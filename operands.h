// operands.h - CPU instructions operands enum (used also by the registers)

#ifndef OP_SYM_H
#define OP_SYM_H

typedef enum{
    // Registers
    REG_A = 0,
    REG_F,
    REG_B,
    REG_C,
    REG_D,
    REG_E,
    REG_H,
    REG_L,
    REG_SP,
    REG_PC,
    REG_AF,
    REG_BC = REG_AF + 2,
    REG_DE = REG_BC + 2,
    REG_HL = REG_DE + 2,
    //Memory
    MEM_REG_BC,
    MEM_REG_DE,
    MEM_REG_HL,
    MEM_IMM16,
    MEM_REG_C,
    MEM_IMM8,
    MEM_REG_HL_PLUS,
    MEM_REG_HL_MINUS,

    // Immediate Values
    IMM8,
    SIMM8,
    IMM16,
    // Conditions
    CON_NZ,
    CON_Z, 
    CON_NC,
    CON_C, 

    //Weird 
    REG_SP_PLUS_SIMM8, 


    // EMPTY enum for padding instructions with less than 2 arguments
    EMPTY,

}operand;

#endif
