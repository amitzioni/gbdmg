// registers.c - CPU Registers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "defs.h"
#include "operands.h"
#include "registers.h"


// array of the 8-bit registers initialized to the startup sequence values
static Byte byte_registers[] = {
    [REG_A] = 0x01 ,
    //TODO initial value of REG_F (i.e. CPU flags) is dependet on the ROM checksum
    [REG_F] = 0x80,
    [REG_B] = 0x00,
    [REG_C] = 0x13,
    [REG_D] = 0x00,
    [REG_E] = 0xD8,
    [REG_H] = 0x01,
    [REG_L] = 0x4D,
};

// the program counter and the stack pointer 16-bit registers initial values
static Word reg_pc = 0x0100;
static Word reg_sp = 0xFFFE; 







Byte getByteRegister(operand op){
    assert(op >= REG_A && op <= REG_L);

    return byte_registers[op];
}

Word getWordRegister(operand op){
    assert(op >= REG_SP && op <= REG_HL);

    if(op == REG_PC)
        return reg_pc;
    if(op == REG_SP)
        return reg_sp;

    Word to_return = byte_registers[op - REG_AF];
    to_return <<= 8;
    to_return |= byte_registers[(op - REG_AF) + 1];

    return to_return;
}

bool getFlag(flag fl){
    assert(fl >= FLAG_C && fl <= FLAG_Z);

    Byte reg_f = byte_registers[REG_F];
    return (((1UL << fl) & reg_f) ? true : false);
}



void setByteRegister(operand op, Byte val){
    assert(op >= REG_A && op <= REG_L);

    byte_registers[op] = val;

}

void setWordRegister(operand op, Word val){
    assert(op >= REG_SP && op <= REG_HL);

    if(op == REG_PC)
        reg_pc = val;
    else if(op == REG_SP)
        reg_sp = val;
    else
    {
        byte_registers[op - REG_AF] = (val >> 8) & 0xFF;
        byte_registers[(op - REG_AF) + 1] = val & 0xFF;
    }

}

void setFlag(flag fl, bool val){
    Byte reg_f = byte_registers[REG_F];

    if(val == true)
        reg_f |= (1UL << fl);
    else
        reg_f &= ~(1UL << fl);

    byte_registers[REG_F] = reg_f;
}











