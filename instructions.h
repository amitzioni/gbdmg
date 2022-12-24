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

void ldFunction(operand op1, operand op2);
void incFunction(operand op1, operand op2);
void decFunction(operand op1, operand op2);
void addFunction(operand op1, operand op2);
void adcFunction(operand op1, operand op2);
void subFunction(operand op1, operand op2);
void sbcFunction(operand op1, operand op2);
void xorFunction(operand op1, operand op2);
void andFunction(operand op1, operand op2);
void orFunction(operand op1, operand op2);
void cpFunction(operand op1, operand op2);
void jpFunction(operand op1, operand op2);
void jrFunction(operand op1, operand op2);
void pushFunction(operand op1, operand op2);
void popFunction(operand op1, operand op2);
void callFunction(operand op1, operand op2);
void retFunction(operand op1, operand op2);
void retiFunction(operand op1, operand op2);
void rstFunction(operand op1, operand op2);
void daaFunction(operand op1, operand op2);
void cplFunction(operand op1, operand op2);
void scfFunction(operand op1, operand op2);
void ccfFunction(operand op1, operand op2);
void diFunction(operand op1, operand op2);
void eiFunction(operand op1, operand op2);
void nopFunction(operand op1, operand op2);
void stopFunction(operand op1, operand op2);
void haltFunction(operand op1, operand op2);
void rlaFunction(operand op1, operand op2);
void rraFunction(operand op1, operand op2);
void rlcaFunction(operand op1, operand op2);
void rrcaFunction(operand op1, operand op2);
void rlcFunction(operand op1, operand op2);
void rrcFunction(operand op1, operand op2);
void rlFunction(operand op1, operand op2);
void rrFunction(operand op1, operand op2);
void slaFunction(operand op1, operand op2);
void sraFunction(operand op1, operand op2);
void srlFunction(operand op1, operand op2);
void swapFunction(operand op1, operand op2);
void bitFunction(operand op1, operand op2);
void resFunction(operand op1, operand op2);
void setFunction(operand op1, operand op2);
#endif
