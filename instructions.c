#include "operands.h"
#include "instructions.h"
#include "cpu.h"

char *str_operands[]= {
 [REG_A] = "REG_A",
 [REG_F] = "REG_F",
 [REG_B] = "REG_B",
 [REG_C] = "REG_C",
 [REG_D] = "REG_D",
 [REG_E] = "REG_E",
 [REG_H] = "REG_H",
 [REG_L] = "REG_L",
 [REG_SP] = "REG_SP",
 [REG_PC] = "REG_PC",
 [REG_AF] = "REG_AF",
 [REG_BC] = "REG_BC ",
 [REG_DE] = "REG_DE ",
 [REG_HL] = "REG_HL ",
 [MEM_REG_BC] = "MEM_REG_BC",
 [MEM_REG_DE] = "MEM_REG_DE",
 [MEM_REG_HL] = "MEM_REG_HL",
 [MEM_IMM16] = "MEM_IMM16",
 [MEM_REG_C] = "MEM_REG_C",
 [MEM_IMM8] = "MEM_IMM8",
 [MEM_REG_HL_PLUS] = "MEM_REG_HL_PLUS",
 [MEM_REG_HL_MINUS] = "MEM_REG_HL_MINUS",
 [IMM8] = "IMM8",
 [SIMM8] = "SIMM8",
 [IMM16] = "IMM16",
 [CON_NZ] = "CON_NZ",
 [CON_Z] = "CON_Z", 
 [CON_NC] = "CON_NC",
 [CON_C] = "CON_C", 
 [REG_SP_PLUS_SIMM8] = "REG_SP_PLUS_SIMM8", 
 [EMPTY] = "EMPTY",
};

