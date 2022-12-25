// memory.c - the gameboy memory (map) 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#include "defs.h"
#include "hw_regs.h"
#define ROM_TITLE_ADDR 0x0134
#define MBC_TYPE_ADDR 0x0147
#define NUM_ROM_BANKS_ADDR 0x0148
#define NUM_RAM_BANKS_ADDR 0x0149

#define ROM_BANK_SIZE_IN_BYTES 16384
#define RAM_BANK_SIZE_IN_BYTES  8192

#define IS_PROHIBITED_ADDR(A) ((((A) >= 0xE000) && ((A) <= 0xFDFF)) || (((A) >= 0xFEA0) && ((A) <= 0xFEFF)))

/*

   The Gameboy DMG Memory Map:

0000 - 3FFF : 16 KiB ROM bank 00

4000 - 7FFF : 16 KiB ROM Bank 01~NN, switchable bank via MBC (if any)

8000 - 9FFF : 8 KiB Video RAM (VRAM)

A000 - BFFF : 8 KiB External RAM, switchable bank if any

C000 - DFFF : 8 KiB Work RAM (WRAM)	

E000 - FDFF : ### PROHIBITED AREA ####

FE00 - FE9F : Sprite attribute table (OAM)	

FEA0 - FEFF : ### PROHIBITED AREA ####

FF00 - FF7F : I/O Registers	

FF80 - FFFE : High RAM (HRAM)	

FFFF - FFFF : Interrupt Enable register (IE)	



*/
typedef enum{
    NO_MBC = 0,
    MBC1,
    MBC3,
}mbc;

char rom_title[17];
static mbc mbc_type;
static int num_rom_banks = 0;
static int num_ram_banks = 0;
static Byte memory_map[0x10000];


static Byte *rom_banks[512];
static Byte *ram_banks[16];
int curr_rom_bank = 1;
int curr_ram_bank = 0;


void extractSpecs(FILE *rom_file)
{
    assert(rom_file != NULL);

    // extract ROM title
    fseek(rom_file, ROM_TITLE_ADDR, SEEK_SET);

    fread(rom_title, 16, 1, rom_file);
    rom_title[16] = '\0';



    // extract MBC type
    fseek(rom_file, MBC_TYPE_ADDR, SEEK_SET);
    Byte mbc_check = fgetc(rom_file);

    switch(mbc_check)
    {
        case 0x00:
        case 0x08:
        case 0x09:
            mbc_type = NO_MBC;
            break;

        case 0x01:
        case 0x02:
        case 0x03:
            mbc_type = MBC1;
            break;

        case 0x0F:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            mbc_type = MBC3;
            break;

        default:
            fprintf(stderr, "Error in %s: Could not identify MBC type or MBC type is not supported\n", __func__);
            exit(EXIT_FAILURE);
            break;

    }

    // extract the number of rom banks 
    fseek(rom_file, NUM_ROM_BANKS_ADDR, SEEK_SET);
    Byte rom_bank_check = fgetc(rom_file);

    switch(rom_bank_check)
    {
        case 0x00:
            num_rom_banks = 2;
            break;

        case 0x01:
            num_rom_banks = 4;
            break;

        case 0x02:
            num_rom_banks = 8;
            break;

        case 0x03:
            num_rom_banks = 16;
            break;

        case 0x04:
            num_rom_banks = 32;
            break;

        case 0x05:
            num_rom_banks = 64;
            break;

        case 0x06:
            num_rom_banks = 128;
            break;

        case 0x07:
            num_rom_banks = 256;
            break;

        case 0x08:
            num_rom_banks = 512;
            break;

        default:
            fprintf(stderr, "Error in %s: Could not determine the number of rom banks needed\n", __func__);
            exit(EXIT_FAILURE);
            break;

    }

    // extract the number of ram banks 
    fseek(rom_file, NUM_RAM_BANKS_ADDR, SEEK_SET);
    Byte ram_bank_check = fgetc(rom_file);

    switch(ram_bank_check)
    {
        case 0x00:
            num_ram_banks = 0;
            break;

        case 0x02:
            num_ram_banks = 1;
            break;

        case 0x03:
            num_ram_banks = 4;
            break;

        case 0x04:
            num_ram_banks = 16;
            break;

        case 0x05:
            num_ram_banks = 8;
            break;
        default:
            fprintf(stderr, "Error in %s: Could not determine the number of ram banks needed\n", __func__);
            exit(EXIT_FAILURE);
            break;

    }

}


void createRomBanks(void){
    for(int i = 0; i < num_rom_banks; i++)
    {
        if((rom_banks[i] = malloc(sizeof(Byte) * ROM_BANK_SIZE_IN_BYTES)) == NULL)
        {
            fprintf(stderr, "Error in %s: Could not allocate memory for a ROM bank\n", __func__);
            exit(EXIT_FAILURE);
        }

    }
}

void fillRomBanks(FILE *rom_file){
    rewind(rom_file);
    for(int i = 0; i < num_rom_banks; i++)
        fread(rom_banks[i], ROM_BANK_SIZE_IN_BYTES, 1, rom_file);
}

void createRamBanks(void){
    for(int i = 0; i < num_ram_banks; i++)
    {
        if((ram_banks[i] = malloc(sizeof(Byte) * RAM_BANK_SIZE_IN_BYTES)) == NULL)
        {
            fprintf(stderr, "Error in %s: Could not allocate memory for a RAM bank\n", __func__);
            exit(EXIT_FAILURE);
        }
    }
}

