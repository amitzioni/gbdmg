// memory.h - The interface to interact with the memory
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include "defs.h"

extern char rom_title[16];

void initMemory(FILE *rom_file);
Byte getMemory(Word addr);
void setMemory(Word addr, Byte val);



#endif
