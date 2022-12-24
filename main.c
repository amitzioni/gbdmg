

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "memory.h"
#include "cpu.h"


int main(int argc, char **argv){
    FILE *fp;  


    if(argc != 2)
    {
        fprintf(stderr, "Error in %s: Should give one file path as an argument\n", __func__);
        exit(EXIT_FAILURE);
    }


    if((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error in %s: Could not open file %s\n", __func__, argv[1]);
        exit(EXIT_FAILURE);
    }

    initMemory(fp);

    while(1)
    {
        cpuTick();
    }
}