void initMemoryMap(void){
    // Fill memory map with ROM bank 0 - from 0x0000 until 0x3FFFF
    for(int i = 0; i < ROM_BANK_SIZE_IN_BYTES; i++)
        memory_map[i] = rom_banks[0][i];

    // Fill memory map with ROM bank 1 - from 0x4000 until 0x7FFFF
    for(int i = 0; i < ROM_BANK_SIZE_IN_BYTES; i++)
        memory_map[0x4000 + i] = rom_banks[1][i];

    // Initialize hardware registers
    memory_map[HWR_P1] = 0xCF;
    memory_map[HWR_SB] = 0x00;
    memory_map[HWR_SC] = 0x7E;
    memory_map[HWR_DIV] = 0xAB;
    memory_map[HWR_TIMA] = 0x00;
    memory_map[HWR_TMA] = 0x00;
    memory_map[HWR_TAC] = 0xF8;
    memory_map[HWR_IF] = 0xE1;
    memory_map[HWR_NR10] = 0x80;
    memory_map[HWR_NR11] = 0xBF;
    memory_map[HWR_NR12] = 0xF3;
    memory_map[HWR_NR13] = 0xFF;
    memory_map[HWR_NR14] = 0xBF;
    memory_map[HWR_NR21] = 0x3F;
    memory_map[HWR_NR22] = 0x00;
    memory_map[HWR_NR23] = 0xFF;
    memory_map[HWR_NR24] = 0xBF;
    memory_map[HWR_NR30] = 0x7F;
    memory_map[HWR_NR31] = 0xFF;
    memory_map[HWR_NR32] = 0x9F;
    memory_map[HWR_NR33] = 0xFF;
    memory_map[HWR_NR34] = 0xBF;
    memory_map[HWR_NR41] = 0xFF;
    memory_map[HWR_NR42] = 0x00;
    memory_map[HWR_NR43] = 0x00;
    memory_map[HWR_NR44] = 0xBF;
    memory_map[HWR_NR50] = 0x77;
    memory_map[HWR_NR51] = 0xF3;
    memory_map[HWR_NR52] = 0xF1;
    memory_map[HWR_LCDC] = 0x91;
    memory_map[HWR_STAT] = 0x85;
    memory_map[HWR_SCY] = 0x00;
    memory_map[HWR_SCX] = 0x00;
    memory_map[HWR_LY] = 0x00;
    memory_map[HWR_LYC] = 0x00;
    memory_map[HWR_DMA] = 0xFF;
    memory_map[HWR_BGP] = 0xFC;
    memory_map[HWR_OBP0] = 0x00;
    memory_map[HWR_OBP1] = 0x00;
    memory_map[HWR_WY] = 0x00;
    memory_map[HWR_WX] = 0x00;
    memory_map[HWR_KEY1] = 0xFF;
    memory_map[HWR_VBK] = 0xFF;
    memory_map[HWR_HDMA1] = 0xFF;
    memory_map[HWR_HDMA2] = 0xFF;
    memory_map[HWR_HDMA3] = 0xFF;
    memory_map[HWR_HDMA4] = 0xFF;
    memory_map[HWR_HDMA5] = 0xFF;
    memory_map[HWR_RP] = 0xFF;
    memory_map[HWR_BCPS] = 0xFF;
    memory_map[HWR_BCPD] = 0xFF;
    memory_map[HWR_OCPS] = 0xFF;
    memory_map[HWR_OCPD] = 0xFF;
    memory_map[HWR_SVBK] = 0xFF;
    memory_map[HWR_IE] = 0x00;

}

void initMemory(FILE *rom_file){
    extractSpecs(rom_file);
    createRomBanks();
    fillRomBanks(rom_file);
    createRamBanks();
    initMemoryMap();
}

void switchRomBank(int bnum){
    assert(bnum > 0 && bnum < num_rom_banks);
    for(long i = 0; i < ROM_BANK_SIZE_IN_BYTES; i++)
        memory_map[0x4000 + i] = rom_banks[bnum][i];
}

void switchRamBank(int bnum){
    assert(bnum > 0 && bnum < num_ram_banks);

    // First save the state of the current ram bank 
    for(long i = 0; i < RAM_BANK_SIZE_IN_BYTES; i++)
        rom_banks[curr_ram_bank][i] = memory_map[0xA000 + i];

    // Then copy the contents of the chosen ram bank into memory map
    for(long i = 0; i < RAM_BANK_SIZE_IN_BYTES; i++)
         memory_map[0xA000 + i] = rom_banks[bnum][i] ;

}


Byte getMemory(Word addr){
    // Make sure that there isn't an attempt to read from external ram when
    // there is no external ram present
    assert(!(num_ram_banks == 0 && (addr >= 0xA000 && addr <= 0xBFFF)));

    // Make sure that the program not trying to read from prohibited 
    // areas in memory map 
    assert(!(IS_PROHIBITED_ADDR(addr)));

    return memory_map[addr];
}


void controlMBC1(Word addr, Byte val){
    //TODO
}

void controlMBC3(Word addr, Byte val){
    //TODO
}

void setMemory(Word addr, Byte val){
    // Make sure that there isn't an attempt to write to external ram when
    // there is no external ram present
    assert(!(num_ram_banks == 0 && (addr >= 0xA000 && addr <= 0xBFFF)));

    // Make sure that the program not trying to write to prohibited 
    // areas in memory map 
    assert(!(IS_PROHIBITED_ADDR(addr)));

    // Make sure that if there's no MBC then there should be no attempt 
    // to write into the ROM area
    assert(!((mbc_type == NO_MBC) && (addr >= 0x0000 && addr <= 0x7FFF)));
    

    if(addr >= 0x0000 && addr <= 0x7FFF)
    {
        if(mbc_type == MBC1)
            controlMBC1(addr, val);
        else
            controlMBC3(addr, val);
    }

    memory_map[addr] = val;
}



