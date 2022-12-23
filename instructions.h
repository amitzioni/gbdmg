// instructions.h - interface for the cpu to access insructions arrays for decoding the instruction code
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "operands.h"
typedef enum{
    LD = 0,
    INC,
    DEC,
    ADD,
    ADC,
    SUB,
    SBC,
    XOR,
    AND,
    OR,
    CP,
    JP,
    JR,
    PUSH,
    POP,
    CALL,
    RET,
    RETI,
    RST,
    DAA,
    CPL,
    SCF,
    CCF,
    DI,
    EI,
    NOP,
    STOP,
    HALT,
    RLA,
    RRA,
    RLCA,
    RRCA,
    RLC,
    RRC,
    RL,
    RR,
    SLA,
    SRA,
    SRL,
    SWAP,
    BIT,
    RES,
    SET,

}inst_name;

typedef struct{
    inst_name opr;
    operand op1;
    operand op2;
}instruction;

extern const instruction normal_inst[0x100];
extern const instruction cb_inst[0x100];

#endif
