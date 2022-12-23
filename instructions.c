#include "operands.h"
#include "instructions.h"

// Normal Instructions         
const instruction normal_inst[0x100] = {
   [0x0A] = { LD, REG_A, MEM_REG_BC }, // | 1--8 | - - - -
   [0x1A] = { LD, REG_A, MEM_REG_DE }, // | 1--8 | - - - -
   [0x2A] = { LD, REG_A, MEM_REG_HL_PLUS }, // | 1--8 | - - - -
   [0x3A] = { LD, REG_A, MEM_REG_HL_MINUS }, // | 1--8 | - - - -
   [0x3E] = { LD, REG_A, IMM8 }, // | 2--8 | - - - -
   [0x01] = { LD, REG_BC, IMM16 }, // | 3--12 | - - - -
   [0x11] = { LD, REG_DE, IMM16 }, // | 3--12 | - - - -
   [0x21] = { LD, REG_HL, IMM16 }, // | 3--12 | - - - -
   [0x31] = { LD, REG_SP, IMM16 }, // | 3--12 | - - - -
   [0x06] = { LD, REG_B, IMM8 }, // | 2--8 | - - - -
   [0x0E] = { LD, REG_C, IMM8 }, // | 2--8 | - - - -
   [0x16] = { LD, REG_D, IMM8 }, // | 2--8 | - - - -
   [0x1E] = { LD, REG_E, IMM8 }, // | 2--8 | - - - -
   [0x26] = { LD, REG_H, IMM8 }, // | 2--8 | - - - -
   [0x2E] = { LD, REG_L, IMM8 }, // | 2--8 | - - - -
   [0x36] = { LD, MEM_REG_HL, IMM8 }, // | 2--12 | - - - -
   [0x40] = { LD, REG_B, REG_B }, // | 1--4 | - - - -
   [0x41] = { LD, REG_B, REG_C }, // | 1--4 | - - - -
   [0x42] = { LD, REG_B, REG_D }, // | 1--4 | - - - -
   [0x43] = { LD, REG_B, REG_E }, // | 1--4 | - - - -
   [0x44] = { LD, REG_B, REG_H }, // | 1--4 | - - - -
   [0x45] = { LD, REG_B, REG_L }, // | 1--4 | - - - -
   [0x47] = { LD, REG_B, REG_A }, // | 1--4 | - - - -
   [0x48] = { LD, REG_C, REG_B }, // | 1--4 | - - - -
   [0x49] = { LD, REG_C, REG_C }, // | 1--4 | - - - -
   [0x4A] = { LD, REG_C, REG_D }, // | 1--4 | - - - -
   [0x4B] = { LD, REG_C, REG_E }, // | 1--4 | - - - -
   [0x4C] = { LD, REG_C, REG_H }, // | 1--4 | - - - -
   [0x4D] = { LD, REG_C, REG_L }, // | 1--4 | - - - -
   [0x4F] = { LD, REG_C, REG_A }, // | 1--4 | - - - -
   [0x50] = { LD, REG_D, REG_B }, // | 1--4 | - - - -
   [0x51] = { LD, REG_D, REG_C }, // | 1--4 | - - - -
   [0x52] = { LD, REG_D, REG_D }, // | 1--4 | - - - -
   [0x53] = { LD, REG_D, REG_E }, // | 1--4 | - - - -
   [0x54] = { LD, REG_D, REG_H }, // | 1--4 | - - - -
   [0x55] = { LD, REG_D, REG_L }, // | 1--4 | - - - -
   [0x57] = { LD, REG_D, REG_A }, // | 1--4 | - - - -
   [0x58] = { LD, REG_E, REG_B }, // | 1--4 | - - - -
   [0x59] = { LD, REG_E, REG_C }, // | 1--4 | - - - -
   [0x5A] = { LD, REG_E, REG_D }, // | 1--4 | - - - -
   [0x5B] = { LD, REG_E, REG_E }, // | 1--4 | - - - -
   [0x5C] = { LD, REG_E, REG_H }, // | 1--4 | - - - -
   [0x5D] = { LD, REG_E, REG_L }, // | 1--4 | - - - -
   [0x5F] = { LD, REG_E, REG_A }, // | 1--4 | - - - -
   [0x60] = { LD, REG_H, REG_B }, // | 1--4 | - - - -
   [0x61] = { LD, REG_H, REG_C }, // | 1--4 | - - - -
   [0x62] = { LD, REG_H, REG_D }, // | 1--4 | - - - -
   [0x63] = { LD, REG_H, REG_E }, // | 1--4 | - - - -
   [0x64] = { LD, REG_H, REG_H }, // | 1--4 | - - - -
   [0x65] = { LD, REG_H, REG_L }, // | 1--4 | - - - -
   [0x67] = { LD, REG_H, REG_A }, // | 1--4 | - - - -
   [0x68] = { LD, REG_L, REG_B }, // | 1--4 | - - - -
   [0x69] = { LD, REG_L, REG_C }, // | 1--4 | - - - -
   [0x6A] = { LD, REG_L, REG_D }, // | 1--4 | - - - -
   [0x6B] = { LD, REG_L, REG_E }, // | 1--4 | - - - -
   [0x6C] = { LD, REG_L, REG_H }, // | 1--4 | - - - -
   [0x6D] = { LD, REG_L, REG_L }, // | 1--4 | - - - -
   [0x6F] = { LD, REG_L, REG_A }, // | 1--4 | - - - -
   [0x78] = { LD, REG_A, REG_B }, // | 1--4 | - - - -
   [0x79] = { LD, REG_A, REG_C }, // | 1--4 | - - - -
   [0x7A] = { LD, REG_A, REG_D }, // | 1--4 | - - - -
   [0x7B] = { LD, REG_A, REG_E }, // | 1--4 | - - - -
   [0x7C] = { LD, REG_A, REG_H }, // | 1--4 | - - - -
   [0x7D] = { LD, REG_A, REG_L }, // | 1--4 | - - - -
   [0x7F] = { LD, REG_A, REG_A }, // | 1--4 | - - - -
   [0x46] = { LD, REG_B, MEM_REG_HL }, // | 1--8 | - - - -
   [0x4E] = { LD, REG_C, MEM_REG_HL }, // | 1--8 | - - - -
   [0x56] = { LD, REG_D, MEM_REG_HL }, // | 1--8 | - - - -
   [0x5E] = { LD, REG_E, MEM_REG_HL }, // | 1--8 | - - - -
   [0x66] = { LD, REG_H, MEM_REG_HL }, // | 1--8 | - - - -
   [0x6E] = { LD, REG_L, MEM_REG_HL }, // | 1--8 | - - - -
   [0x7E] = { LD, REG_A, MEM_REG_HL }, // | 1--8 | - - - -
   [0x70] = { LD, MEM_REG_HL, REG_B }, // | 1--8 | - - - -
   [0x71] = { LD, MEM_REG_HL, REG_C }, // | 1--8 | - - - -
   [0x72] = { LD, MEM_REG_HL, REG_D }, // | 1--8 | - - - -
   [0x73] = { LD, MEM_REG_HL, REG_E }, // | 1--8 | - - - -
   [0x74] = { LD, MEM_REG_HL, REG_H }, // | 1--8 | - - - -
   [0x75] = { LD, MEM_REG_HL, REG_L }, // | 1--8 | - - - -
   [0x77] = { LD, MEM_REG_HL, REG_A }, // | 1--8 | - - - -

   [0xE0] = { LD, MEM_IMM8, REG_A }, // | 2--12 | - - - -
   [0xF0] = { LD, REG_A, MEM_IMM8 }, // | 2--12 | - - - -
   [0xE2] = { LD, MEM_REG_C, REG_A }, // | 2--8 | - - - -
   [0xF2] = { LD, REG_A, MEM_REG_C }, // | 2--8 | - - - -
   [0xF8] = { LD, REG_HL, REG_SP_PLUS_SIMM8}, // | 2--12 | 0 0 H C
   [0xF9] = { LD, REG_SP, REG_HL }, // | 1--8 | - - - -
   [0x02] = { LD, MEM_REG_BC, REG_A }, // | 1--8 | - - - -
   [0x12] = { LD, MEM_REG_DE, REG_A }, // | 1--8 | - - - -
   [0x22] = { LD, MEM_REG_HL_PLUS, REG_A }, // | 1--8 | - - - -
   [0x32] = { LD, MEM_REG_HL_MINUS, REG_A }, // | 1--8 | - - - -
   [0xFA] = { LD, REG_A, MEM_IMM16 }, // | 3--16 | - - - -
   [0x08] = { LD, MEM_IMM16, REG_SP }, // | 3--20 | - - - -
   [0xEA] = { LD, MEM_IMM16, REG_A }, // | 3--16 | - - - -


   [0x04] = { INC, REG_B , EMPTY }, // | 1--4 | Z 0 H -
   [0x0C] = { INC, REG_C , EMPTY }, // | 1--4 | Z 0 H -
   [0x14] = { INC, REG_D , EMPTY }, // | 1--4 | Z 0 H -
   [0x1C] = { INC, REG_E , EMPTY }, // | 1--4 | Z 0 H -
   [0x24] = { INC, REG_H , EMPTY }, // | 1--4 | Z 0 H -
   [0x2C] = { INC, REG_L , EMPTY }, // | 1--4 | Z 0 H -
   [0x3C] = { INC, REG_A , EMPTY }, // | 1--4 | Z 0 H -
   [0x34] = { INC, MEM_REG_HL, EMPTY }, // | 1--12 | Z 0 H -
   [0x03] = { INC, REG_BC, EMPTY }, // | 1--8 | - - - -
   [0x13] = { INC, REG_DE, EMPTY }, // | 1--8 | - - - -
   [0x23] = { INC, REG_HL, EMPTY }, // | 1--8 | - - - -
   [0x33] = { INC, REG_SP, EMPTY }, // | 1--8 | - - - -


   [0x05] = { DEC, REG_B  , EMPTY }, // | 1--4 | Z 1 H -
   [0x0D] = { DEC, REG_C  , EMPTY }, // | 1--4 | Z 1 H -
   [0x15] = { DEC, REG_D  , EMPTY }, // | 1--4 | Z 1 H -
   [0x1D] = { DEC, REG_E  , EMPTY }, // | 1--4 | Z 1 H -
   [0x25] = { DEC, REG_H  , EMPTY }, // | 1--4 | Z 1 H -
   [0x2D] = { DEC, REG_L  , EMPTY }, // | 1--4 | Z 1 H -
   [0x3D] = { DEC, REG_A  , EMPTY }, // | 1--4 | Z 1 H -
   [0x35] = { DEC, MEM_REG_HL, EMPTY }, // | 1--12 | Z 1 H -
   [0x0B] = { DEC, REG_BC , EMPTY }, // | 1--8 | - - - -
   [0x1B] = { DEC, REG_DE , EMPTY }, // | 1--8 | - - - -
   [0x2B] = { DEC, REG_HL , EMPTY }, // | 1--8 | - - - -
   [0x3B] = { DEC, REG_SP , EMPTY }, // | 1--8 | - - - -



   [0x09] = { ADD, REG_HL, REG_BC }, // | 1--8 | - 0 H C
   [0x19] = { ADD, REG_HL, REG_DE }, // | 1--8 | - 0 H C
   [0x29] = { ADD, REG_HL, REG_HL }, // | 1--8 | - 0 H C
   [0x39] = { ADD, REG_HL, REG_SP }, // | 1--8 | - 0 H C
   [0x80] = { ADD, REG_A, REG_B }, // | 1--4 | Z 0 H C
   [0x81] = { ADD, REG_A, REG_C }, // | 1--4 | Z 0 H C
   [0x82] = { ADD, REG_A, REG_D }, // | 1--4 | Z 0 H C
   [0x83] = { ADD, REG_A, REG_E }, // | 1--4 | Z 0 H C
   [0x84] = { ADD, REG_A, REG_H }, // | 1--4 | Z 0 H C
   [0x85] = { ADD, REG_A, REG_L }, // | 1--4 | Z 0 H C
   [0x87] = { ADD, REG_A, REG_A }, // | 1--4 | Z 0 H C
   [0xC6] = { ADD, REG_A, IMM8 }, // | 2--8 | Z 0 H C
   [0xE8] = { ADD, REG_SP, SIMM8 }, // | 2--16 | 0 0 H C
   [0x86] = { ADD, REG_A, MEM_REG_HL}, // | 1--8 | Z 0 H C


   [0x88] = { ADC, REG_A, REG_B }, // | 1--4 | Z 0 H C
   [0x89] = { ADC, REG_A, REG_C }, // | 1--4 | Z 0 H C
   [0x8A] = { ADC, REG_A, REG_D }, // | 1--4 | Z 0 H C
   [0x8B] = { ADC, REG_A, REG_E }, // | 1--4 | Z 0 H C
   [0x8C] = { ADC, REG_A, REG_H }, // | 1--4 | Z 0 H C
   [0x8D] = { ADC, REG_A, REG_L }, // | 1--4 | Z 0 H C
   [0x8F] = { ADC, REG_A, REG_A }, // | 1--4 | Z 0 H C
   [0xCE] = { ADC, REG_A, IMM8 }, // | 2--8 | Z 0 H C
   [0x8E] = { ADC, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 H C


   [0x90] = { SUB, REG_A, REG_B }, // | 1--4 | Z 1 H C
   [0x91] = { SUB, REG_A, REG_C }, // | 1--4 | Z 1 H C
   [0x92] = { SUB, REG_A, REG_D }, // | 1--4 | Z 1 H C
   [0x93] = { SUB, REG_A, REG_E }, // | 1--4 | Z 1 H C
   [0x94] = { SUB, REG_A, REG_H }, // | 1--4 | Z 1 H C
   [0x95] = { SUB, REG_A, REG_L }, // | 1--4 | Z 1 H C
   [0x97] = { SUB, REG_A, REG_A }, // | 1--4 | Z 1 H C
   [0xD6] = { SUB, REG_A, IMM8 }, // | 2--8 | Z 1 H C
   [0x96] = { SUB, REG_A, MEM_REG_HL }, // | 1--8 | Z 1 H C


   [0x98] = { SBC, REG_A, REG_B }, // | 1--4 | Z 1 H C
   [0x99] = { SBC, REG_A, REG_C }, // | 1--4 | Z 1 H C
   [0x9A] = { SBC, REG_A, REG_D }, // | 1--4 | Z 1 H C
   [0x9B] = { SBC, REG_A, REG_E }, // | 1--4 | Z 1 H C
   [0x9C] = { SBC, REG_A, REG_H }, // | 1--4 | Z 1 H C
   [0x9D] = { SBC, REG_A, REG_L }, // | 1--4 | Z 1 H C
   [0x9F] = { SBC, REG_A, REG_A }, // | 1--4 | Z 1 H C
   [0xDE] = { SBC, REG_A, IMM8 }, // | 2--8 | Z 1 H C
   [0x9E] = { SBC, REG_A, MEM_REG_HL }, // | 1--8 | Z 1 H C


   [0xA8] = { XOR, REG_A, REG_B }, // | 1--4 | Z 0 0 0
   [0xA9] = { XOR, REG_A, REG_C }, // | 1--4 | Z 0 0 0
   [0xAA] = { XOR, REG_A, REG_D }, // | 1--4 | Z 0 0 0
   [0xAB] = { XOR, REG_A, REG_E }, // | 1--4 | Z 0 0 0
   [0xAC] = { XOR, REG_A, REG_H }, // | 1--4 | Z 0 0 0
   [0xAD] = { XOR, REG_A, REG_L }, // | 1--4 | Z 0 0 0
   [0xAF] = { XOR, REG_A, REG_A }, // | 1--4 | Z 0 0 0
   [0xEE] = { XOR, REG_A, IMM8 }, // | 2--8 | Z 0 0 0
   [0xAE] = { XOR, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 0 0


   [0xA0] = { AND, REG_A, REG_B }, // | 1--4 | Z 0 1 0
   [0xA1] = { AND, REG_A, REG_C }, // | 1--4 | Z 0 1 0
   [0xA2] = { AND, REG_A, REG_D }, // | 1--4 | Z 0 1 0
   [0xA3] = { AND, REG_A, REG_E }, // | 1--4 | Z 0 1 0
   [0xA4] = { AND, REG_A, REG_H }, // | 1--4 | Z 0 1 0
   [0xA5] = { AND, REG_A, REG_L }, // | 1--4 | Z 0 1 0
   [0xA7] = { AND, REG_A, REG_A }, // | 1--4 | Z 0 1 0
   [0xE6] = { AND, REG_A, IMM8 }, // | 2--8 | Z 0 1 0
   [0xA6] = { AND, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 1 0


   [0xB0] = { OR, REG_A, REG_B }, // | 1--4 | Z 0 0 0
   [0xB1] = { OR, REG_A, REG_C }, // | 1--4 | Z 0 0 0
   [0xB2] = { OR, REG_A, REG_D }, // | 1--4 | Z 0 0 0
   [0xB3] = { OR, REG_A, REG_E }, // | 1--4 | Z 0 0 0
   [0xB4] = { OR, REG_A, REG_H }, // | 1--4 | Z 0 0 0
   [0xB5] = { OR, REG_A, REG_L }, // | 1--4 | Z 0 0 0
   [0xB7] = { OR, REG_A, REG_A }, // | 1--4 | Z 0 0 0
   [0xF6] = { OR, REG_A, IMM8 }, // | 2--8 | Z 0 0 0
   [0xB6] = { OR, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 0 0



   [0xB8] = { CP, REG_A, REG_B }, // | 1--4 | Z 1 H C
   [0xB9] = { CP, REG_A, REG_C }, // | 1--4 | Z 1 H C
   [0xBA] = { CP, REG_A, REG_D }, // | 1--4 | Z 1 H C
   [0xBB] = { CP, REG_A, REG_E }, // | 1--4 | Z 1 H C
   [0xBC] = { CP, REG_A, REG_H }, // | 1--4 | Z 1 H C
   [0xBD] = { CP, REG_A, REG_L }, // | 1--4 | Z 1 H C
   [0xBF] = { CP, REG_A, REG_A }, // | 1--4 | Z 1 H C
   [0xFE] = { CP, REG_A, IMM8 }, // | 2--8 | Z 1 H C
   [0xBE] = { CP, REG_A, MEM_REG_HL }, // | 1--8 | Z 1 H C


   [0xE9] = { JP, MEM_REG_HL, EMPTY }, // | 1--4 | - - - -
   [0xC3] = { JP, IMM16, EMPTY }, // | 3--16 | - - - -
   [0xC2] = { JP, CON_NZ,IMM16 }, // | 3--16/12 | - - - -
   [0xCA] = { JP, CON_Z,IMM16 }, // | 3--16/12 | - - - -
   [0xD2] = { JP, CON_NC,IMM16 }, // | 3--16/12 | - - - -
   [0xDA] = { JP, CON_C,IMM16 }, // | 3--16/12 | - - - -


   [0x18] = { JR, SIMM8, EMPTY }, // | 2--12 | - - - -
   [0x38] = { JR, CON_C, SIMM8 }, // | 2--12/8 | - - - -
   [0x20] = { JR, CON_NZ, SIMM8 }, // | 2--12/8 | - - - -
   [0x28] = { JR, CON_Z, SIMM8 }, // | 2--12/8 | - - - -
   [0x30] = { JR, CON_NC, SIMM8 }, // | 2--12/8 | - - - -



   [0xC5] = { PUSH, REG_BC, EMPTY }, // | 1--16 | - - - -
   [0xD5] = { PUSH, REG_DE, EMPTY }, // | 1--16 | - - - -
   [0xE5] = { PUSH, REG_HL, EMPTY }, // | 1--16 | - - - -
   [0xF5] = { PUSH, REG_AF, EMPTY }, // | 1--16 | - - - -


   [0xC1] = { POP, REG_BC, EMPTY }, // | 1--12 | - - - -
   [0xD1] = { POP, REG_DE, EMPTY }, // | 1--12 | - - - -
   [0xE1] = { POP, REG_HL, EMPTY }, // | 1--12 | - - - -
   [0xF1] = { POP, REG_AF, EMPTY }, // | 1--12 | Z N H C


   [0xCD] = { CALL, IMM16, EMPTY }, // | 3--24 | - - - -
   [0xC4] = { CALL, CON_NZ,IMM16 }, // | 3--24/12 | - - - -
   [0xCC] = { CALL, CON_Z,IMM16 }, // | 3--24/12 | - - - -
   [0xD4] = { CALL, CON_NC,IMM16 }, // | 3--24/12 | - - - -
   [0xDC] = { CALL, CON_C,IMM16 }, // | 3--24/12 | - - - -



   [0xC0] = { RET, CON_NZ, EMPTY }, // | 1--20/8 | - - - -
   [0xC8] = { RET, CON_Z , EMPTY }, // | 1--20/8 | - - - -
   [0xD0] = { RET, CON_NC, EMPTY }, // | 1--20/8 | - - - -
   [0xD8] = { RET, CON_C , EMPTY }, // | 1--20/8 | - - - -
   [0xC9] = { RET, EMPTY, EMPTY }, // | 1--16 | - - - -
   [0xD9] = { RETI, EMPTY, EMPTY }, // | 1--16 | - - - -


   [0xC7] = { RST, 0x00, EMPTY}, // | 1--16 | - - - -
   [0xCF] = { RST, 0x08, EMPTY}, // | 1--16 | - - - -
   [0xD7] = { RST, 0x10, EMPTY}, // | 1--16 | - - - -
   [0xDF] = { RST, 0x18, EMPTY}, // | 1--16 | - - - -
   [0xE7] = { RST, 0x20, EMPTY}, // | 1--16 | - - - -
   [0xEF] = { RST, 0x28, EMPTY}, // | 1--16 | - - - -
   [0xF7] = { RST, 0x30, EMPTY}, // | 1--16 | - - - -
   [0xFF] = { RST, 0x38, EMPTY}, // | 1--16 | - - - -


   
   [0x27] = { DAA, EMPTY, EMPTY }, // | 1--4 | Z - 0 C

   [0x2F] = { CPL, EMPTY, EMPTY }, // | 1--4 | - 1 1 -
   [0x37] = { SCF, EMPTY, EMPTY }, // | 1--4 | - 0 0 1
   [0x3F] = { CCF, EMPTY, EMPTY }, // | 1--4 | - 0 0 C
   
   
   [0xF3] = { DI, EMPTY, EMPTY }, // | 1--4 | - - - -
   [0xFB] = { EI, EMPTY, EMPTY }, // | 1--4 | - - - -
   
   [0x00] = { NOP, EMPTY, EMPTY }, // | 1--4 | - - - -
   [0x10] = { STOP, EMPTY, EMPTY }, // | 2--4 | - - - -
   [0x76] = { HALT, EMPTY, EMPTY }, // | 1--4 | - - - -
   
   
   [0x17] = { RLA, EMPTY, EMPTY }, // | 1--4 | 0 0 0 C
   [0x1F] = { RRA, EMPTY, EMPTY }, // | 1--4 | 0 0 0 C
   [0x07] = { RLCA, EMPTY, EMPTY}, // | 1--4 | 0 0 0 C
   [0x0F] = { RRCA, EMPTY, EMPTY}, // | 1--4 | 0 0 0 C
};
   
         
// CB Instructions         
const instruction cb_inst[0x100] = {
   [0x00] = { RLC, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x01] = { RLC, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x02] = { RLC, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x03] = { RLC, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x04] = { RLC, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x05] = { RLC, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x07] = { RLC, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x06] = { RLC, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C


   [0x08] = { RRC, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x09] = { RRC, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0A] = { RRC, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0B] = { RRC, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0C] = { RRC, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0D] = { RRC, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0F] = { RRC, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0E] = { RRC, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C
   
   
   [0x10] = { RL, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x11] = { RL, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x12] = { RL, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x13] = { RL, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x14] = { RL, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x15] = { RL, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x17] = { RL, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x16] = { RL, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C

   [0x18] = { RR, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x19] = { RR, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1A] = { RR, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1B] = { RR, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1C] = { RR, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1D] = { RR, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1F] = { RR, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1E] = { RR, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C
   
   
   [0x20] = { SLA, REG_B, EMPTY}, // | 2--8 | Z 0 0 C
   [0x21] = { SLA, REG_C, EMPTY}, // | 2--8 | Z 0 0 C
   [0x22] = { SLA, REG_D, EMPTY}, // | 2--8 | Z 0 0 C
   [0x23] = { SLA, REG_E, EMPTY}, // | 2--8 | Z 0 0 C
   [0x24] = { SLA, REG_H, EMPTY}, // | 2--8 | Z 0 0 C
   [0x25] = { SLA, REG_L, EMPTY}, // | 2--8 | Z 0 0 C
   [0x27] = { SLA, REG_A, EMPTY}, // | 2--8 | Z 0 0 C
   [0x26] = { SLA, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C

   [0x28] = { SRA, REG_B, EMPTY}, // | 2--8 | Z 0 0 0
   [0x29] = { SRA, REG_C, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2A] = { SRA, REG_D, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2B] = { SRA, REG_E, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2C] = { SRA, REG_H, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2D] = { SRA, REG_L, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2F] = { SRA, REG_A, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2E] = { SRA, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 0
   
   
   [0x38] = { SRL, REG_B, EMPTY}, // | 2--8 | Z 0 0 C
   [0x39] = { SRL, REG_C, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3A] = { SRL, REG_D, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3B] = { SRL, REG_E, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3C] = { SRL, REG_H, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3D] = { SRL, REG_L, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3F] = { SRL, REG_A, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3E] = { SRL, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C




   [0x30] = { SWAP, REG_B, EMPTY }, // | 2--8 | Z 0 0 0
   [0x31] = { SWAP, REG_C, EMPTY }, // | 2--8 | Z 0 0 0
   [0x32] = { SWAP, REG_D, EMPTY }, // | 2--8 | Z 0 0 0
   [0x33] = { SWAP, REG_E, EMPTY }, // | 2--8 | Z 0 0 0
   [0x34] = { SWAP, REG_H, EMPTY }, // | 2--8 | Z 0 0 0
   [0x35] = { SWAP, REG_L, EMPTY }, // | 2--8 | Z 0 0 0
   [0x37] = { SWAP, REG_A, EMPTY }, // | 2--8 | Z 0 0 0
   [0x36] = { SWAP, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 0




   
   
   [0x40] = { BIT, 0, REG_B }, // | 2--8 | Z 0 1 -
   [0x41] = { BIT, 0, REG_C }, // | 2--8 | Z 0 1 -
   [0x42] = { BIT, 0, REG_D }, // | 2--8 | Z 0 1 -
   [0x43] = { BIT, 0, REG_E }, // | 2--8 | Z 0 1 -
   [0x44] = { BIT, 0, REG_H }, // | 2--8 | Z 0 1 -
   [0x45] = { BIT, 0, REG_L }, // | 2--8 | Z 0 1 -
   [0x47] = { BIT, 0, REG_A }, // | 2--8 | Z 0 1 -
   [0x48] = { BIT, 1, REG_B }, // | 2--8 | Z 0 1 -
   [0x49] = { BIT, 1, REG_C }, // | 2--8 | Z 0 1 -
   [0x4A] = { BIT, 1, REG_D }, // | 2--8 | Z 0 1 -
   [0x4B] = { BIT, 1, REG_E }, // | 2--8 | Z 0 1 -
   [0x4C] = { BIT, 1, REG_H }, // | 2--8 | Z 0 1 -
   [0x4D] = { BIT, 1, REG_L }, // | 2--8 | Z 0 1 -
   [0x4F] = { BIT, 1, REG_A }, // | 2--8 | Z 0 1 -
   [0x50] = { BIT, 2, REG_B }, // | 2--8 | Z 0 1 -
   [0x51] = { BIT, 2, REG_C }, // | 2--8 | Z 0 1 -
   [0x52] = { BIT, 2, REG_D }, // | 2--8 | Z 0 1 -
   [0x53] = { BIT, 2, REG_E }, // | 2--8 | Z 0 1 -
   [0x54] = { BIT, 2, REG_H }, // | 2--8 | Z 0 1 -
   [0x55] = { BIT, 2, REG_L }, // | 2--8 | Z 0 1 -
   [0x57] = { BIT, 2, REG_A }, // | 2--8 | Z 0 1 -
   [0x58] = { BIT, 3, REG_B }, // | 2--8 | Z 0 1 -
   [0x59] = { BIT, 3, REG_C }, // | 2--8 | Z 0 1 -
   [0x5A] = { BIT, 3, REG_D }, // | 2--8 | Z 0 1 -
   [0x5B] = { BIT, 3, REG_E }, // | 2--8 | Z 0 1 -
   [0x5C] = { BIT, 3, REG_H }, // | 2--8 | Z 0 1 -
   [0x5D] = { BIT, 3, REG_L }, // | 2--8 | Z 0 1 -
   [0x5F] = { BIT, 3, REG_A }, // | 2--8 | Z 0 1 -
   [0x60] = { BIT, 4, REG_B }, // | 2--8 | Z 0 1 -
   [0x61] = { BIT, 4, REG_C }, // | 2--8 | Z 0 1 -
   [0x62] = { BIT, 4, REG_D }, // | 2--8 | Z 0 1 -
   [0x63] = { BIT, 4, REG_E }, // | 2--8 | Z 0 1 -
   [0x64] = { BIT, 4, REG_H }, // | 2--8 | Z 0 1 -
   [0x65] = { BIT, 4, REG_L }, // | 2--8 | Z 0 1 -
   [0x67] = { BIT, 4, REG_A }, // | 2--8 | Z 0 1 -
   [0x68] = { BIT, 5, REG_B }, // | 2--8 | Z 0 1 -
   [0x69] = { BIT, 5, REG_C }, // | 2--8 | Z 0 1 -
   [0x6A] = { BIT, 5, REG_D }, // | 2--8 | Z 0 1 -
   [0x6B] = { BIT, 5, REG_E }, // | 2--8 | Z 0 1 -
   [0x6C] = { BIT, 5, REG_H }, // | 2--8 | Z 0 1 -
   [0x6D] = { BIT, 5, REG_L }, // | 2--8 | Z 0 1 -
   [0x6F] = { BIT, 5, REG_A }, // | 2--8 | Z 0 1 -
   [0x70] = { BIT, 6, REG_B }, // | 2--8 | Z 0 1 -
   [0x71] = { BIT, 6, REG_C }, // | 2--8 | Z 0 1 -
   [0x72] = { BIT, 6, REG_D }, // | 2--8 | Z 0 1 -
   [0x73] = { BIT, 6, REG_E }, // | 2--8 | Z 0 1 -
   [0x74] = { BIT, 6, REG_H }, // | 2--8 | Z 0 1 -
   [0x75] = { BIT, 6, REG_L }, // | 2--8 | Z 0 1 -
   [0x77] = { BIT, 6, REG_A }, // | 2--8 | Z 0 1 -
   [0x78] = { BIT, 7, REG_B }, // | 2--8 | Z 0 1 -
   [0x79] = { BIT, 7, REG_C }, // | 2--8 | Z 0 1 -
   [0x7A] = { BIT, 7, REG_D }, // | 2--8 | Z 0 1 -
   [0x7B] = { BIT, 7, REG_E }, // | 2--8 | Z 0 1 -
   [0x7C] = { BIT, 7, REG_H }, // | 2--8 | Z 0 1 -
   [0x7D] = { BIT, 7, REG_L }, // | 2--8 | Z 0 1 -
   [0x7F] = { BIT, 7, REG_A }, // | 2--8 | Z 0 1 -
   [0x46] = { BIT, 0, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x4E] = { BIT, 1, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x56] = { BIT, 2, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x5E] = { BIT, 3, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x66] = { BIT, 4, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x6E] = { BIT, 5, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x76] = { BIT, 6, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x7E] = { BIT, 7, MEM_REG_HL }, // | 2--16 | Z 0 1 -

   

   [0x80] = { RES, 0, REG_B }, // | 2--8 | - - - -
   [0x81] = { RES, 0, REG_C }, // | 2--8 | - - - -
   [0x82] = { RES, 0, REG_D }, // | 2--8 | - - - -
   [0x83] = { RES, 0, REG_E }, // | 2--8 | - - - -
   [0x84] = { RES, 0, REG_H }, // | 2--8 | - - - -
   [0x85] = { RES, 0, REG_L }, // | 2--8 | - - - -
   [0x87] = { RES, 0, REG_A }, // | 2--8 | - - - -
   [0x88] = { RES, 1, REG_B }, // | 2--8 | - - - -
   [0x89] = { RES, 1, REG_C }, // | 2--8 | - - - -
   [0x8A] = { RES, 1, REG_D }, // | 2--8 | - - - -
   [0x8B] = { RES, 1, REG_E }, // | 2--8 | - - - -
   [0x8C] = { RES, 1, REG_H }, // | 2--8 | - - - -
   [0x8D] = { RES, 1, REG_L }, // | 2--8 | - - - -
   [0x8F] = { RES, 1, REG_A }, // | 2--8 | - - - -
   [0x90] = { RES, 2, REG_B }, // | 2--8 | - - - -
   [0x91] = { RES, 2, REG_C }, // | 2--8 | - - - -
   [0x92] = { RES, 2, REG_D }, // | 2--8 | - - - -
   [0x93] = { RES, 2, REG_E }, // | 2--8 | - - - -
   [0x94] = { RES, 2, REG_H }, // | 2--8 | - - - -
   [0x95] = { RES, 2, REG_L }, // | 2--8 | - - - -
   [0x97] = { RES, 2, REG_A }, // | 2--8 | - - - -
   [0x98] = { RES, 3, REG_B }, // | 2--8 | - - - -
   [0x99] = { RES, 3, REG_C }, // | 2--8 | - - - -
   [0x9A] = { RES, 3, REG_D }, // | 2--8 | - - - -
   [0x9B] = { RES, 3, REG_E }, // | 2--8 | - - - -
   [0x9C] = { RES, 3, REG_H }, // | 2--8 | - - - -
   [0x9D] = { RES, 3, REG_L }, // | 2--8 | - - - -
   [0x9F] = { RES, 3, REG_A }, // | 2--8 | - - - -
   [0xA0] = { RES, 4, REG_B }, // | 2--8 | - - - -
   [0xA1] = { RES, 4, REG_C }, // | 2--8 | - - - -
   [0xA2] = { RES, 4, REG_D }, // | 2--8 | - - - -
   [0xA3] = { RES, 4, REG_E }, // | 2--8 | - - - -
   [0xA4] = { RES, 4, REG_H }, // | 2--8 | - - - -
   [0xA5] = { RES, 4, REG_L }, // | 2--8 | - - - -
   [0xA7] = { RES, 4, REG_A }, // | 2--8 | - - - -
   [0xA8] = { RES, 5, REG_B }, // | 2--8 | - - - -
   [0xA9] = { RES, 5, REG_C }, // | 2--8 | - - - -
   [0xAA] = { RES, 5, REG_D }, // | 2--8 | - - - -
   [0xAB] = { RES, 5, REG_E }, // | 2--8 | - - - -
   [0xAC] = { RES, 5, REG_H }, // | 2--8 | - - - -
   [0xAD] = { RES, 5, REG_L }, // | 2--8 | - - - -
   [0xAF] = { RES, 5, REG_A }, // | 2--8 | - - - -
   [0xB0] = { RES, 6, REG_B }, // | 2--8 | - - - -
   [0xB1] = { RES, 6, REG_C }, // | 2--8 | - - - -
   [0xB2] = { RES, 6, REG_D }, // | 2--8 | - - - -
   [0xB3] = { RES, 6, REG_E }, // | 2--8 | - - - -
   [0xB4] = { RES, 6, REG_H }, // | 2--8 | - - - -
   [0xB5] = { RES, 6, REG_L }, // | 2--8 | - - - -
   [0xB7] = { RES, 6, REG_A }, // | 2--8 | - - - -
   [0xB8] = { RES, 7, REG_B }, // | 2--8 | - - - -
   [0xB9] = { RES, 7, REG_C }, // | 2--8 | - - - -
   [0xBA] = { RES, 7, REG_D }, // | 2--8 | - - - -
   [0xBB] = { RES, 7, REG_E }, // | 2--8 | - - - -
   [0xBC] = { RES, 7, REG_H }, // | 2--8 | - - - -
   [0xBD] = { RES, 7, REG_L }, // | 2--8 | - - - -
   [0xBF] = { RES, 7, REG_A }, // | 2--8 | - - - -
   [0x86] = { RES, 0, MEM_REG_HL }, // | 2--16 | - - - -
   [0x8E] = { RES, 1, MEM_REG_HL }, // | 2--16 | - - - -
   [0x96] = { RES, 2, MEM_REG_HL }, // | 2--16 | - - - -
   [0x9E] = { RES, 3, MEM_REG_HL }, // | 2--16 | - - - -
   [0xA6] = { RES, 4, MEM_REG_HL }, // | 2--16 | - - - -
   [0xAE] = { RES, 5, MEM_REG_HL }, // | 2--16 | - - - -
   [0xB6] = { RES, 6, MEM_REG_HL }, // | 2--16 | - - - -
   [0xBE] = { RES, 7, MEM_REG_HL }, // | 2--16 | - - - -
   
   
 

   [0xC0] = { SET, 0, REG_B }, // | 2--8 | - - - -
   [0xC1] = { SET, 0, REG_C }, // | 2--8 | - - - -
   [0xC2] = { SET, 0, REG_D }, // | 2--8 | - - - -
   [0xC3] = { SET, 0, REG_E }, // | 2--8 | - - - -
   [0xC4] = { SET, 0, REG_H }, // | 2--8 | - - - -
   [0xC5] = { SET, 0, REG_L }, // | 2--8 | - - - -
   [0xC7] = { SET, 0, REG_A }, // | 2--8 | - - - -
   [0xC8] = { SET, 1, REG_B }, // | 2--8 | - - - -
   [0xC9] = { SET, 1, REG_C }, // | 2--8 | - - - -
   [0xCA] = { SET, 1, REG_D }, // | 2--8 | - - - -
   [0xCB] = { SET, 1, REG_E }, // | 2--8 | - - - -
   [0xCC] = { SET, 1, REG_H }, // | 2--8 | - - - -
   [0xCD] = { SET, 1, REG_L }, // | 2--8 | - - - -
   [0xCF] = { SET, 1, REG_A }, // | 2--8 | - - - -
   [0xD0] = { SET, 2, REG_B }, // | 2--8 | - - - -
   [0xD1] = { SET, 2, REG_C }, // | 2--8 | - - - -
   [0xD2] = { SET, 2, REG_D }, // | 2--8 | - - - -
   [0xD3] = { SET, 2, REG_E }, // | 2--8 | - - - -
   [0xD4] = { SET, 2, REG_H }, // | 2--8 | - - - -
   [0xD5] = { SET, 2, REG_L }, // | 2--8 | - - - -
   [0xD7] = { SET, 2, REG_A }, // | 2--8 | - - - -
   [0xD8] = { SET, 3, REG_B }, // | 2--8 | - - - -
   [0xD9] = { SET, 3, REG_C }, // | 2--8 | - - - -
   [0xDA] = { SET, 3, REG_D }, // | 2--8 | - - - -
   [0xDB] = { SET, 3, REG_E }, // | 2--8 | - - - -
   [0xDC] = { SET, 3, REG_H }, // | 2--8 | - - - -
   [0xDD] = { SET, 3, REG_L }, // | 2--8 | - - - -
   [0xDF] = { SET, 3, REG_A }, // | 2--8 | - - - -
   [0xE0] = { SET, 4, REG_B }, // | 2--8 | - - - -
   [0xE1] = { SET, 4, REG_C }, // | 2--8 | - - - -
   [0xE2] = { SET, 4, REG_D }, // | 2--8 | - - - -
   [0xE3] = { SET, 4, REG_E }, // | 2--8 | - - - -
   [0xE4] = { SET, 4, REG_H }, // | 2--8 | - - - -
   [0xE5] = { SET, 4, REG_L }, // | 2--8 | - - - -
   [0xE7] = { SET, 4, REG_A }, // | 2--8 | - - - -
   [0xE8] = { SET, 5, REG_B }, // | 2--8 | - - - -
   [0xE9] = { SET, 5, REG_C }, // | 2--8 | - - - -
   [0xEA] = { SET, 5, REG_D }, // | 2--8 | - - - -
   [0xEB] = { SET, 5, REG_E }, // | 2--8 | - - - -
   [0xEC] = { SET, 5, REG_H }, // | 2--8 | - - - -
   [0xED] = { SET, 5, REG_L }, // | 2--8 | - - - -
   [0xEF] = { SET, 5, REG_A }, // | 2--8 | - - - -
   [0xF0] = { SET, 6, REG_B }, // | 2--8 | - - - -
   [0xF1] = { SET, 6, REG_C }, // | 2--8 | - - - -
   [0xF2] = { SET, 6, REG_D }, // | 2--8 | - - - -
   [0xF3] = { SET, 6, REG_E }, // | 2--8 | - - - -
   [0xF4] = { SET, 6, REG_H }, // | 2--8 | - - - -
   [0xF5] = { SET, 6, REG_L }, // | 2--8 | - - - -
   [0xF7] = { SET, 6, REG_A }, // | 2--8 | - - - -
   [0xF8] = { SET, 7, REG_B }, // | 2--8 | - - - -
   [0xF9] = { SET, 7, REG_C }, // | 2--8 | - - - -
   [0xFA] = { SET, 7, REG_D }, // | 2--8 | - - - -
   [0xFB] = { SET, 7, REG_E }, // | 2--8 | - - - -
   [0xFC] = { SET, 7, REG_H }, // | 2--8 | - - - -
   [0xFD] = { SET, 7, REG_L }, // | 2--8 | - - - -
   [0xFF] = { SET, 7, REG_A }, // | 2--8 | - - - -
   [0xC6] = { SET, 0, MEM_REG_HL }, // | 2--16 | - - - -
   [0xCE] = { SET, 1, MEM_REG_HL }, // | 2--16 | - - - -
   [0xD6] = { SET, 2, MEM_REG_HL }, // | 2--16 | - - - -
   [0xDE] = { SET, 3, MEM_REG_HL }, // | 2--16 | - - - -
   [0xE6] = { SET, 4, MEM_REG_HL }, // | 2--16 | - - - -
   [0xEE] = { SET, 5, MEM_REG_HL }, // | 2--16 | - - - -
   [0xF6] = { SET, 6, MEM_REG_HL }, // | 2--16 | - - - -
   [0xFE] = { SET, 7, MEM_REG_HL }, // | 2--16 | - - - -
};
