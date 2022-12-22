// registers.h - The interface to set and get the cpu registers and flags
#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdbool.h>
#include "defs.h"
#include "operands.h"


typedef enum{
    FLAG_Z = 7,
    FLAG_N = 6,
    FLAG_H = 5,
    FLAG_C = 4,
}flag;


Byte getByteRegister(operand op);
Word getWordRegister(operand op);
bool getFlag(flag fl);


void setByteRegister(operand op, Byte val);
void setWordRegister(operand op, Word val);
void setFlag(flag fl, bool val);









#endif
