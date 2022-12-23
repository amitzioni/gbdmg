// instructions.h - interface for the cpu to access insructions arrays for decoding the instruction code
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "operands.h"

typedef struct{
    void (*op_func)(operand,operand);
    operand op1;
    operand op2;
}instruction;

extern const instruction normal_inst[0x100];
extern const instruction cb_inst[0x100];

#endif