// Normal Instructions         
const instruction normal_inst[0x100] = {
    // Load (LD) instructions
   [0x40] = { ldFunction, REG_B, REG_B }, // | 1--4 | - - - -
   [0x41] = { ldFunction, REG_B, REG_C }, // | 1--4 | - - - -
   [0x42] = { ldFunction, REG_B, REG_D }, // | 1--4 | - - - -
   [0x43] = { ldFunction, REG_B, REG_E }, // | 1--4 | - - - -
   [0x44] = { ldFunction, REG_B, REG_H }, // | 1--4 | - - - -
   [0x45] = { ldFunction, REG_B, REG_L }, // | 1--4 | - - - -
   [0x47] = { ldFunction, REG_B, REG_A }, // | 1--4 | - - - -
   [0x48] = { ldFunction, REG_C, REG_B }, // | 1--4 | - - - -
   [0x49] = { ldFunction, REG_C, REG_C }, // | 1--4 | - - - -
   [0x4A] = { ldFunction, REG_C, REG_D }, // | 1--4 | - - - -
   [0x4B] = { ldFunction, REG_C, REG_E }, // | 1--4 | - - - -
   [0x4C] = { ldFunction, REG_C, REG_H }, // | 1--4 | - - - -
   [0x4D] = { ldFunction, REG_C, REG_L }, // | 1--4 | - - - -
   [0x4F] = { ldFunction, REG_C, REG_A }, // | 1--4 | - - - -
   [0x50] = { ldFunction, REG_D, REG_B }, // | 1--4 | - - - -
   [0x51] = { ldFunction, REG_D, REG_C }, // | 1--4 | - - - -
   [0x52] = { ldFunction, REG_D, REG_D }, // | 1--4 | - - - -
   [0x53] = { ldFunction, REG_D, REG_E }, // | 1--4 | - - - -
   [0x54] = { ldFunction, REG_D, REG_H }, // | 1--4 | - - - -
   [0x55] = { ldFunction, REG_D, REG_L }, // | 1--4 | - - - -
   [0x57] = { ldFunction, REG_D, REG_A }, // | 1--4 | - - - -
   [0x58] = { ldFunction, REG_E, REG_B }, // | 1--4 | - - - -
   [0x59] = { ldFunction, REG_E, REG_C }, // | 1--4 | - - - -
   [0x5A] = { ldFunction, REG_E, REG_D }, // | 1--4 | - - - -
   [0x5B] = { ldFunction, REG_E, REG_E }, // | 1--4 | - - - -
   [0x5C] = { ldFunction, REG_E, REG_H }, // | 1--4 | - - - -
   [0x5D] = { ldFunction, REG_E, REG_L }, // | 1--4 | - - - -
   [0x5F] = { ldFunction, REG_E, REG_A }, // | 1--4 | - - - -
   [0x60] = { ldFunction, REG_H, REG_B }, // | 1--4 | - - - -
   [0x61] = { ldFunction, REG_H, REG_C }, // | 1--4 | - - - -
   [0x62] = { ldFunction, REG_H, REG_D }, // | 1--4 | - - - -
   [0x63] = { ldFunction, REG_H, REG_E }, // | 1--4 | - - - -
   [0x64] = { ldFunction, REG_H, REG_H }, // | 1--4 | - - - -
   [0x65] = { ldFunction, REG_H, REG_L }, // | 1--4 | - - - -
   [0x67] = { ldFunction, REG_H, REG_A }, // | 1--4 | - - - -
   [0x68] = { ldFunction, REG_L, REG_B }, // | 1--4 | - - - -
   [0x69] = { ldFunction, REG_L, REG_C }, // | 1--4 | - - - -
   [0x6A] = { ldFunction, REG_L, REG_D }, // | 1--4 | - - - -
   [0x6B] = { ldFunction, REG_L, REG_E }, // | 1--4 | - - - -
   [0x6C] = { ldFunction, REG_L, REG_H }, // | 1--4 | - - - -
   [0x6D] = { ldFunction, REG_L, REG_L }, // | 1--4 | - - - -
   [0x6F] = { ldFunction, REG_L, REG_A }, // | 1--4 | - - - -
   [0x78] = { ldFunction, REG_A, REG_B }, // | 1--4 | - - - -
   [0x79] = { ldFunction, REG_A, REG_C }, // | 1--4 | - - - -
   [0x7A] = { ldFunction, REG_A, REG_D }, // | 1--4 | - - - -
   [0x7B] = { ldFunction, REG_A, REG_E }, // | 1--4 | - - - -
   [0x7C] = { ldFunction, REG_A, REG_H }, // | 1--4 | - - - -
   [0x7D] = { ldFunction, REG_A, REG_L }, // | 1--4 | - - - -
   [0x7F] = { ldFunction, REG_A, REG_A }, // | 1--4 | - - - -
   [0xF9] = { ldFunction, REG_SP, REG_HL }, // | 1--8 | - - - -

   [0x46] = { ldFunction, REG_B, MEM_REG_HL }, // | 1--8 | - - - -
   [0x4E] = { ldFunction, REG_C, MEM_REG_HL }, // | 1--8 | - - - -
   [0x56] = { ldFunction, REG_D, MEM_REG_HL }, // | 1--8 | - - - -
   [0x5E] = { ldFunction, REG_E, MEM_REG_HL }, // | 1--8 | - - - -
   [0x66] = { ldFunction, REG_H, MEM_REG_HL }, // | 1--8 | - - - -
   [0x6E] = { ldFunction, REG_L, MEM_REG_HL }, // | 1--8 | - - - -
   [0x7E] = { ldFunction, REG_A, MEM_REG_HL }, // | 1--8 | - - - -
   [0x0A] = { ldFunction, REG_A, MEM_REG_BC }, // | 1--8 | - - - -
   [0x1A] = { ldFunction, REG_A, MEM_REG_DE }, // | 1--8 | - - - -
   [0xFA] = { ldFunction, REG_A, MEM_IMM16 }, // | 3--16 | - - - -
   [0x2A] = { ldFunction, REG_A, MEM_REG_HL_PLUS }, // | 1--8 | - - - -
   [0x3A] = { ldFunction, REG_A, MEM_REG_HL_MINUS }, // | 1--8 | - - - -
   [0xF2] = { ldFunction, REG_A, MEM_REG_C }, // | 2--8 | - - - -
   [0xF0] = { ldFunction, REG_A, MEM_IMM8 }, // | 2--12 | - - - -


   [0x70] = { ldFunction, MEM_REG_HL, REG_B }, // | 1--8 | - - - -
   [0x71] = { ldFunction, MEM_REG_HL, REG_C }, // | 1--8 | - - - -
   [0x72] = { ldFunction, MEM_REG_HL, REG_D }, // | 1--8 | - - - -
   [0x73] = { ldFunction, MEM_REG_HL, REG_E }, // | 1--8 | - - - -
   [0x74] = { ldFunction, MEM_REG_HL, REG_H }, // | 1--8 | - - - -
   [0x75] = { ldFunction, MEM_REG_HL, REG_L }, // | 1--8 | - - - -
   [0x77] = { ldFunction, MEM_REG_HL, REG_A }, // | 1--8 | - - - -
   [0x36] = { ldFunction, MEM_REG_HL, IMM8 }, // | 2--12 | - - - -
   [0x02] = { ldFunction, MEM_REG_BC, REG_A }, // | 1--8 | - - - -
   [0x12] = { ldFunction, MEM_REG_DE, REG_A }, // | 1--8 | - - - -
   [0xE2] = { ldFunction, MEM_REG_C, REG_A }, // | 2--8 | - - - -
   [0xE0] = { ldFunction, MEM_IMM8, REG_A }, // | 2--12 | - - - -
   [0x22] = { ldFunction, MEM_REG_HL_PLUS, REG_A }, // | 1--8 | - - - -
   [0x32] = { ldFunction, MEM_REG_HL_MINUS, REG_A }, // | 1--8 | - - - -
   [0x08] = { ldFunction, MEM_IMM16, REG_SP }, // | 3--20 | - - - -
   [0xEA] = { ldFunction, MEM_IMM16, REG_A }, // | 3--16 | - - - -

   [0x3E] = { ldFunction, REG_A, IMM8 }, // | 2--8 | - - - -
   [0x06] = { ldFunction, REG_B, IMM8 }, // | 2--8 | - - - -
   [0x0E] = { ldFunction, REG_C, IMM8 }, // | 2--8 | - - - -
   [0x16] = { ldFunction, REG_D, IMM8 }, // | 2--8 | - - - -
   [0x1E] = { ldFunction, REG_E, IMM8 }, // | 2--8 | - - - -
   [0x26] = { ldFunction, REG_H, IMM8 }, // | 2--8 | - - - -
   [0x2E] = { ldFunction, REG_L, IMM8 }, // | 2--8 | - - - -


   [0x01] = { ldFunction, REG_BC, IMM16 }, // | 3--12 | - - - -
   [0x11] = { ldFunction, REG_DE, IMM16 }, // | 3--12 | - - - -
   [0x21] = { ldFunction, REG_HL, IMM16 }, // | 3--12 | - - - -
   [0x31] = { ldFunction, REG_SP, IMM16 }, // | 3--12 | - - - -

   [0xF8] = { ldFunction, REG_HL, REG_SP_PLUS_SIMM8}, // | 2--12 | 0 0 H C



   // Increment (INC) instructions
   [0x04] = { incFunction, REG_B , EMPTY }, // | 1--4 | Z 0 H -
   [0x0C] = { incFunction, REG_C , EMPTY }, // | 1--4 | Z 0 H -
   [0x14] = { incFunction, REG_D , EMPTY }, // | 1--4 | Z 0 H -
   [0x1C] = { incFunction, REG_E , EMPTY }, // | 1--4 | Z 0 H -
   [0x24] = { incFunction, REG_H , EMPTY }, // | 1--4 | Z 0 H -
   [0x2C] = { incFunction, REG_L , EMPTY }, // | 1--4 | Z 0 H -
   [0x3C] = { incFunction, REG_A , EMPTY }, // | 1--4 | Z 0 H -
   [0x34] = { incFunction, MEM_REG_HL, EMPTY }, // | 1--12 | Z 0 H -

   [0x03] = { incFunction, REG_BC, EMPTY }, // | 1--8 | - - - -
   [0x13] = { incFunction, REG_DE, EMPTY }, // | 1--8 | - - - -
   [0x23] = { incFunction, REG_HL, EMPTY }, // | 1--8 | - - - -
   [0x33] = { incFunction, REG_SP, EMPTY }, // | 1--8 | - - - -


   // Decrement (DEC) instructions
   [0x05] = { decFunction, REG_B  , EMPTY }, // | 1--4 | Z 1 H -
   [0x0D] = { decFunction, REG_C  , EMPTY }, // | 1--4 | Z 1 H -
   [0x15] = { decFunction, REG_D  , EMPTY }, // | 1--4 | Z 1 H -
   [0x1D] = { decFunction, REG_E  , EMPTY }, // | 1--4 | Z 1 H -
   [0x25] = { decFunction, REG_H  , EMPTY }, // | 1--4 | Z 1 H -
   [0x2D] = { decFunction, REG_L  , EMPTY }, // | 1--4 | Z 1 H -
   [0x3D] = { decFunction, REG_A  , EMPTY }, // | 1--4 | Z 1 H -
   [0x35] = { decFunction, MEM_REG_HL, EMPTY }, // | 1--12 | Z 1 H -

   [0x0B] = { decFunction, REG_BC , EMPTY }, // | 1--8 | - - - -
   [0x1B] = { decFunction, REG_DE , EMPTY }, // | 1--8 | - - - -
   [0x2B] = { decFunction, REG_HL , EMPTY }, // | 1--8 | - - - -
   [0x3B] = { decFunction, REG_SP , EMPTY }, // | 1--8 | - - - -


   // Add (ADD) instructions
   [0x80] = { addFunction, REG_A, REG_B }, // | 1--4 | Z 0 H C
   [0x81] = { addFunction, REG_A, REG_C }, // | 1--4 | Z 0 H C
   [0x82] = { addFunction, REG_A, REG_D }, // | 1--4 | Z 0 H C
   [0x83] = { addFunction, REG_A, REG_E }, // | 1--4 | Z 0 H C
   [0x84] = { addFunction, REG_A, REG_H }, // | 1--4 | Z 0 H C
   [0x85] = { addFunction, REG_A, REG_L }, // | 1--4 | Z 0 H C
   [0x87] = { addFunction, REG_A, REG_A }, // | 1--4 | Z 0 H C
   [0xC6] = { addFunction, REG_A, IMM8  }, // | 2--8 | Z 0 H C
   [0x86] = { addFunction, REG_A, MEM_REG_HL}, // | 1--8 | Z 0 H C

   [0x09] = { addFunction, REG_HL, REG_BC }, // | 1--8 | - 0 H C
   [0x19] = { addFunction, REG_HL, REG_DE }, // | 1--8 | - 0 H C
   [0x29] = { addFunction, REG_HL, REG_HL }, // | 1--8 | - 0 H C
   [0x39] = { addFunction, REG_HL, REG_SP }, // | 1--8 | - 0 H C

   [0xE8] = { addFunction, REG_SP, SIMM8 }, // | 2--16 | 0 0 H C

   // Add with carry (ADC) instructions
   [0x88] = { adcFunction, REG_A, REG_B }, // | 1--4 | Z 0 H C
   [0x89] = { adcFunction, REG_A, REG_C }, // | 1--4 | Z 0 H C
   [0x8A] = { adcFunction, REG_A, REG_D }, // | 1--4 | Z 0 H C
   [0x8B] = { adcFunction, REG_A, REG_E }, // | 1--4 | Z 0 H C
   [0x8C] = { adcFunction, REG_A, REG_H }, // | 1--4 | Z 0 H C
   [0x8D] = { adcFunction, REG_A, REG_L }, // | 1--4 | Z 0 H C
   [0x8F] = { adcFunction, REG_A, REG_A }, // | 1--4 | Z 0 H C
   [0xCE] = { adcFunction, REG_A, IMM8 }, // | 2--8 | Z 0 H C
   [0x8E] = { adcFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 H C


   // Subtract (SUB) instructions
   [0x90] = { subFunction, REG_A, REG_B }, // | 1--4 | Z 1 H C
   [0x91] = { subFunction, REG_A, REG_C }, // | 1--4 | Z 1 H C
   [0x92] = { subFunction, REG_A, REG_D }, // | 1--4 | Z 1 H C
   [0x93] = { subFunction, REG_A, REG_E }, // | 1--4 | Z 1 H C
   [0x94] = { subFunction, REG_A, REG_H }, // | 1--4 | Z 1 H C
   [0x95] = { subFunction, REG_A, REG_L }, // | 1--4 | Z 1 H C
   [0x97] = { subFunction, REG_A, REG_A }, // | 1--4 | Z 1 H C
   [0xD6] = { subFunction, REG_A, IMM8 }, // | 2--8 | Z 1 H C
   [0x96] = { subFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 1 H C


   // Subtract with carry (SBC) instructions
   [0x98] = { sbcFunction, REG_A, REG_B }, // | 1--4 | Z 1 H C
   [0x99] = { sbcFunction, REG_A, REG_C }, // | 1--4 | Z 1 H C
   [0x9A] = { sbcFunction, REG_A, REG_D }, // | 1--4 | Z 1 H C
   [0x9B] = { sbcFunction, REG_A, REG_E }, // | 1--4 | Z 1 H C
   [0x9C] = { sbcFunction, REG_A, REG_H }, // | 1--4 | Z 1 H C
   [0x9D] = { sbcFunction, REG_A, REG_L }, // | 1--4 | Z 1 H C
   [0x9F] = { sbcFunction, REG_A, REG_A }, // | 1--4 | Z 1 H C
   [0xDE] = { sbcFunction, REG_A, IMM8 }, // | 2--8 | Z 1 H C
   [0x9E] = { sbcFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 1 H C




   // And (AND) instructions
   [0xA0] = { andFunction, REG_A, REG_B }, // | 1--4 | Z 0 1 0
   [0xA1] = { andFunction, REG_A, REG_C }, // | 1--4 | Z 0 1 0
   [0xA2] = { andFunction, REG_A, REG_D }, // | 1--4 | Z 0 1 0
   [0xA3] = { andFunction, REG_A, REG_E }, // | 1--4 | Z 0 1 0
   [0xA4] = { andFunction, REG_A, REG_H }, // | 1--4 | Z 0 1 0
   [0xA5] = { andFunction, REG_A, REG_L }, // | 1--4 | Z 0 1 0
   [0xA7] = { andFunction, REG_A, REG_A }, // | 1--4 | Z 0 1 0
   [0xE6] = { andFunction, REG_A, IMM8 }, // | 2--8 | Z 0 1 0
   [0xA6] = { andFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 1 0


   // Or (OR) instructions
   [0xB0] = { orFunction, REG_A, REG_B }, // | 1--4 | Z 0 0 0
   [0xB1] = { orFunction, REG_A, REG_C }, // | 1--4 | Z 0 0 0
   [0xB2] = { orFunction, REG_A, REG_D }, // | 1--4 | Z 0 0 0
   [0xB3] = { orFunction, REG_A, REG_E }, // | 1--4 | Z 0 0 0
   [0xB4] = { orFunction, REG_A, REG_H }, // | 1--4 | Z 0 0 0
   [0xB5] = { orFunction, REG_A, REG_L }, // | 1--4 | Z 0 0 0
   [0xB7] = { orFunction, REG_A, REG_A }, // | 1--4 | Z 0 0 0
   [0xF6] = { orFunction, REG_A, IMM8 }, // | 2--8 | Z 0 0 0
   [0xB6] = { orFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 0 0


   // Xor (XOR) instructions
   [0xA8] = { xorFunction, REG_A, REG_B }, // | 1--4 | Z 0 0 0
   [0xA9] = { xorFunction, REG_A, REG_C }, // | 1--4 | Z 0 0 0
   [0xAA] = { xorFunction, REG_A, REG_D }, // | 1--4 | Z 0 0 0
   [0xAB] = { xorFunction, REG_A, REG_E }, // | 1--4 | Z 0 0 0
   [0xAC] = { xorFunction, REG_A, REG_H }, // | 1--4 | Z 0 0 0
   [0xAD] = { xorFunction, REG_A, REG_L }, // | 1--4 | Z 0 0 0
   [0xAF] = { xorFunction, REG_A, REG_A }, // | 1--4 | Z 0 0 0
   [0xEE] = { xorFunction, REG_A, IMM8 }, // | 2--8 | Z 0 0 0
   [0xAE] = { xorFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 0 0 0

   // Compare (CP) instructions
   [0xB8] = { cpFunction, REG_A, REG_B }, // | 1--4 | Z 1 H C
   [0xB9] = { cpFunction, REG_A, REG_C }, // | 1--4 | Z 1 H C
   [0xBA] = { cpFunction, REG_A, REG_D }, // | 1--4 | Z 1 H C
   [0xBB] = { cpFunction, REG_A, REG_E }, // | 1--4 | Z 1 H C
   [0xBC] = { cpFunction, REG_A, REG_H }, // | 1--4 | Z 1 H C
   [0xBD] = { cpFunction, REG_A, REG_L }, // | 1--4 | Z 1 H C
   [0xBF] = { cpFunction, REG_A, REG_A }, // | 1--4 | Z 1 H C
   [0xFE] = { cpFunction, REG_A, IMM8 }, // | 2--8 | Z 1 H C
   [0xBE] = { cpFunction, REG_A, MEM_REG_HL }, // | 1--8 | Z 1 H C


   // Jump (JP) instructions
   [0xE9] = { jpFunction, MEM_REG_HL, EMPTY }, // | 1--4 | - - - -
   [0xC3] = { jpFunction, IMM16, EMPTY }, // | 3--16 | - - - -
   [0xC2] = { jpFunction, CON_NZ,IMM16 }, // | 3--16/12 | - - - -
   [0xCA] = { jpFunction, CON_Z,IMM16 }, // | 3--16/12 | - - - -
   [0xD2] = { jpFunction, CON_NC,IMM16 }, // | 3--16/12 | - - - -
   [0xDA] = { jpFunction, CON_C,IMM16 }, // | 3--16/12 | - - - -


   // Relative jump (JR) instructions
   [0x18] = { jrFunction, SIMM8, EMPTY }, // | 2--12 | - - - -
   [0x38] = { jrFunction, CON_C, SIMM8 }, // | 2--12/8 | - - - -
   [0x20] = { jrFunction, CON_NZ, SIMM8 }, // | 2--12/8 | - - - -
   [0x28] = { jrFunction, CON_Z, SIMM8 }, // | 2--12/8 | - - - -
   [0x30] = { jrFunction, CON_NC, SIMM8 }, // | 2--12/8 | - - - -



   // Push to stack (PUSH) instructions
   [0xC5] = { pushFunction, REG_BC, EMPTY }, // | 1--16 | - - - -
   [0xD5] = { pushFunction, REG_DE, EMPTY }, // | 1--16 | - - - -
   [0xE5] = { pushFunction, REG_HL, EMPTY }, // | 1--16 | - - - -
   [0xF5] = { pushFunction, REG_AF, EMPTY }, // | 1--16 | - - - -


   // Pop from stack (POP) instructions
   [0xC1] = { popFunction, REG_BC, EMPTY }, // | 1--12 | - - - -
   [0xD1] = { popFunction, REG_DE, EMPTY }, // | 1--12 | - - - -
   [0xE1] = { popFunction, REG_HL, EMPTY }, // | 1--12 | - - - -
   [0xF1] = { popFunction, REG_AF, EMPTY }, // | 1--12 | Z N H C


   // Call a routine (CALL) instructions
   [0xCD] = { callFunction, IMM16, EMPTY }, // | 3--24 | - - - -
   [0xC4] = { callFunction, CON_NZ,IMM16 }, // | 3--24/12 | - - - -
   [0xCC] = { callFunction, CON_Z,IMM16 }, // | 3--24/12 | - - - -
   [0xD4] = { callFunction, CON_NC,IMM16 }, // | 3--24/12 | - - - -
   [0xDC] = { callFunction, CON_C,IMM16 }, // | 3--24/12 | - - - -



   // Reture from a routine (RET) instructions
   [0xC0] = { retFunction, CON_NZ, EMPTY }, // | 1--20/8 | - - - -
   [0xC8] = { retFunction, CON_Z , EMPTY }, // | 1--20/8 | - - - -
   [0xD0] = { retFunction, CON_NC, EMPTY }, // | 1--20/8 | - - - -
   [0xD8] = { retFunction, CON_C , EMPTY }, // | 1--20/8 | - - - -
   [0xC9] = { retFunction, EMPTY, EMPTY }, // | 1--16 | - - - -
   [0xD9] = { retiFunction, EMPTY, EMPTY }, // | 1--16 | - - - -


   // Call Reset Routines (RST) instructions
   [0xC7] = { rstFunction, 0x00, EMPTY}, // | 1--16 | - - - -
   [0xCF] = { rstFunction, 0x08, EMPTY}, // | 1--16 | - - - -
   [0xD7] = { rstFunction, 0x10, EMPTY}, // | 1--16 | - - - -
   [0xDF] = { rstFunction, 0x18, EMPTY}, // | 1--16 | - - - -
   [0xE7] = { rstFunction, 0x20, EMPTY}, // | 1--16 | - - - -
   [0xEF] = { rstFunction, 0x28, EMPTY}, // | 1--16 | - - - -
   [0xF7] = { rstFunction, 0x30, EMPTY}, // | 1--16 | - - - -
   [0xFF] = { rstFunction, 0x38, EMPTY}, // | 1--16 | - - - -


  
   // Decimal Adjust for REG_A instruction
   [0x27] = { daaFunction, EMPTY, EMPTY }, // | 1--4 | Z - 0 C

   // REG_A XOR 0xFF instruction
   [0x2F] = { cplFunction, EMPTY, EMPTY }, // | 1--4 | - 1 1 -

   // Set carry flag to 1 instruction
   [0x37] = { scfFunction, EMPTY, EMPTY }, // | 1--4 | - 0 0 1

   // carry XOR 0xFF instruction
   [0x3F] = { ccfFunction, EMPTY, EMPTY }, // | 1--4 | - 0 0 C
   
  
   //Enable (EI) and disable (DI) interrupts instructions 
   [0xF3] = { diFunction, EMPTY, EMPTY }, // | 1--4 | - - - -
   [0xFB] = { eiFunction, EMPTY, EMPTY }, // | 1--4 | - - - -
  
   // No operation instruction
   [0x00] = { nopFunction, EMPTY, EMPTY }, // | 1--4 | - - - -
   // Stop instruction
   [0x10] = { stopFunction, EMPTY, EMPTY }, // | 2--4 | - - - -
   // Halt instruction
   [0x76] = { haltFunction, EMPTY, EMPTY }, // | 1--4 | - - - -
   
  
   // Rotate REG_A left through carry (RLA) instruction
   [0x17] = { rlaFunction, EMPTY, EMPTY }, // | 1--4 | 0 0 0 C
   // Rotate REG_A right through carry (RRA) instruction
   [0x1F] = { rraFunction, EMPTY, EMPTY }, // | 1--4 | 0 0 0 C
   // Rotate REG_A left (RLCA) instruction
   [0x07] = { rlcaFunction, EMPTY, EMPTY}, // | 1--4 | 0 0 0 C
   // Rotate REG_A right (RRCA) instruction
   [0x0F] = { rrcaFunction, EMPTY, EMPTY}, // | 1--4 | 0 0 0 C
};
   
         
// CB Instructions         
const instruction cb_inst[0x100] = {
   // Rotate left (RLC) instruction
   [0x00] = { rlcFunction, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x01] = { rlcFunction, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x02] = { rlcFunction, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x03] = { rlcFunction, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x04] = { rlcFunction, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x05] = { rlcFunction, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x07] = { rlcFunction, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x06] = { rlcFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C


   // Rotate right (RRC) instruction
   [0x08] = { rrcFunction, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x09] = { rrcFunction, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0A] = { rrcFunction, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0B] = { rrcFunction, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0C] = { rrcFunction, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0D] = { rrcFunction, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0F] = { rrcFunction, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x0E] = { rrcFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C
   
   
   // Rotate left through carry (RL) instruction
   [0x10] = { rlFunction, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x11] = { rlFunction, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x12] = { rlFunction, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x13] = { rlFunction, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x14] = { rlFunction, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x15] = { rlFunction, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x17] = { rlFunction, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x16] = { rlFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C

   // Rotate right through carry (RR) instruction
   [0x18] = { rrFunction, REG_B, EMPTY }, // | 2--8 | Z 0 0 C
   [0x19] = { rrFunction, REG_C, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1A] = { rrFunction, REG_D, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1B] = { rrFunction, REG_E, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1C] = { rrFunction, REG_H, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1D] = { rrFunction, REG_L, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1F] = { rrFunction, REG_A, EMPTY }, // | 2--8 | Z 0 0 C
   [0x1E] = { rrFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C
   
  // Shift left arithmetically (SLA) instruction 
   [0x20] = { slaFunction, REG_B, EMPTY}, // | 2--8 | Z 0 0 C
   [0x21] = { slaFunction, REG_C, EMPTY}, // | 2--8 | Z 0 0 C
   [0x22] = { slaFunction, REG_D, EMPTY}, // | 2--8 | Z 0 0 C
   [0x23] = { slaFunction, REG_E, EMPTY}, // | 2--8 | Z 0 0 C
   [0x24] = { slaFunction, REG_H, EMPTY}, // | 2--8 | Z 0 0 C
   [0x25] = { slaFunction, REG_L, EMPTY}, // | 2--8 | Z 0 0 C
   [0x27] = { slaFunction, REG_A, EMPTY}, // | 2--8 | Z 0 0 C
   [0x26] = { slaFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C

  // Shift right arithmetically (SRA) instruction 
   [0x28] = { sraFunction, REG_B, EMPTY}, // | 2--8 | Z 0 0 0
   [0x29] = { sraFunction, REG_C, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2A] = { sraFunction, REG_D, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2B] = { sraFunction, REG_E, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2C] = { sraFunction, REG_H, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2D] = { sraFunction, REG_L, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2F] = { sraFunction, REG_A, EMPTY}, // | 2--8 | Z 0 0 0
   [0x2E] = { sraFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 0
   
   

  // Shift right logically (SRL) instruction 
   [0x38] = { srlFunction, REG_B, EMPTY}, // | 2--8 | Z 0 0 C
   [0x39] = { srlFunction, REG_C, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3A] = { srlFunction, REG_D, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3B] = { srlFunction, REG_E, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3C] = { srlFunction, REG_H, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3D] = { srlFunction, REG_L, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3F] = { srlFunction, REG_A, EMPTY}, // | 2--8 | Z 0 0 C
   [0x3E] = { srlFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 C



   // Swap between high and low nibbles (SWAP) instruction
   [0x30] = { swapFunction, REG_B, EMPTY }, // | 2--8 | Z 0 0 0
   [0x31] = { swapFunction, REG_C, EMPTY }, // | 2--8 | Z 0 0 0
   [0x32] = { swapFunction, REG_D, EMPTY }, // | 2--8 | Z 0 0 0
   [0x33] = { swapFunction, REG_E, EMPTY }, // | 2--8 | Z 0 0 0
   [0x34] = { swapFunction, REG_H, EMPTY }, // | 2--8 | Z 0 0 0
   [0x35] = { swapFunction, REG_L, EMPTY }, // | 2--8 | Z 0 0 0
   [0x37] = { swapFunction, REG_A, EMPTY }, // | 2--8 | Z 0 0 0
   [0x36] = { swapFunction, MEM_REG_HL, EMPTY }, // | 2--16 | Z 0 0 0




   
  // Check bit status (BIT) instruction 
   [0x40] = { bitFunction, 0, REG_B }, // | 2--8 | Z 0 1 -
   [0x41] = { bitFunction, 0, REG_C }, // | 2--8 | Z 0 1 -
   [0x42] = { bitFunction, 0, REG_D }, // | 2--8 | Z 0 1 -
   [0x43] = { bitFunction, 0, REG_E }, // | 2--8 | Z 0 1 -
   [0x44] = { bitFunction, 0, REG_H }, // | 2--8 | Z 0 1 -
   [0x45] = { bitFunction, 0, REG_L }, // | 2--8 | Z 0 1 -
   [0x47] = { bitFunction, 0, REG_A }, // | 2--8 | Z 0 1 -
   [0x48] = { bitFunction, 1, REG_B }, // | 2--8 | Z 0 1 -
   [0x49] = { bitFunction, 1, REG_C }, // | 2--8 | Z 0 1 -
   [0x4A] = { bitFunction, 1, REG_D }, // | 2--8 | Z 0 1 -
   [0x4B] = { bitFunction, 1, REG_E }, // | 2--8 | Z 0 1 -
   [0x4C] = { bitFunction, 1, REG_H }, // | 2--8 | Z 0 1 -
   [0x4D] = { bitFunction, 1, REG_L }, // | 2--8 | Z 0 1 -
   [0x4F] = { bitFunction, 1, REG_A }, // | 2--8 | Z 0 1 -
   [0x50] = { bitFunction, 2, REG_B }, // | 2--8 | Z 0 1 -
   [0x51] = { bitFunction, 2, REG_C }, // | 2--8 | Z 0 1 -
   [0x52] = { bitFunction, 2, REG_D }, // | 2--8 | Z 0 1 -
   [0x53] = { bitFunction, 2, REG_E }, // | 2--8 | Z 0 1 -
   [0x54] = { bitFunction, 2, REG_H }, // | 2--8 | Z 0 1 -
   [0x55] = { bitFunction, 2, REG_L }, // | 2--8 | Z 0 1 -
   [0x57] = { bitFunction, 2, REG_A }, // | 2--8 | Z 0 1 -
   [0x58] = { bitFunction, 3, REG_B }, // | 2--8 | Z 0 1 -
   [0x59] = { bitFunction, 3, REG_C }, // | 2--8 | Z 0 1 -
   [0x5A] = { bitFunction, 3, REG_D }, // | 2--8 | Z 0 1 -
   [0x5B] = { bitFunction, 3, REG_E }, // | 2--8 | Z 0 1 -
   [0x5C] = { bitFunction, 3, REG_H }, // | 2--8 | Z 0 1 -
   [0x5D] = { bitFunction, 3, REG_L }, // | 2--8 | Z 0 1 -
   [0x5F] = { bitFunction, 3, REG_A }, // | 2--8 | Z 0 1 -
   [0x60] = { bitFunction, 4, REG_B }, // | 2--8 | Z 0 1 -
   [0x61] = { bitFunction, 4, REG_C }, // | 2--8 | Z 0 1 -
   [0x62] = { bitFunction, 4, REG_D }, // | 2--8 | Z 0 1 -
   [0x63] = { bitFunction, 4, REG_E }, // | 2--8 | Z 0 1 -
   [0x64] = { bitFunction, 4, REG_H }, // | 2--8 | Z 0 1 -
   [0x65] = { bitFunction, 4, REG_L }, // | 2--8 | Z 0 1 -
   [0x67] = { bitFunction, 4, REG_A }, // | 2--8 | Z 0 1 -
   [0x68] = { bitFunction, 5, REG_B }, // | 2--8 | Z 0 1 -
   [0x69] = { bitFunction, 5, REG_C }, // | 2--8 | Z 0 1 -
   [0x6A] = { bitFunction, 5, REG_D }, // | 2--8 | Z 0 1 -
   [0x6B] = { bitFunction, 5, REG_E }, // | 2--8 | Z 0 1 -
   [0x6C] = { bitFunction, 5, REG_H }, // | 2--8 | Z 0 1 -
   [0x6D] = { bitFunction, 5, REG_L }, // | 2--8 | Z 0 1 -
   [0x6F] = { bitFunction, 5, REG_A }, // | 2--8 | Z 0 1 -
   [0x70] = { bitFunction, 6, REG_B }, // | 2--8 | Z 0 1 -
   [0x71] = { bitFunction, 6, REG_C }, // | 2--8 | Z 0 1 -
   [0x72] = { bitFunction, 6, REG_D }, // | 2--8 | Z 0 1 -
   [0x73] = { bitFunction, 6, REG_E }, // | 2--8 | Z 0 1 -
   [0x74] = { bitFunction, 6, REG_H }, // | 2--8 | Z 0 1 -
   [0x75] = { bitFunction, 6, REG_L }, // | 2--8 | Z 0 1 -
   [0x77] = { bitFunction, 6, REG_A }, // | 2--8 | Z 0 1 -
   [0x78] = { bitFunction, 7, REG_B }, // | 2--8 | Z 0 1 -
   [0x79] = { bitFunction, 7, REG_C }, // | 2--8 | Z 0 1 -
   [0x7A] = { bitFunction, 7, REG_D }, // | 2--8 | Z 0 1 -
   [0x7B] = { bitFunction, 7, REG_E }, // | 2--8 | Z 0 1 -
   [0x7C] = { bitFunction, 7, REG_H }, // | 2--8 | Z 0 1 -
   [0x7D] = { bitFunction, 7, REG_L }, // | 2--8 | Z 0 1 -
   [0x7F] = { bitFunction, 7, REG_A }, // | 2--8 | Z 0 1 -
   [0x46] = { bitFunction, 0, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x4E] = { bitFunction, 1, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x56] = { bitFunction, 2, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x5E] = { bitFunction, 3, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x66] = { bitFunction, 4, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x6E] = { bitFunction, 5, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x76] = { bitFunction, 6, MEM_REG_HL }, // | 2--16 | Z 0 1 -
   [0x7E] = { bitFunction, 7, MEM_REG_HL }, // | 2--16 | Z 0 1 -

   

  // Reset bit (RES) instruction 
   [0x80] = { resFunction, 0, REG_B }, // | 2--8 | - - - -
   [0x81] = { resFunction, 0, REG_C }, // | 2--8 | - - - -
   [0x82] = { resFunction, 0, REG_D }, // | 2--8 | - - - -
   [0x83] = { resFunction, 0, REG_E }, // | 2--8 | - - - -
   [0x84] = { resFunction, 0, REG_H }, // | 2--8 | - - - -
   [0x85] = { resFunction, 0, REG_L }, // | 2--8 | - - - -
   [0x87] = { resFunction, 0, REG_A }, // | 2--8 | - - - -
   [0x88] = { resFunction, 1, REG_B }, // | 2--8 | - - - -
   [0x89] = { resFunction, 1, REG_C }, // | 2--8 | - - - -
   [0x8A] = { resFunction, 1, REG_D }, // | 2--8 | - - - -
   [0x8B] = { resFunction, 1, REG_E }, // | 2--8 | - - - -
   [0x8C] = { resFunction, 1, REG_H }, // | 2--8 | - - - -
   [0x8D] = { resFunction, 1, REG_L }, // | 2--8 | - - - -
   [0x8F] = { resFunction, 1, REG_A }, // | 2--8 | - - - -
   [0x90] = { resFunction, 2, REG_B }, // | 2--8 | - - - -
   [0x91] = { resFunction, 2, REG_C }, // | 2--8 | - - - -
   [0x92] = { resFunction, 2, REG_D }, // | 2--8 | - - - -
   [0x93] = { resFunction, 2, REG_E }, // | 2--8 | - - - -
   [0x94] = { resFunction, 2, REG_H }, // | 2--8 | - - - -
   [0x95] = { resFunction, 2, REG_L }, // | 2--8 | - - - -
   [0x97] = { resFunction, 2, REG_A }, // | 2--8 | - - - -
   [0x98] = { resFunction, 3, REG_B }, // | 2--8 | - - - -
   [0x99] = { resFunction, 3, REG_C }, // | 2--8 | - - - -
   [0x9A] = { resFunction, 3, REG_D }, // | 2--8 | - - - -
   [0x9B] = { resFunction, 3, REG_E }, // | 2--8 | - - - -
   [0x9C] = { resFunction, 3, REG_H }, // | 2--8 | - - - -
   [0x9D] = { resFunction, 3, REG_L }, // | 2--8 | - - - -
   [0x9F] = { resFunction, 3, REG_A }, // | 2--8 | - - - -
   [0xA0] = { resFunction, 4, REG_B }, // | 2--8 | - - - -
   [0xA1] = { resFunction, 4, REG_C }, // | 2--8 | - - - -
   [0xA2] = { resFunction, 4, REG_D }, // | 2--8 | - - - -
   [0xA3] = { resFunction, 4, REG_E }, // | 2--8 | - - - -
   [0xA4] = { resFunction, 4, REG_H }, // | 2--8 | - - - -
   [0xA5] = { resFunction, 4, REG_L }, // | 2--8 | - - - -
   [0xA7] = { resFunction, 4, REG_A }, // | 2--8 | - - - -
   [0xA8] = { resFunction, 5, REG_B }, // | 2--8 | - - - -
   [0xA9] = { resFunction, 5, REG_C }, // | 2--8 | - - - -
   [0xAA] = { resFunction, 5, REG_D }, // | 2--8 | - - - -
   [0xAB] = { resFunction, 5, REG_E }, // | 2--8 | - - - -
   [0xAC] = { resFunction, 5, REG_H }, // | 2--8 | - - - -
   [0xAD] = { resFunction, 5, REG_L }, // | 2--8 | - - - -
   [0xAF] = { resFunction, 5, REG_A }, // | 2--8 | - - - -
   [0xB0] = { resFunction, 6, REG_B }, // | 2--8 | - - - -
   [0xB1] = { resFunction, 6, REG_C }, // | 2--8 | - - - -
   [0xB2] = { resFunction, 6, REG_D }, // | 2--8 | - - - -
   [0xB3] = { resFunction, 6, REG_E }, // | 2--8 | - - - -
   [0xB4] = { resFunction, 6, REG_H }, // | 2--8 | - - - -
   [0xB5] = { resFunction, 6, REG_L }, // | 2--8 | - - - -
   [0xB7] = { resFunction, 6, REG_A }, // | 2--8 | - - - -
   [0xB8] = { resFunction, 7, REG_B }, // | 2--8 | - - - -
   [0xB9] = { resFunction, 7, REG_C }, // | 2--8 | - - - -
   [0xBA] = { resFunction, 7, REG_D }, // | 2--8 | - - - -
   [0xBB] = { resFunction, 7, REG_E }, // | 2--8 | - - - -
   [0xBC] = { resFunction, 7, REG_H }, // | 2--8 | - - - -
   [0xBD] = { resFunction, 7, REG_L }, // | 2--8 | - - - -
   [0xBF] = { resFunction, 7, REG_A }, // | 2--8 | - - - -
   [0x86] = { resFunction, 0, MEM_REG_HL }, // | 2--16 | - - - -
   [0x8E] = { resFunction, 1, MEM_REG_HL }, // | 2--16 | - - - -
   [0x96] = { resFunction, 2, MEM_REG_HL }, // | 2--16 | - - - -
   [0x9E] = { resFunction, 3, MEM_REG_HL }, // | 2--16 | - - - -
   [0xA6] = { resFunction, 4, MEM_REG_HL }, // | 2--16 | - - - -
   [0xAE] = { resFunction, 5, MEM_REG_HL }, // | 2--16 | - - - -
   [0xB6] = { resFunction, 6, MEM_REG_HL }, // | 2--16 | - - - -
   [0xBE] = { resFunction, 7, MEM_REG_HL }, // | 2--16 | - - - -
   
   
 

  // Set bit (SET) instruction 
   [0xC0] = { setFunction, 0, REG_B }, // | 2--8 | - - - -
   [0xC1] = { setFunction, 0, REG_C }, // | 2--8 | - - - -
   [0xC2] = { setFunction, 0, REG_D }, // | 2--8 | - - - -
   [0xC3] = { setFunction, 0, REG_E }, // | 2--8 | - - - -
   [0xC4] = { setFunction, 0, REG_H }, // | 2--8 | - - - -
   [0xC5] = { setFunction, 0, REG_L }, // | 2--8 | - - - -
   [0xC7] = { setFunction, 0, REG_A }, // | 2--8 | - - - -
   [0xC8] = { setFunction, 1, REG_B }, // | 2--8 | - - - -
   [0xC9] = { setFunction, 1, REG_C }, // | 2--8 | - - - -
   [0xCA] = { setFunction, 1, REG_D }, // | 2--8 | - - - -
   [0xCB] = { setFunction, 1, REG_E }, // | 2--8 | - - - -
   [0xCC] = { setFunction, 1, REG_H }, // | 2--8 | - - - -
   [0xCD] = { setFunction, 1, REG_L }, // | 2--8 | - - - -
   [0xCF] = { setFunction, 1, REG_A }, // | 2--8 | - - - -
   [0xD0] = { setFunction, 2, REG_B }, // | 2--8 | - - - -
   [0xD1] = { setFunction, 2, REG_C }, // | 2--8 | - - - -
   [0xD2] = { setFunction, 2, REG_D }, // | 2--8 | - - - -
   [0xD3] = { setFunction, 2, REG_E }, // | 2--8 | - - - -
   [0xD4] = { setFunction, 2, REG_H }, // | 2--8 | - - - -
   [0xD5] = { setFunction, 2, REG_L }, // | 2--8 | - - - -
   [0xD7] = { setFunction, 2, REG_A }, // | 2--8 | - - - -
   [0xD8] = { setFunction, 3, REG_B }, // | 2--8 | - - - -
   [0xD9] = { setFunction, 3, REG_C }, // | 2--8 | - - - -
   [0xDA] = { setFunction, 3, REG_D }, // | 2--8 | - - - -
   [0xDB] = { setFunction, 3, REG_E }, // | 2--8 | - - - -
   [0xDC] = { setFunction, 3, REG_H }, // | 2--8 | - - - -
   [0xDD] = { setFunction, 3, REG_L }, // | 2--8 | - - - -
   [0xDF] = { setFunction, 3, REG_A }, // | 2--8 | - - - -
   [0xE0] = { setFunction, 4, REG_B }, // | 2--8 | - - - -
   [0xE1] = { setFunction, 4, REG_C }, // | 2--8 | - - - -
   [0xE2] = { setFunction, 4, REG_D }, // | 2--8 | - - - -
   [0xE3] = { setFunction, 4, REG_E }, // | 2--8 | - - - -
   [0xE4] = { setFunction, 4, REG_H }, // | 2--8 | - - - -
   [0xE5] = { setFunction, 4, REG_L }, // | 2--8 | - - - -
   [0xE7] = { setFunction, 4, REG_A }, // | 2--8 | - - - -
   [0xE8] = { setFunction, 5, REG_B }, // | 2--8 | - - - -
   [0xE9] = { setFunction, 5, REG_C }, // | 2--8 | - - - -
   [0xEA] = { setFunction, 5, REG_D }, // | 2--8 | - - - -
   [0xEB] = { setFunction, 5, REG_E }, // | 2--8 | - - - -
   [0xEC] = { setFunction, 5, REG_H }, // | 2--8 | - - - -
   [0xED] = { setFunction, 5, REG_L }, // | 2--8 | - - - -
   [0xEF] = { setFunction, 5, REG_A }, // | 2--8 | - - - -
   [0xF0] = { setFunction, 6, REG_B }, // | 2--8 | - - - -
   [0xF1] = { setFunction, 6, REG_C }, // | 2--8 | - - - -
   [0xF2] = { setFunction, 6, REG_D }, // | 2--8 | - - - -
   [0xF3] = { setFunction, 6, REG_E }, // | 2--8 | - - - -
   [0xF4] = { setFunction, 6, REG_H }, // | 2--8 | - - - -
   [0xF5] = { setFunction, 6, REG_L }, // | 2--8 | - - - -
   [0xF7] = { setFunction, 6, REG_A }, // | 2--8 | - - - -
   [0xF8] = { setFunction, 7, REG_B }, // | 2--8 | - - - -
   [0xF9] = { setFunction, 7, REG_C }, // | 2--8 | - - - -
   [0xFA] = { setFunction, 7, REG_D }, // | 2--8 | - - - -
   [0xFB] = { setFunction, 7, REG_E }, // | 2--8 | - - - -
   [0xFC] = { setFunction, 7, REG_H }, // | 2--8 | - - - -
   [0xFD] = { setFunction, 7, REG_L }, // | 2--8 | - - - -
   [0xFF] = { setFunction, 7, REG_A }, // | 2--8 | - - - -
   [0xC6] = { setFunction, 0, MEM_REG_HL }, // | 2--16 | - - - -
   [0xCE] = { setFunction, 1, MEM_REG_HL }, // | 2--16 | - - - -
   [0xD6] = { setFunction, 2, MEM_REG_HL }, // | 2--16 | - - - -
   [0xDE] = { setFunction, 3, MEM_REG_HL }, // | 2--16 | - - - -
   [0xE6] = { setFunction, 4, MEM_REG_HL }, // | 2--16 | - - - -
   [0xEE] = { setFunction, 5, MEM_REG_HL }, // | 2--16 | - - - -
   [0xF6] = { setFunction, 6, MEM_REG_HL }, // | 2--16 | - - - -
   [0xFE] = { setFunction, 7, MEM_REG_HL }, // | 2--16 | - - - -
};





const char *str_normal_inst[0x100] = {
    // Load (LD) instructions
   [0x40] = " ldFunction, REG_B, REG_B ", // | 1--4 | - - - -
   [0x41] = " ldFunction, REG_B, REG_C ", // | 1--4 | - - - -
   [0x42] = " ldFunction, REG_B, REG_D ", // | 1--4 | - - - -
   [0x43] = " ldFunction, REG_B, REG_E ", // | 1--4 | - - - -
   [0x44] = " ldFunction, REG_B, REG_H ", // | 1--4 | - - - -
   [0x45] = " ldFunction, REG_B, REG_L ", // | 1--4 | - - - -
   [0x47] = " ldFunction, REG_B, REG_A ", // | 1--4 | - - - -
   [0x48] = " ldFunction, REG_C, REG_B ", // | 1--4 | - - - -
   [0x49] = " ldFunction, REG_C, REG_C ", // | 1--4 | - - - -
   [0x4A] = " ldFunction, REG_C, REG_D ", // | 1--4 | - - - -
   [0x4B] = " ldFunction, REG_C, REG_E ", // | 1--4 | - - - -
   [0x4C] = " ldFunction, REG_C, REG_H ", // | 1--4 | - - - -
   [0x4D] = " ldFunction, REG_C, REG_L ", // | 1--4 | - - - -
   [0x4F] = " ldFunction, REG_C, REG_A ", // | 1--4 | - - - -
   [0x50] = " ldFunction, REG_D, REG_B ", // | 1--4 | - - - -
   [0x51] = " ldFunction, REG_D, REG_C ", // | 1--4 | - - - -
   [0x52] = " ldFunction, REG_D, REG_D ", // | 1--4 | - - - -
   [0x53] = " ldFunction, REG_D, REG_E ", // | 1--4 | - - - -
   [0x54] = " ldFunction, REG_D, REG_H ", // | 1--4 | - - - -
   [0x55] = " ldFunction, REG_D, REG_L ", // | 1--4 | - - - -
   [0x57] = " ldFunction, REG_D, REG_A ", // | 1--4 | - - - -
   [0x58] = " ldFunction, REG_E, REG_B ", // | 1--4 | - - - -
   [0x59] = " ldFunction, REG_E, REG_C ", // | 1--4 | - - - -
   [0x5A] = " ldFunction, REG_E, REG_D ", // | 1--4 | - - - -
   [0x5B] = " ldFunction, REG_E, REG_E ", // | 1--4 | - - - -
   [0x5C] = " ldFunction, REG_E, REG_H ", // | 1--4 | - - - -
   [0x5D] = " ldFunction, REG_E, REG_L ", // | 1--4 | - - - -
   [0x5F] = " ldFunction, REG_E, REG_A ", // | 1--4 | - - - -
   [0x60] = " ldFunction, REG_H, REG_B ", // | 1--4 | - - - -
   [0x61] = " ldFunction, REG_H, REG_C ", // | 1--4 | - - - -
   [0x62] = " ldFunction, REG_H, REG_D ", // | 1--4 | - - - -
   [0x63] = " ldFunction, REG_H, REG_E ", // | 1--4 | - - - -
   [0x64] = " ldFunction, REG_H, REG_H ", // | 1--4 | - - - -
   [0x65] = " ldFunction, REG_H, REG_L ", // | 1--4 | - - - -
   [0x67] = " ldFunction, REG_H, REG_A ", // | 1--4 | - - - -
   [0x68] = " ldFunction, REG_L, REG_B ", // | 1--4 | - - - -
   [0x69] = " ldFunction, REG_L, REG_C ", // | 1--4 | - - - -
   [0x6A] = " ldFunction, REG_L, REG_D ", // | 1--4 | - - - -
   [0x6B] = " ldFunction, REG_L, REG_E ", // | 1--4 | - - - -
   [0x6C] = " ldFunction, REG_L, REG_H ", // | 1--4 | - - - -
   [0x6D] = " ldFunction, REG_L, REG_L ", // | 1--4 | - - - -
   [0x6F] = " ldFunction, REG_L, REG_A ", // | 1--4 | - - - -
   [0x78] = " ldFunction, REG_A, REG_B ", // | 1--4 | - - - -
   [0x79] = " ldFunction, REG_A, REG_C ", // | 1--4 | - - - -
   [0x7A] = " ldFunction, REG_A, REG_D ", // | 1--4 | - - - -
   [0x7B] = " ldFunction, REG_A, REG_E ", // | 1--4 | - - - -
   [0x7C] = " ldFunction, REG_A, REG_H ", // | 1--4 | - - - -
   [0x7D] = " ldFunction, REG_A, REG_L ", // | 1--4 | - - - -
   [0x7F] = " ldFunction, REG_A, REG_A ", // | 1--4 | - - - -
   [0xF9] = " ldFunction, REG_SP, REG_HL ", // | 1--8 | - - - -

   [0x46] = " ldFunction, REG_B, MEM_REG_HL ", // | 1--8 | - - - -
   [0x4E] = " ldFunction, REG_C, MEM_REG_HL ", // | 1--8 | - - - -
   [0x56] = " ldFunction, REG_D, MEM_REG_HL ", // | 1--8 | - - - -
   [0x5E] = " ldFunction, REG_E, MEM_REG_HL ", // | 1--8 | - - - -
   [0x66] = " ldFunction, REG_H, MEM_REG_HL ", // | 1--8 | - - - -
   [0x6E] = " ldFunction, REG_L, MEM_REG_HL ", // | 1--8 | - - - -
   [0x7E] = " ldFunction, REG_A, MEM_REG_HL ", // | 1--8 | - - - -
   [0x0A] = " ldFunction, REG_A, MEM_REG_BC ", // | 1--8 | - - - -
   [0x1A] = " ldFunction, REG_A, MEM_REG_DE ", // | 1--8 | - - - -
   [0xFA] = " ldFunction, REG_A, MEM_IMM16 ", // | 3--16 | - - - -
   [0x2A] = " ldFunction, REG_A, MEM_REG_HL_PLUS ", // | 1--8 | - - - -
   [0x3A] = " ldFunction, REG_A, MEM_REG_HL_MINUS ", // | 1--8 | - - - -
   [0xF2] = " ldFunction, REG_A, MEM_REG_C ", // | 2--8 | - - - -
   [0xF0] = " ldFunction, REG_A, MEM_IMM8 ", // | 2--12 | - - - -


   [0x70] = " ldFunction, MEM_REG_HL, REG_B ", // | 1--8 | - - - -
   [0x71] = " ldFunction, MEM_REG_HL, REG_C ", // | 1--8 | - - - -
   [0x72] = " ldFunction, MEM_REG_HL, REG_D ", // | 1--8 | - - - -
   [0x73] = " ldFunction, MEM_REG_HL, REG_E ", // | 1--8 | - - - -
   [0x74] = " ldFunction, MEM_REG_HL, REG_H ", // | 1--8 | - - - -
   [0x75] = " ldFunction, MEM_REG_HL, REG_L ", // | 1--8 | - - - -
   [0x77] = " ldFunction, MEM_REG_HL, REG_A ", // | 1--8 | - - - -
   [0x36] = " ldFunction, MEM_REG_HL, IMM8 ", // | 2--12 | - - - -
   [0x02] = " ldFunction, MEM_REG_BC, REG_A ", // | 1--8 | - - - -
   [0x12] = " ldFunction, MEM_REG_DE, REG_A ", // | 1--8 | - - - -
   [0xE2] = " ldFunction, MEM_REG_C, REG_A ", // | 2--8 | - - - -
   [0xE0] = " ldFunction, MEM_IMM8, REG_A ", // | 2--12 | - - - -
   [0x22] = " ldFunction, MEM_REG_HL_PLUS, REG_A ", // | 1--8 | - - - -
   [0x32] = " ldFunction, MEM_REG_HL_MINUS, REG_A ", // | 1--8 | - - - -
   [0x08] = " ldFunction, MEM_IMM16, REG_SP ", // | 3--20 | - - - -
   [0xEA] = " ldFunction, MEM_IMM16, REG_A ", // | 3--16 | - - - -

   [0x3E] = " ldFunction, REG_A, IMM8 ", // | 2--8 | - - - -
   [0x06] = " ldFunction, REG_B, IMM8 ", // | 2--8 | - - - -
   [0x0E] = " ldFunction, REG_C, IMM8 ", // | 2--8 | - - - -
   [0x16] = " ldFunction, REG_D, IMM8 ", // | 2--8 | - - - -
   [0x1E] = " ldFunction, REG_E, IMM8 ", // | 2--8 | - - - -
   [0x26] = " ldFunction, REG_H, IMM8 ", // | 2--8 | - - - -
   [0x2E] = " ldFunction, REG_L, IMM8 ", // | 2--8 | - - - -


   [0x01] = " ldFunction, REG_BC, IMM16 ", // | 3--12 | - - - -
   [0x11] = " ldFunction, REG_DE, IMM16 ", // | 3--12 | - - - -
   [0x21] = " ldFunction, REG_HL, IMM16 ", // | 3--12 | - - - -
   [0x31] = " ldFunction, REG_SP, IMM16 ", // | 3--12 | - - - -

   [0xF8] = " ldFunction, REG_HL, REG_SP_PLUS_SIMM8", // | 2--12 | 0 0 H C



   // Increment (INC) instructions
   [0x04] = " incFunction, REG_B , EMPTY ", // | 1--4 | Z 0 H -
   [0x0C] = " incFunction, REG_C , EMPTY ", // | 1--4 | Z 0 H -
   [0x14] = " incFunction, REG_D , EMPTY ", // | 1--4 | Z 0 H -
   [0x1C] = " incFunction, REG_E , EMPTY ", // | 1--4 | Z 0 H -
   [0x24] = " incFunction, REG_H , EMPTY ", // | 1--4 | Z 0 H -
   [0x2C] = " incFunction, REG_L , EMPTY ", // | 1--4 | Z 0 H -
   [0x3C] = " incFunction, REG_A , EMPTY ", // | 1--4 | Z 0 H -
   [0x34] = " incFunction, MEM_REG_HL, EMPTY ", // | 1--12 | Z 0 H -

   [0x03] = " incFunction, REG_BC, EMPTY ", // | 1--8 | - - - -
   [0x13] = " incFunction, REG_DE, EMPTY ", // | 1--8 | - - - -
   [0x23] = " incFunction, REG_HL, EMPTY ", // | 1--8 | - - - -
   [0x33] = " incFunction, REG_SP, EMPTY ", // | 1--8 | - - - -


   // Decrement (DEC) instructions
   [0x05] = " decFunction, REG_B  , EMPTY ", // | 1--4 | Z 1 H -
   [0x0D] = " decFunction, REG_C  , EMPTY ", // | 1--4 | Z 1 H -
   [0x15] = " decFunction, REG_D  , EMPTY ", // | 1--4 | Z 1 H -
   [0x1D] = " decFunction, REG_E  , EMPTY ", // | 1--4 | Z 1 H -
   [0x25] = " decFunction, REG_H  , EMPTY ", // | 1--4 | Z 1 H -
   [0x2D] = " decFunction, REG_L  , EMPTY ", // | 1--4 | Z 1 H -
   [0x3D] = " decFunction, REG_A  , EMPTY ", // | 1--4 | Z 1 H -
   [0x35] = " decFunction, MEM_REG_HL, EMPTY ", // | 1--12 | Z 1 H -

   [0x0B] = " decFunction, REG_BC , EMPTY ", // | 1--8 | - - - -
   [0x1B] = " decFunction, REG_DE , EMPTY ", // | 1--8 | - - - -
   [0x2B] = " decFunction, REG_HL , EMPTY ", // | 1--8 | - - - -
   [0x3B] = " decFunction, REG_SP , EMPTY ", // | 1--8 | - - - -


   // Add (ADD) instructions
   [0x80] = " addFunction, REG_A, REG_B ", // | 1--4 | Z 0 H C
   [0x81] = " addFunction, REG_A, REG_C ", // | 1--4 | Z 0 H C
   [0x82] = " addFunction, REG_A, REG_D ", // | 1--4 | Z 0 H C
   [0x83] = " addFunction, REG_A, REG_E ", // | 1--4 | Z 0 H C
   [0x84] = " addFunction, REG_A, REG_H ", // | 1--4 | Z 0 H C
   [0x85] = " addFunction, REG_A, REG_L ", // | 1--4 | Z 0 H C
   [0x87] = " addFunction, REG_A, REG_A ", // | 1--4 | Z 0 H C
   [0xC6] = " addFunction, REG_A, IMM8  ", // | 2--8 | Z 0 H C
   [0x86] = " addFunction, REG_A, MEM_REG_HL", // | 1--8 | Z 0 H C

   [0x09] = " addFunction, REG_HL, REG_BC ", // | 1--8 | - 0 H C
   [0x19] = " addFunction, REG_HL, REG_DE ", // | 1--8 | - 0 H C
   [0x29] = " addFunction, REG_HL, REG_HL ", // | 1--8 | - 0 H C
   [0x39] = " addFunction, REG_HL, REG_SP ", // | 1--8 | - 0 H C

   [0xE8] = " addFunction, REG_SP, SIMM8 ", // | 2--16 | 0 0 H C

   // Add with carry (ADC) instructions
   [0x88] = " adcFunction, REG_A, REG_B ", // | 1--4 | Z 0 H C
   [0x89] = " adcFunction, REG_A, REG_C ", // | 1--4 | Z 0 H C
   [0x8A] = " adcFunction, REG_A, REG_D ", // | 1--4 | Z 0 H C
   [0x8B] = " adcFunction, REG_A, REG_E ", // | 1--4 | Z 0 H C
   [0x8C] = " adcFunction, REG_A, REG_H ", // | 1--4 | Z 0 H C
   [0x8D] = " adcFunction, REG_A, REG_L ", // | 1--4 | Z 0 H C
   [0x8F] = " adcFunction, REG_A, REG_A ", // | 1--4 | Z 0 H C
   [0xCE] = " adcFunction, REG_A, IMM8 ", // | 2--8 | Z 0 H C
   [0x8E] = " adcFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 0 H C


   // Subtract (SUB) instructions
   [0x90] = " subFunction, REG_A, REG_B ", // | 1--4 | Z 1 H C
   [0x91] = " subFunction, REG_A, REG_C ", // | 1--4 | Z 1 H C
   [0x92] = " subFunction, REG_A, REG_D ", // | 1--4 | Z 1 H C
   [0x93] = " subFunction, REG_A, REG_E ", // | 1--4 | Z 1 H C
   [0x94] = " subFunction, REG_A, REG_H ", // | 1--4 | Z 1 H C
   [0x95] = " subFunction, REG_A, REG_L ", // | 1--4 | Z 1 H C
   [0x97] = " subFunction, REG_A, REG_A ", // | 1--4 | Z 1 H C
   [0xD6] = " subFunction, REG_A, IMM8 ", // | 2--8 | Z 1 H C
   [0x96] = " subFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 1 H C


   // Subtract with carry (SBC) instructions
   [0x98] = " sbcFunction, REG_A, REG_B ", // | 1--4 | Z 1 H C
   [0x99] = " sbcFunction, REG_A, REG_C ", // | 1--4 | Z 1 H C
   [0x9A] = " sbcFunction, REG_A, REG_D ", // | 1--4 | Z 1 H C
   [0x9B] = " sbcFunction, REG_A, REG_E ", // | 1--4 | Z 1 H C
   [0x9C] = " sbcFunction, REG_A, REG_H ", // | 1--4 | Z 1 H C
   [0x9D] = " sbcFunction, REG_A, REG_L ", // | 1--4 | Z 1 H C
   [0x9F] = " sbcFunction, REG_A, REG_A ", // | 1--4 | Z 1 H C
   [0xDE] = " sbcFunction, REG_A, IMM8 ", // | 2--8 | Z 1 H C
   [0x9E] = " sbcFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 1 H C




   // And (AND) instructions
   [0xA0] = " andFunction, REG_A, REG_B ", // | 1--4 | Z 0 1 0
   [0xA1] = " andFunction, REG_A, REG_C ", // | 1--4 | Z 0 1 0
   [0xA2] = " andFunction, REG_A, REG_D ", // | 1--4 | Z 0 1 0
   [0xA3] = " andFunction, REG_A, REG_E ", // | 1--4 | Z 0 1 0
   [0xA4] = " andFunction, REG_A, REG_H ", // | 1--4 | Z 0 1 0
   [0xA5] = " andFunction, REG_A, REG_L ", // | 1--4 | Z 0 1 0
   [0xA7] = " andFunction, REG_A, REG_A ", // | 1--4 | Z 0 1 0
   [0xE6] = " andFunction, REG_A, IMM8 ", // | 2--8 | Z 0 1 0
   [0xA6] = " andFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 0 1 0


   // Or (OR) instructions
   [0xB0] = " orFunction, REG_A, REG_B ", // | 1--4 | Z 0 0 0
   [0xB1] = " orFunction, REG_A, REG_C ", // | 1--4 | Z 0 0 0
   [0xB2] = " orFunction, REG_A, REG_D ", // | 1--4 | Z 0 0 0
   [0xB3] = " orFunction, REG_A, REG_E ", // | 1--4 | Z 0 0 0
   [0xB4] = " orFunction, REG_A, REG_H ", // | 1--4 | Z 0 0 0
   [0xB5] = " orFunction, REG_A, REG_L ", // | 1--4 | Z 0 0 0
   [0xB7] = " orFunction, REG_A, REG_A ", // | 1--4 | Z 0 0 0
   [0xF6] = " orFunction, REG_A, IMM8 ", // | 2--8 | Z 0 0 0
   [0xB6] = " orFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 0 0 0


   // Xor (XOR) instructions
   [0xA8] = " xorFunction, REG_A, REG_B ", // | 1--4 | Z 0 0 0
   [0xA9] = " xorFunction, REG_A, REG_C ", // | 1--4 | Z 0 0 0
   [0xAA] = " xorFunction, REG_A, REG_D ", // | 1--4 | Z 0 0 0
   [0xAB] = " xorFunction, REG_A, REG_E ", // | 1--4 | Z 0 0 0
   [0xAC] = " xorFunction, REG_A, REG_H ", // | 1--4 | Z 0 0 0
   [0xAD] = " xorFunction, REG_A, REG_L ", // | 1--4 | Z 0 0 0
   [0xAF] = " xorFunction, REG_A, REG_A ", // | 1--4 | Z 0 0 0
   [0xEE] = " xorFunction, REG_A, IMM8 ", // | 2--8 | Z 0 0 0
   [0xAE] = " xorFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 0 0 0

   // Compare (CP) instructions
   [0xB8] = " cpFunction, REG_A, REG_B ", // | 1--4 | Z 1 H C
   [0xB9] = " cpFunction, REG_A, REG_C ", // | 1--4 | Z 1 H C
   [0xBA] = " cpFunction, REG_A, REG_D ", // | 1--4 | Z 1 H C
   [0xBB] = " cpFunction, REG_A, REG_E ", // | 1--4 | Z 1 H C
   [0xBC] = " cpFunction, REG_A, REG_H ", // | 1--4 | Z 1 H C
   [0xBD] = " cpFunction, REG_A, REG_L ", // | 1--4 | Z 1 H C
   [0xBF] = " cpFunction, REG_A, REG_A ", // | 1--4 | Z 1 H C
   [0xFE] = " cpFunction, REG_A, IMM8 ", // | 2--8 | Z 1 H C
   [0xBE] = " cpFunction, REG_A, MEM_REG_HL ", // | 1--8 | Z 1 H C


   // Jump (JP) instructions
   [0xE9] = " jpFunction, MEM_REG_HL, EMPTY ", // | 1--4 | - - - -
   [0xC3] = " jpFunction, IMM16, EMPTY ", // | 3--16 | - - - -
   [0xC2] = " jpFunction, CON_NZ,IMM16 ", // | 3--16/12 | - - - -
   [0xCA] = " jpFunction, CON_Z,IMM16 ", // | 3--16/12 | - - - -
   [0xD2] = " jpFunction, CON_NC,IMM16 ", // | 3--16/12 | - - - -
   [0xDA] = " jpFunction, CON_C,IMM16 ", // | 3--16/12 | - - - -


   // Relative jump (JR) instructions
   [0x18] = " jrFunction, SIMM8, EMPTY ", // | 2--12 | - - - -
   [0x38] = " jrFunction, CON_C, SIMM8 ", // | 2--12/8 | - - - -
   [0x20] = " jrFunction, CON_NZ, SIMM8 ", // | 2--12/8 | - - - -
   [0x28] = " jrFunction, CON_Z, SIMM8 ", // | 2--12/8 | - - - -
   [0x30] = " jrFunction, CON_NC, SIMM8 ", // | 2--12/8 | - - - -



   // Push to stack (PUSH) instructions
   [0xC5] = " pushFunction, REG_BC, EMPTY ", // | 1--16 | - - - -
   [0xD5] = " pushFunction, REG_DE, EMPTY ", // | 1--16 | - - - -
   [0xE5] = " pushFunction, REG_HL, EMPTY ", // | 1--16 | - - - -
   [0xF5] = " pushFunction, REG_AF, EMPTY ", // | 1--16 | - - - -


   // Pop from stack (POP) instructions
   [0xC1] = " popFunction, REG_BC, EMPTY ", // | 1--12 | - - - -
   [0xD1] = " popFunction, REG_DE, EMPTY ", // | 1--12 | - - - -
   [0xE1] = " popFunction, REG_HL, EMPTY ", // | 1--12 | - - - -
   [0xF1] = " popFunction, REG_AF, EMPTY ", // | 1--12 | Z N H C


   // Call a routine (CALL) instructions
   [0xCD] = " callFunction, IMM16, EMPTY ", // | 3--24 | - - - -
   [0xC4] = " callFunction, CON_NZ,IMM16 ", // | 3--24/12 | - - - -
   [0xCC] = " callFunction, CON_Z,IMM16 ", // | 3--24/12 | - - - -
   [0xD4] = " callFunction, CON_NC,IMM16 ", // | 3--24/12 | - - - -
   [0xDC] = " callFunction, CON_C,IMM16 ", // | 3--24/12 | - - - -



   // Reture from a routine (RET) instructions
   [0xC0] = " retFunction, CON_NZ, EMPTY ", // | 1--20/8 | - - - -
   [0xC8] = " retFunction, CON_Z , EMPTY ", // | 1--20/8 | - - - -
   [0xD0] = " retFunction, CON_NC, EMPTY ", // | 1--20/8 | - - - -
   [0xD8] = " retFunction, CON_C , EMPTY ", // | 1--20/8 | - - - -
   [0xC9] = " retFunction, EMPTY, EMPTY ", // | 1--16 | - - - -
   [0xD9] = " retiFunction, EMPTY, EMPTY ", // | 1--16 | - - - -


   // Call Reset Routines (RST) instructions
   [0xC7] = " rstFunction, 0x00, EMPTY", // | 1--16 | - - - -
   [0xCF] = " rstFunction, 0x08, EMPTY", // | 1--16 | - - - -
   [0xD7] = " rstFunction, 0x10, EMPTY", // | 1--16 | - - - -
   [0xDF] = " rstFunction, 0x18, EMPTY", // | 1--16 | - - - -
   [0xE7] = " rstFunction, 0x20, EMPTY", // | 1--16 | - - - -
   [0xEF] = " rstFunction, 0x28, EMPTY", // | 1--16 | - - - -
   [0xF7] = " rstFunction, 0x30, EMPTY", // | 1--16 | - - - -
   [0xFF] = " rstFunction, 0x38, EMPTY", // | 1--16 | - - - -


  
   // Decimal Adjust for REG_A instruction
   [0x27] = " daaFunction, EMPTY, EMPTY ", // | 1--4 | Z - 0 C

   // REG_A XOR 0xFF instruction
   [0x2F] = " cplFunction, EMPTY, EMPTY ", // | 1--4 | - 1 1 -

   // Set carry flag to 1 instruction
   [0x37] = " scfFunction, EMPTY, EMPTY ", // | 1--4 | - 0 0 1

   // carry XOR 0xFF instruction
   [0x3F] = " ccfFunction, EMPTY, EMPTY ", // | 1--4 | - 0 0 C
   
  
   //Enable (EI) and disable (DI) interrupts instructions 
   [0xF3] = " diFunction, EMPTY, EMPTY ", // | 1--4 | - - - -
   [0xFB] = " eiFunction, EMPTY, EMPTY ", // | 1--4 | - - - -
  
   // No operation instruction
   [0x00] = " nopFunction, EMPTY, EMPTY ", // | 1--4 | - - - -
   // Stop instruction
   [0x10] = " stopFunction, EMPTY, EMPTY ", // | 2--4 | - - - -
   // Halt instruction
   [0x76] = " haltFunction, EMPTY, EMPTY ", // | 1--4 | - - - -
   
  
   // Rotate REG_A left through carry (RLA) instruction
   [0x17] = " rlaFunction, EMPTY, EMPTY ", // | 1--4 | 0 0 0 C
   // Rotate REG_A right through carry (RRA) instruction
   [0x1F] = " rraFunction, EMPTY, EMPTY ", // | 1--4 | 0 0 0 C
   // Rotate REG_A left (RLCA) instruction
   [0x07] = " rlcaFunction, EMPTY, EMPTY", // | 1--4 | 0 0 0 C
   // Rotate REG_A right (RRCA) instruction
   [0x0F] = " rrcaFunction, EMPTY, EMPTY", // | 1--4 | 0 0 0 C
};
   
// CB Instructions         
const char *str_cb_inst[0x100] = {
   // Rotate left (RLC) instruction
   [0x00] = " rlcFunction, REG_B, EMPTY ", // | 2--8 | Z 0 0 C
   [0x01] = " rlcFunction, REG_C, EMPTY ", // | 2--8 | Z 0 0 C
   [0x02] = " rlcFunction, REG_D, EMPTY ", // | 2--8 | Z 0 0 C
   [0x03] = " rlcFunction, REG_E, EMPTY ", // | 2--8 | Z 0 0 C
   [0x04] = " rlcFunction, REG_H, EMPTY ", // | 2--8 | Z 0 0 C
   [0x05] = " rlcFunction, REG_L, EMPTY ", // | 2--8 | Z 0 0 C
   [0x07] = " rlcFunction, REG_A, EMPTY ", // | 2--8 | Z 0 0 C
   [0x06] = " rlcFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 C


   // Rotate right (RRC) instruction
   [0x08] = " rrcFunction, REG_B, EMPTY ", // | 2--8 | Z 0 0 C
   [0x09] = " rrcFunction, REG_C, EMPTY ", // | 2--8 | Z 0 0 C
   [0x0A] = " rrcFunction, REG_D, EMPTY ", // | 2--8 | Z 0 0 C
   [0x0B] = " rrcFunction, REG_E, EMPTY ", // | 2--8 | Z 0 0 C
   [0x0C] = " rrcFunction, REG_H, EMPTY ", // | 2--8 | Z 0 0 C
   [0x0D] = " rrcFunction, REG_L, EMPTY ", // | 2--8 | Z 0 0 C
   [0x0F] = " rrcFunction, REG_A, EMPTY ", // | 2--8 | Z 0 0 C
   [0x0E] = " rrcFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 C
   
   
   // Rotate left through carry (RL) instruction
   [0x10] = " rlFunction, REG_B, EMPTY ", // | 2--8 | Z 0 0 C
   [0x11] = " rlFunction, REG_C, EMPTY ", // | 2--8 | Z 0 0 C
   [0x12] = " rlFunction, REG_D, EMPTY ", // | 2--8 | Z 0 0 C
   [0x13] = " rlFunction, REG_E, EMPTY ", // | 2--8 | Z 0 0 C
   [0x14] = " rlFunction, REG_H, EMPTY ", // | 2--8 | Z 0 0 C
   [0x15] = " rlFunction, REG_L, EMPTY ", // | 2--8 | Z 0 0 C
   [0x17] = " rlFunction, REG_A, EMPTY ", // | 2--8 | Z 0 0 C
   [0x16] = " rlFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 C

   // Rotate right through carry (RR) instruction
   [0x18] = " rrFunction, REG_B, EMPTY ", // | 2--8 | Z 0 0 C
   [0x19] = " rrFunction, REG_C, EMPTY ", // | 2--8 | Z 0 0 C
   [0x1A] = " rrFunction, REG_D, EMPTY ", // | 2--8 | Z 0 0 C
   [0x1B] = " rrFunction, REG_E, EMPTY ", // | 2--8 | Z 0 0 C
   [0x1C] = " rrFunction, REG_H, EMPTY ", // | 2--8 | Z 0 0 C
   [0x1D] = " rrFunction, REG_L, EMPTY ", // | 2--8 | Z 0 0 C
   [0x1F] = " rrFunction, REG_A, EMPTY ", // | 2--8 | Z 0 0 C
   [0x1E] = " rrFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 C
   
  // Shift left arithmetically (SLA) instruction 
   [0x20] = " slaFunction, REG_B, EMPTY", // | 2--8 | Z 0 0 C
   [0x21] = " slaFunction, REG_C, EMPTY", // | 2--8 | Z 0 0 C
   [0x22] = " slaFunction, REG_D, EMPTY", // | 2--8 | Z 0 0 C
   [0x23] = " slaFunction, REG_E, EMPTY", // | 2--8 | Z 0 0 C
   [0x24] = " slaFunction, REG_H, EMPTY", // | 2--8 | Z 0 0 C
   [0x25] = " slaFunction, REG_L, EMPTY", // | 2--8 | Z 0 0 C
   [0x27] = " slaFunction, REG_A, EMPTY", // | 2--8 | Z 0 0 C
   [0x26] = " slaFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 C

  // Shift right arithmetically (SRA) instruction 
   [0x28] = " sraFunction, REG_B, EMPTY", // | 2--8 | Z 0 0 0
   [0x29] = " sraFunction, REG_C, EMPTY", // | 2--8 | Z 0 0 0
   [0x2A] = " sraFunction, REG_D, EMPTY", // | 2--8 | Z 0 0 0
   [0x2B] = " sraFunction, REG_E, EMPTY", // | 2--8 | Z 0 0 0
   [0x2C] = " sraFunction, REG_H, EMPTY", // | 2--8 | Z 0 0 0
   [0x2D] = " sraFunction, REG_L, EMPTY", // | 2--8 | Z 0 0 0
   [0x2F] = " sraFunction, REG_A, EMPTY", // | 2--8 | Z 0 0 0
   [0x2E] = " sraFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 0
   
   

  // Shift right logically (SRL) instruction 
   [0x38] = " srlFunction, REG_B, EMPTY", // | 2--8 | Z 0 0 C
   [0x39] = " srlFunction, REG_C, EMPTY", // | 2--8 | Z 0 0 C
   [0x3A] = " srlFunction, REG_D, EMPTY", // | 2--8 | Z 0 0 C
   [0x3B] = " srlFunction, REG_E, EMPTY", // | 2--8 | Z 0 0 C
   [0x3C] = " srlFunction, REG_H, EMPTY", // | 2--8 | Z 0 0 C
   [0x3D] = " srlFunction, REG_L, EMPTY", // | 2--8 | Z 0 0 C
   [0x3F] = " srlFunction, REG_A, EMPTY", // | 2--8 | Z 0 0 C
   [0x3E] = " srlFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 C



   // Swap between high and low nibbles (SWAP) instruction
   [0x30] = " swapFunction, REG_B, EMPTY ", // | 2--8 | Z 0 0 0
   [0x31] = " swapFunction, REG_C, EMPTY ", // | 2--8 | Z 0 0 0
   [0x32] = " swapFunction, REG_D, EMPTY ", // | 2--8 | Z 0 0 0
   [0x33] = " swapFunction, REG_E, EMPTY ", // | 2--8 | Z 0 0 0
   [0x34] = " swapFunction, REG_H, EMPTY ", // | 2--8 | Z 0 0 0
   [0x35] = " swapFunction, REG_L, EMPTY ", // | 2--8 | Z 0 0 0
   [0x37] = " swapFunction, REG_A, EMPTY ", // | 2--8 | Z 0 0 0
   [0x36] = " swapFunction, MEM_REG_HL, EMPTY ", // | 2--16 | Z 0 0 0




   
  // Check bit status (BIT) instruction 
   [0x40] = " bitFunction, 0, REG_B ", // | 2--8 | Z 0 1 -
   [0x41] = " bitFunction, 0, REG_C ", // | 2--8 | Z 0 1 -
   [0x42] = " bitFunction, 0, REG_D ", // | 2--8 | Z 0 1 -
   [0x43] = " bitFunction, 0, REG_E ", // | 2--8 | Z 0 1 -
   [0x44] = " bitFunction, 0, REG_H ", // | 2--8 | Z 0 1 -
   [0x45] = " bitFunction, 0, REG_L ", // | 2--8 | Z 0 1 -
   [0x47] = " bitFunction, 0, REG_A ", // | 2--8 | Z 0 1 -
   [0x48] = " bitFunction, 1, REG_B ", // | 2--8 | Z 0 1 -
   [0x49] = " bitFunction, 1, REG_C ", // | 2--8 | Z 0 1 -
   [0x4A] = " bitFunction, 1, REG_D ", // | 2--8 | Z 0 1 -
   [0x4B] = " bitFunction, 1, REG_E ", // | 2--8 | Z 0 1 -
   [0x4C] = " bitFunction, 1, REG_H ", // | 2--8 | Z 0 1 -
   [0x4D] = " bitFunction, 1, REG_L ", // | 2--8 | Z 0 1 -
   [0x4F] = " bitFunction, 1, REG_A ", // | 2--8 | Z 0 1 -
   [0x50] = " bitFunction, 2, REG_B ", // | 2--8 | Z 0 1 -
   [0x51] = " bitFunction, 2, REG_C ", // | 2--8 | Z 0 1 -
   [0x52] = " bitFunction, 2, REG_D ", // | 2--8 | Z 0 1 -
   [0x53] = " bitFunction, 2, REG_E ", // | 2--8 | Z 0 1 -
   [0x54] = " bitFunction, 2, REG_H ", // | 2--8 | Z 0 1 -
   [0x55] = " bitFunction, 2, REG_L ", // | 2--8 | Z 0 1 -
   [0x57] = " bitFunction, 2, REG_A ", // | 2--8 | Z 0 1 -
   [0x58] = " bitFunction, 3, REG_B ", // | 2--8 | Z 0 1 -
   [0x59] = " bitFunction, 3, REG_C ", // | 2--8 | Z 0 1 -
   [0x5A] = " bitFunction, 3, REG_D ", // | 2--8 | Z 0 1 -
   [0x5B] = " bitFunction, 3, REG_E ", // | 2--8 | Z 0 1 -
   [0x5C] = " bitFunction, 3, REG_H ", // | 2--8 | Z 0 1 -
   [0x5D] = " bitFunction, 3, REG_L ", // | 2--8 | Z 0 1 -
   [0x5F] = " bitFunction, 3, REG_A ", // | 2--8 | Z 0 1 -
   [0x60] = " bitFunction, 4, REG_B ", // | 2--8 | Z 0 1 -
   [0x61] = " bitFunction, 4, REG_C ", // | 2--8 | Z 0 1 -
   [0x62] = " bitFunction, 4, REG_D ", // | 2--8 | Z 0 1 -
   [0x63] = " bitFunction, 4, REG_E ", // | 2--8 | Z 0 1 -
   [0x64] = " bitFunction, 4, REG_H ", // | 2--8 | Z 0 1 -
   [0x65] = " bitFunction, 4, REG_L ", // | 2--8 | Z 0 1 -
   [0x67] = " bitFunction, 4, REG_A ", // | 2--8 | Z 0 1 -
   [0x68] = " bitFunction, 5, REG_B ", // | 2--8 | Z 0 1 -
   [0x69] = " bitFunction, 5, REG_C ", // | 2--8 | Z 0 1 -
   [0x6A] = " bitFunction, 5, REG_D ", // | 2--8 | Z 0 1 -
   [0x6B] = " bitFunction, 5, REG_E ", // | 2--8 | Z 0 1 -
   [0x6C] = " bitFunction, 5, REG_H ", // | 2--8 | Z 0 1 -
   [0x6D] = " bitFunction, 5, REG_L ", // | 2--8 | Z 0 1 -
   [0x6F] = " bitFunction, 5, REG_A ", // | 2--8 | Z 0 1 -
   [0x70] = " bitFunction, 6, REG_B ", // | 2--8 | Z 0 1 -
   [0x71] = " bitFunction, 6, REG_C ", // | 2--8 | Z 0 1 -
   [0x72] = " bitFunction, 6, REG_D ", // | 2--8 | Z 0 1 -
   [0x73] = " bitFunction, 6, REG_E ", // | 2--8 | Z 0 1 -
   [0x74] = " bitFunction, 6, REG_H ", // | 2--8 | Z 0 1 -
   [0x75] = " bitFunction, 6, REG_L ", // | 2--8 | Z 0 1 -
   [0x77] = " bitFunction, 6, REG_A ", // | 2--8 | Z 0 1 -
   [0x78] = " bitFunction, 7, REG_B ", // | 2--8 | Z 0 1 -
   [0x79] = " bitFunction, 7, REG_C ", // | 2--8 | Z 0 1 -
   [0x7A] = " bitFunction, 7, REG_D ", // | 2--8 | Z 0 1 -
   [0x7B] = " bitFunction, 7, REG_E ", // | 2--8 | Z 0 1 -
   [0x7C] = " bitFunction, 7, REG_H ", // | 2--8 | Z 0 1 -
   [0x7D] = " bitFunction, 7, REG_L ", // | 2--8 | Z 0 1 -
   [0x7F] = " bitFunction, 7, REG_A ", // | 2--8 | Z 0 1 -
   [0x46] = " bitFunction, 0, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x4E] = " bitFunction, 1, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x56] = " bitFunction, 2, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x5E] = " bitFunction, 3, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x66] = " bitFunction, 4, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x6E] = " bitFunction, 5, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x76] = " bitFunction, 6, MEM_REG_HL ", // | 2--16 | Z 0 1 -
   [0x7E] = " bitFunction, 7, MEM_REG_HL ", // | 2--16 | Z 0 1 -

   

  // Reset bit (RES) instruction 
   [0x80] = " resFunction, 0, REG_B ", // | 2--8 | - - - -
   [0x81] = " resFunction, 0, REG_C ", // | 2--8 | - - - -
   [0x82] = " resFunction, 0, REG_D ", // | 2--8 | - - - -
   [0x83] = " resFunction, 0, REG_E ", // | 2--8 | - - - -
   [0x84] = " resFunction, 0, REG_H ", // | 2--8 | - - - -
   [0x85] = " resFunction, 0, REG_L ", // | 2--8 | - - - -
   [0x87] = " resFunction, 0, REG_A ", // | 2--8 | - - - -
   [0x88] = " resFunction, 1, REG_B ", // | 2--8 | - - - -
   [0x89] = " resFunction, 1, REG_C ", // | 2--8 | - - - -
   [0x8A] = " resFunction, 1, REG_D ", // | 2--8 | - - - -
   [0x8B] = " resFunction, 1, REG_E ", // | 2--8 | - - - -
   [0x8C] = " resFunction, 1, REG_H ", // | 2--8 | - - - -
   [0x8D] = " resFunction, 1, REG_L ", // | 2--8 | - - - -
   [0x8F] = " resFunction, 1, REG_A ", // | 2--8 | - - - -
   [0x90] = " resFunction, 2, REG_B ", // | 2--8 | - - - -
   [0x91] = " resFunction, 2, REG_C ", // | 2--8 | - - - -
   [0x92] = " resFunction, 2, REG_D ", // | 2--8 | - - - -
   [0x93] = " resFunction, 2, REG_E ", // | 2--8 | - - - -
   [0x94] = " resFunction, 2, REG_H ", // | 2--8 | - - - -
   [0x95] = " resFunction, 2, REG_L ", // | 2--8 | - - - -
   [0x97] = " resFunction, 2, REG_A ", // | 2--8 | - - - -
   [0x98] = " resFunction, 3, REG_B ", // | 2--8 | - - - -
   [0x99] = " resFunction, 3, REG_C ", // | 2--8 | - - - -
   [0x9A] = " resFunction, 3, REG_D ", // | 2--8 | - - - -
   [0x9B] = " resFunction, 3, REG_E ", // | 2--8 | - - - -
   [0x9C] = " resFunction, 3, REG_H ", // | 2--8 | - - - -
   [0x9D] = " resFunction, 3, REG_L ", // | 2--8 | - - - -
   [0x9F] = " resFunction, 3, REG_A ", // | 2--8 | - - - -
   [0xA0] = " resFunction, 4, REG_B ", // | 2--8 | - - - -
   [0xA1] = " resFunction, 4, REG_C ", // | 2--8 | - - - -
   [0xA2] = " resFunction, 4, REG_D ", // | 2--8 | - - - -
   [0xA3] = " resFunction, 4, REG_E ", // | 2--8 | - - - -
   [0xA4] = " resFunction, 4, REG_H ", // | 2--8 | - - - -
   [0xA5] = " resFunction, 4, REG_L ", // | 2--8 | - - - -
   [0xA7] = " resFunction, 4, REG_A ", // | 2--8 | - - - -
   [0xA8] = " resFunction, 5, REG_B ", // | 2--8 | - - - -
   [0xA9] = " resFunction, 5, REG_C ", // | 2--8 | - - - -
   [0xAA] = " resFunction, 5, REG_D ", // | 2--8 | - - - -
   [0xAB] = " resFunction, 5, REG_E ", // | 2--8 | - - - -
   [0xAC] = " resFunction, 5, REG_H ", // | 2--8 | - - - -
   [0xAD] = " resFunction, 5, REG_L ", // | 2--8 | - - - -
   [0xAF] = " resFunction, 5, REG_A ", // | 2--8 | - - - -
   [0xB0] = " resFunction, 6, REG_B ", // | 2--8 | - - - -
   [0xB1] = " resFunction, 6, REG_C ", // | 2--8 | - - - -
   [0xB2] = " resFunction, 6, REG_D ", // | 2--8 | - - - -
   [0xB3] = " resFunction, 6, REG_E ", // | 2--8 | - - - -
   [0xB4] = " resFunction, 6, REG_H ", // | 2--8 | - - - -
   [0xB5] = " resFunction, 6, REG_L ", // | 2--8 | - - - -
   [0xB7] = " resFunction, 6, REG_A ", // | 2--8 | - - - -
   [0xB8] = " resFunction, 7, REG_B ", // | 2--8 | - - - -
   [0xB9] = " resFunction, 7, REG_C ", // | 2--8 | - - - -
   [0xBA] = " resFunction, 7, REG_D ", // | 2--8 | - - - -
   [0xBB] = " resFunction, 7, REG_E ", // | 2--8 | - - - -
   [0xBC] = " resFunction, 7, REG_H ", // | 2--8 | - - - -
   [0xBD] = " resFunction, 7, REG_L ", // | 2--8 | - - - -
   [0xBF] = " resFunction, 7, REG_A ", // | 2--8 | - - - -
   [0x86] = " resFunction, 0, MEM_REG_HL ", // | 2--16 | - - - -
   [0x8E] = " resFunction, 1, MEM_REG_HL ", // | 2--16 | - - - -
   [0x96] = " resFunction, 2, MEM_REG_HL ", // | 2--16 | - - - -
   [0x9E] = " resFunction, 3, MEM_REG_HL ", // | 2--16 | - - - -
   [0xA6] = " resFunction, 4, MEM_REG_HL ", // | 2--16 | - - - -
   [0xAE] = " resFunction, 5, MEM_REG_HL ", // | 2--16 | - - - -
   [0xB6] = " resFunction, 6, MEM_REG_HL ", // | 2--16 | - - - -
   [0xBE] = " resFunction, 7, MEM_REG_HL ", // | 2--16 | - - - -
   
   
 

  // Set bit (SET) instruction 
   [0xC0] = " setFunction, 0, REG_B ", // | 2--8 | - - - -
   [0xC1] = " setFunction, 0, REG_C ", // | 2--8 | - - - -
   [0xC2] = " setFunction, 0, REG_D ", // | 2--8 | - - - -
   [0xC3] = " setFunction, 0, REG_E ", // | 2--8 | - - - -
   [0xC4] = " setFunction, 0, REG_H ", // | 2--8 | - - - -
   [0xC5] = " setFunction, 0, REG_L ", // | 2--8 | - - - -
   [0xC7] = " setFunction, 0, REG_A ", // | 2--8 | - - - -
   [0xC8] = " setFunction, 1, REG_B ", // | 2--8 | - - - -
   [0xC9] = " setFunction, 1, REG_C ", // | 2--8 | - - - -
   [0xCA] = " setFunction, 1, REG_D ", // | 2--8 | - - - -
   [0xCB] = " setFunction, 1, REG_E ", // | 2--8 | - - - -
   [0xCC] = " setFunction, 1, REG_H ", // | 2--8 | - - - -
   [0xCD] = " setFunction, 1, REG_L ", // | 2--8 | - - - -
   [0xCF] = " setFunction, 1, REG_A ", // | 2--8 | - - - -
   [0xD0] = " setFunction, 2, REG_B ", // | 2--8 | - - - -
   [0xD1] = " setFunction, 2, REG_C ", // | 2--8 | - - - -
   [0xD2] = " setFunction, 2, REG_D ", // | 2--8 | - - - -
   [0xD3] = " setFunction, 2, REG_E ", // | 2--8 | - - - -
   [0xD4] = " setFunction, 2, REG_H ", // | 2--8 | - - - -
   [0xD5] = " setFunction, 2, REG_L ", // | 2--8 | - - - -
   [0xD7] = " setFunction, 2, REG_A ", // | 2--8 | - - - -
   [0xD8] = " setFunction, 3, REG_B ", // | 2--8 | - - - -
   [0xD9] = " setFunction, 3, REG_C ", // | 2--8 | - - - -
   [0xDA] = " setFunction, 3, REG_D ", // | 2--8 | - - - -
   [0xDB] = " setFunction, 3, REG_E ", // | 2--8 | - - - -
   [0xDC] = " setFunction, 3, REG_H ", // | 2--8 | - - - -
   [0xDD] = " setFunction, 3, REG_L ", // | 2--8 | - - - -
   [0xDF] = " setFunction, 3, REG_A ", // | 2--8 | - - - -
   [0xE0] = " setFunction, 4, REG_B ", // | 2--8 | - - - -
   [0xE1] = " setFunction, 4, REG_C ", // | 2--8 | - - - -
   [0xE2] = " setFunction, 4, REG_D ", // | 2--8 | - - - -
   [0xE3] = " setFunction, 4, REG_E ", // | 2--8 | - - - -
   [0xE4] = " setFunction, 4, REG_H ", // | 2--8 | - - - -
   [0xE5] = " setFunction, 4, REG_L ", // | 2--8 | - - - -
   [0xE7] = " setFunction, 4, REG_A ", // | 2--8 | - - - -
   [0xE8] = " setFunction, 5, REG_B ", // | 2--8 | - - - -
   [0xE9] = " setFunction, 5, REG_C ", // | 2--8 | - - - -
   [0xEA] = " setFunction, 5, REG_D ", // | 2--8 | - - - -
   [0xEB] = " setFunction, 5, REG_E ", // | 2--8 | - - - -
   [0xEC] = " setFunction, 5, REG_H ", // | 2--8 | - - - -
   [0xED] = " setFunction, 5, REG_L ", // | 2--8 | - - - -
   [0xEF] = " setFunction, 5, REG_A ", // | 2--8 | - - - -
   [0xF0] = " setFunction, 6, REG_B ", // | 2--8 | - - - -
   [0xF1] = " setFunction, 6, REG_C ", // | 2--8 | - - - -
   [0xF2] = " setFunction, 6, REG_D ", // | 2--8 | - - - -
   [0xF3] = " setFunction, 6, REG_E ", // | 2--8 | - - - -
   [0xF4] = " setFunction, 6, REG_H ", // | 2--8 | - - - -
   [0xF5] = " setFunction, 6, REG_L ", // | 2--8 | - - - -
   [0xF7] = " setFunction, 6, REG_A ", // | 2--8 | - - - -
   [0xF8] = " setFunction, 7, REG_B ", // | 2--8 | - - - -
   [0xF9] = " setFunction, 7, REG_C ", // | 2--8 | - - - -
   [0xFA] = " setFunction, 7, REG_D ", // | 2--8 | - - - -
   [0xFB] = " setFunction, 7, REG_E ", // | 2--8 | - - - -
   [0xFC] = " setFunction, 7, REG_H ", // | 2--8 | - - - -
   [0xFD] = " setFunction, 7, REG_L ", // | 2--8 | - - - -
   [0xFF] = " setFunction, 7, REG_A ", // | 2--8 | - - - -
   [0xC6] = " setFunction, 0, MEM_REG_HL ", // | 2--16 | - - - -
   [0xCE] = " setFunction, 1, MEM_REG_HL ", // | 2--16 | - - - -
   [0xD6] = " setFunction, 2, MEM_REG_HL ", // | 2--16 | - - - -
   [0xDE] = " setFunction, 3, MEM_REG_HL ", // | 2--16 | - - - -
   [0xE6] = " setFunction, 4, MEM_REG_HL ", // | 2--16 | - - - -
   [0xEE] = " setFunction, 5, MEM_REG_HL ", // | 2--16 | - - - -
   [0xF6] = " setFunction, 6, MEM_REG_HL ", // | 2--16 | - - - -
   [0xFE] = " setFunction, 7, MEM_REG_HL ", // | 2--16 | - - - -
};
