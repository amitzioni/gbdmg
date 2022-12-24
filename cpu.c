// cpu.c - Where the cpu instructions actually take place

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


#include "defs.h"
#include "memory.h"
#include "registers.h"
#include "operands.h"

// Utility Functions


static bool interrupt_master_flag = false;

Byte fetchByteByPC(void){
    Word addr = getWordRegister(REG_PC);

    Byte to_return = getMemory(addr);

    setWordRegister(REG_PC, addr + 1);

    return to_return;
}

Word fetchWordByPC(void){
    Word addr = getWordRegister(REG_PC);

    Word to_return = getMemory(addr);
    to_return |= (((Word)getMemory(addr+1)) << 8);

    setWordRegister(REG_PC, addr + 2);
    return to_return;
}

bool isByteOperand(operand op){
    if(op >= REG_A && op <= REG_L)
        return true;
    
    if(op >= MEM_REG_BC && op <= MEM_REG_HL_MINUS)
        return true;

    if(op == IMM8) 
        return true;

    return false;
}
Byte getByteOperand(operand op){
    if(op >= REG_A && op <= REG_L)
        return getByteRegister(op);
    if(op == IMM8)
        return fetchByteByPC();

    Word addr;
    switch(op)
    {
        case MEM_REG_BC:
            addr = getWordRegister(REG_BC);
            break;
        case MEM_REG_DE:
            addr = getWordRegister(REG_DE);
            break;
        case MEM_REG_HL:
            addr = getWordRegister(REG_HL);
            break;
        case MEM_IMM16:
            addr = fetchWordByPC();
            break;
        case MEM_REG_C:
            addr = getByteRegister(REG_C) + 0xFF00 ;
            break;
        case MEM_IMM8:
            addr = fetchByteByPC() + 0xFF00 ;
            break;
        case MEM_REG_HL_PLUS:
            addr = getWordRegister(REG_HL);
            setWordRegister(REG_HL, addr + 1);
            break;

        case MEM_REG_HL_MINUS:
            addr = getWordRegister(REG_HL);
            setWordRegister(REG_HL, addr - 1);
            break;

        default:
            fprintf(stderr, "Error in %s: Could not docode memory address\n", __func__);
            exit(EXIT_FAILURE);
            break;
    }

    return getMemory(addr);
}

void setByteOperand(operand op, Byte val){
    if(op >= REG_A && op <= REG_L)
    {
        setByteRegister(op, val);
        return;
    }

    Word addr;
    switch(op)
    {
        case MEM_REG_BC:
            addr = getWordRegister(REG_BC);
            break;
        case MEM_REG_DE:
            addr = getWordRegister(REG_DE);
            break;
        case MEM_REG_HL:
            addr = getWordRegister(REG_HL);
            break;
        case MEM_IMM16:
            addr = fetchWordByPC();
            break;
        case MEM_REG_C:
            addr = getByteRegister(REG_C) + 0xFF00 ;
            break;
        case MEM_IMM8:
            addr = fetchByteByPC() + 0xFF00 ;
            break;
        case MEM_REG_HL_PLUS:
            addr = getWordRegister(REG_HL);
            setWordRegister(REG_HL, addr + 1);
            break;

        case MEM_REG_HL_MINUS:
            addr = getWordRegister(REG_HL);
            setWordRegister(REG_HL, addr - 1);
            break;

        default:
            fprintf(stderr, "Error in %s: Could not docode memory address\n", __func__);
            exit(EXIT_FAILURE);
            break;
    }

    setMemory(addr, val);
}
bool isWordOperand(operand op){
    if(op >= REG_SP && op <= REG_HL)
        return true;

    if(op == IMM16)
        return true;

    if(op == REG_SP_PLUS_SIMM8)
        return true;

    return false;
}

Word getWordOperand(operand op){

    if(op >= REG_SP && op <= REG_HL)
        return getWordRegister(op);

    if(op == IMM16)
        return fetchWordByPC();

    if(op == REG_SP_PLUS_SIMM8)
    {
        Word to_return = getWordRegister(REG_SP);
        SignedByte simm8 = (SignedByte) fetchByteByPC();
        
        setFlag(FLAG_Z, false);
        setFlag(FLAG_N, false);
        setFlag(FLAG_H, ((to_return & 0xF) + (simm8 & 0xF)) & 0x10);
        setFlag(FLAG_C, (to_return + (Byte)simm8) < to_return);
        return (to_return + simm8);

    }
    else
    {
        fprintf(stderr, "Error in %s: Could not decode word operand\n", __func__);
        exit(EXIT_FAILURE);
    }

}

void setWordOperand(operand op, Word val){
    if(op >= REG_SP && op <= REG_HL)
        setWordRegister(op, val);
    else
    {
        fprintf(stderr, "Error in %s: Could not decode word operand\n", __func__);
        exit(EXIT_FAILURE);
    }
}




// Function corresponding to the instruction set
void ldFunction(operand op1, operand op2){
    // The only exception where op2 is a Word 
    // and op1 is a Byte to assign to
    if(op2 == REG_SP)
    {
        Word reg_sp = getWordRegister(REG_SP);
        Word addr = fetchWordByPC();
        setMemory(addr, reg_sp);
    }
    else if(isByteOperand(op2))
    {
        Byte op2_val = getByteOperand(op2);
        setByteOperand(op1, op2_val);
    }
    else if(isWordOperand(op2))
    {
        Word op2_val = getWordOperand(op2);
        setWordOperand(op1, op2_val);
    }
}

void incFunction(operand op1, operand op2){
    if(isByteOperand(op1))
    {
        Byte op1_val = getByteOperand(op1);
        setFlag(FLAG_N, false);
        setFlag(FLAG_Z, (op1_val + 1) == 0);
        setFlag(FLAG_H, ((op1_val & 0xF) + 1)& 0x10);
        setByteOperand(op1, op1_val + 1);

    }
    else if(isWordOperand(op1))
    {
        Word op1_val = getWordOperand(op1);
        setWordOperand(op1, op1_val + 1);
    }

}

void decFunction(operand op1, operand op2){
    if(isByteOperand(op1))
    {
        Byte op1_val = getByteOperand(op1);
        setFlag(FLAG_N, true);
        setFlag(FLAG_Z, (op1_val - 1) == 0);
        setFlag(FLAG_H, ((op1_val & 0xF) - 1)& 0x10);
        setByteOperand(op1, op1_val - 1);

    }
    else if(isWordOperand(op1))
    {
        Word op1_val = getWordOperand(op1);
        setWordOperand(op1, op1_val - 1);
    }

}

void addFunction(operand op1, operand op2){
    if(op2 == SIMM8)
    {
        Word op1_val = getWordRegister(REG_SP);
        SignedByte op2_val = fetchByteByPC();

        setFlag(FLAG_Z, false);
        setFlag(FLAG_N, false);
        setFlag(FLAG_H, ((op1_val & 0xF) + (op2_val & 0xF)) & 0x10);
        if(op2_val >= 0)
            setFlag(FLAG_C, (op1_val + op2_val) < op1_val);
        else
            setFlag(FLAG_C, (op1_val + op2_val) > op1_val);
        setWordRegister(REG_SP, op1_val + op2_val);
    }
    else if(isByteOperand(op2))
    {
        Byte op1_val = getByteOperand(op1);
        Byte op2_val = getByteOperand(op2);

        setFlag(FLAG_N, false);
        setFlag(FLAG_Z, (op1_val + op2_val) == 0);
        setFlag(FLAG_H, ((op1_val & 0xF) + (op2_val & 0xF)) & 0x10);
        setFlag(FLAG_C, (op1_val + op2_val) < op1_val);

        setByteOperand(op1, op1_val + op2_val);

    }
    else if(isWordOperand(op2))
    {
        Word op1_val = getWordOperand(op1);
        Word op2_val = getWordOperand(op2);

        setFlag(FLAG_N, false);
        setFlag(FLAG_H, ((op1_val & 0xFFF) + (op2_val & 0xFF)) & 0x1000);

        setFlag(FLAG_C, (op1_val + op2_val) < op1_val);
        setWordOperand(op1, op1_val + op2_val);


    }

}

void adcFunction(operand op1, operand op2){
    Byte carry = (getFlag(FLAG_C) ? 1 : 0);
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2) + carry;

    setFlag(FLAG_N, false);
    setFlag(FLAG_Z, (op1_val + op2_val) == 0);
    setFlag(FLAG_H, ((op1_val & 0xF) + (op2_val & 0xF)) & 0x10);
    setFlag(FLAG_C, (op1_val + op2_val) < op1_val);

    setByteOperand(op1, op1_val + op2_val);

}

void subFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2);

    setFlag(FLAG_N, true);
    setFlag(FLAG_Z, (op1_val - op2_val) == 0);
    setFlag(FLAG_H, ((op1_val & 0xF) - (op2_val & 0xF)) & 0x10);
    setFlag(FLAG_C, (op1_val - op2_val) > op1_val);

    setByteOperand(op1, op1_val - op2_val);

}

void sbcFunction(operand op1, operand op2){
    Byte carry = (getFlag(FLAG_C) ? 1 : 0);
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2) + carry;

    setFlag(FLAG_N, true);
    setFlag(FLAG_Z, (op1_val - op2_val) == 0);
    setFlag(FLAG_H, ((op1_val & 0xF) - (op2_val & 0xF)) & 0x10);
    setFlag(FLAG_C, (op1_val - op2_val) > op1_val);

    setByteOperand(op1, op1_val - op2_val);

}

void xorFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2);

    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setFlag(FLAG_C, false);
    setFlag(FLAG_Z, (op1_val ^ op2_val) == 0);

    setByteOperand(op1, op1_val ^ op2_val);

}

void andFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2);

    setFlag(FLAG_N, false);
    setFlag(FLAG_H, true);
    setFlag(FLAG_C, false);
    setFlag(FLAG_Z, (op1_val & op2_val) == 0);

    setByteOperand(op1, op1_val & op2_val);


}

void orFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2);

    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setFlag(FLAG_C, false);
    setFlag(FLAG_Z, (op1_val | op2_val) == 0);

    setByteOperand(op1, op1_val | op2_val);

}

void cpFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    Byte op2_val = getByteOperand(op2);

    setFlag(FLAG_N, true);
    setFlag(FLAG_Z, (op1_val - op2_val) == 0);
    setFlag(FLAG_H, ((op1_val & 0xF) - (op2_val & 0xF)) & 0x10);
    setFlag(FLAG_C, (op1_val - op2_val) > op1_val);


}

void jpFunction(operand op1, operand op2){
    Word addr;
    if(op1 == MEM_REG_HL)
        addr = getByteOperand(op1);
    else
        addr = fetchWordByPC();

    if((op2 == EMPTY) || \
      (op1 == CON_Z && getFlag(FLAG_Z)) || \
      (op1 == CON_C && getFlag(FLAG_C)) || \
      (op1 == CON_NZ && getFlag(FLAG_N) && getFlag(FLAG_Z)) || \
      (op1 == CON_NC && getFlag(FLAG_N) && getFlag(FLAG_C)))
        setWordRegister(REG_PC, addr);
}

void jrFunction(operand op1, operand op2){
    Word addr = getWordRegister(REG_PC);
    SignedByte simm8 = fetchByteByPC();

    if((op2 == EMPTY) || \
      (op1 == CON_Z && getFlag(FLAG_Z)) || \
      (op1 == CON_C && getFlag(FLAG_C)) || \
      (op1 == CON_NZ && getFlag(FLAG_N) && getFlag(FLAG_Z)) || \
      (op1 == CON_NC && getFlag(FLAG_N) && getFlag(FLAG_C)))
        setWordRegister(REG_PC, addr + simm8);

}

void pushFunction(operand op1, operand op2){
    Word stackp = getWordRegister(REG_SP);
    Word op1_val = getWordOperand(op1);
    Byte lsb = op1_val & 0xFF;
    Byte msb = (op1_val >> 8) & 0xFF;

    setMemory(msb, stackp - 1);
    setMemory(lsb, stackp - 2);

    setWordRegister(REG_SP, stackp - 2);


}

void popFunction(operand op1, operand op2){
    Word stackp = getWordRegister(REG_SP);
    Byte lsb = getMemory(stackp);
    Byte msb = getMemory(stackp + 1);
    Word to_assign = (((Word)msb) << 8) | lsb;
    setWordRegister(op1, to_assign);

}

void callFunction(operand op1, operand op2){
    pushFunction(REG_PC, EMPTY);
    Word addr = fetchWordByPC();

    if((op2 == EMPTY) || \
      (op1 == CON_Z && getFlag(FLAG_Z)) || \
      (op1 == CON_C && getFlag(FLAG_C)) || \
      (op1 == CON_NZ && getFlag(FLAG_N) && getFlag(FLAG_Z)) || \
      (op1 == CON_NC && getFlag(FLAG_N) && getFlag(FLAG_C)))
        setWordRegister(REG_PC, addr);
}

void retFunction(operand op1, operand op2){
    if((op2 == EMPTY) || \
      (op1 == CON_Z && getFlag(FLAG_Z)) || \
      (op1 == CON_C && getFlag(FLAG_C)) || \
      (op1 == CON_NZ && getFlag(FLAG_N) && getFlag(FLAG_Z)) || \
      (op1 == CON_NC && getFlag(FLAG_N) && getFlag(FLAG_C)))
        popFunction(REG_PC, EMPTY);

}

void retiFunction(operand op1, operand op2){
    popFunction(REG_PC, EMPTY);
    interrupt_master_flag = true;
}

void rstFunction(operand op1, operand op2){
    pushFunction(REG_PC, EMPTY);
    Word addr = op1;
    setWordRegister(REG_PC, addr);

}

//TODO was done according to the Z80 instruction set due to 
//lack of documentation on the Gameboy CPU corresponding 
//instruction
void daaFunction(operand op1, operand op2){
    Byte reg_a = getByteRegister(REG_A);
    Byte cp_reg_a = reg_a;
    if((reg_a & 0xF) > 0x9 || getFlag(FLAG_H))
        reg_a += 0x06;

    if((reg_a & 0xF0) > 0x90 || getFlag(FLAG_C))
        reg_a += 0x60;

    setFlag(FLAG_H, false);
    setFlag(FLAG_Z, reg_a == 0);
    setFlag(FLAG_C, reg_a < cp_reg_a);
    setByteRegister(REG_A, reg_a);
}

void cplFunction(operand op1, operand op2){
    Byte reg_a = getByteRegister(REG_A);

    setFlag(FLAG_N, true);
    setFlag(FLAG_H, true);

    setByteRegister(REG_A, reg_a ^ 0xFF);
}

void scfFunction(operand op1, operand op2){
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setFlag(FLAG_C, true);
}

void ccfFunction(operand op1, operand op2){
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    bool cy = getFlag(FLAG_C);
    if(cy == true)
        setFlag(FLAG_C, false);
    else
        setFlag(FLAG_C, true);


}

void diFunction(operand op1, operand op2){
    interrupt_master_flag = false;

}

void eiFunction(operand op1, operand op2){
    interrupt_master_flag = true;

}

void nopFunction(operand op1, operand op2){
    return;
}

void stopFunction(operand op1, operand op2){
    // Not Implemented
    return;

}

void haltFunction(operand op1, operand op2){
    // Not Implemented
    return;

}

void rlcFunction(operand op1, operand op2){

    Byte op1_val = getByteOperand(op1);
    bool out_bit = (bool) ((1UL << 7) & op1_val);
    op1_val <<= 1;
    if(out_bit)
    {
        setFlag(FLAG_C, true);
        op1_val |= 1;
    }
    else
        setFlag(FLAG_C, false);

    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setByteOperand(op1, op1_val);
}

void rrcFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    bool out_bit = (bool) (op1_val & 1);
    op1_val >>= 1;
    if(out_bit)
    {
        setFlag(FLAG_C, true);
        op1_val |= (1UL << 7);
    }
    else
        setFlag(FLAG_C, false);

    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setByteOperand(op1, op1_val);

}

void rlFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    bool carry = getFlag(FLAG_C);

    bool out_bit = (bool) ((1UL << 7) & op1_val);
    setFlag(FLAG_C, out_bit);

    op1_val <<= 1;

    if(carry)
        op1_val |= 1;

    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setByteOperand(op1, op1_val);

}

void rrFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    bool carry = getFlag(FLAG_C);

    bool out_bit = (bool) (1 & op1_val);
    setFlag(FLAG_C, out_bit);

    op1_val >>= 1;

    if(carry)
        op1_val |= (1UL << 7);

    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setByteOperand(op1, op1_val);

}

void rlaFunction(operand op1, operand op2){
    rlFunction(REG_A, EMPTY);
    setFlag(FLAG_Z, false);
}

void rraFunction(operand op1, operand op2){
    rrFunction(REG_A, EMPTY);
    setFlag(FLAG_Z, false);

}

void rlcaFunction(operand op1, operand op2){
    rlcaFunction(REG_A, EMPTY);
    setFlag(FLAG_Z, false);

}

void rrcaFunction(operand op1, operand op2){
    rrcaFunction(REG_A, EMPTY);
    setFlag(FLAG_Z, false);

}

void slaFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    setFlag(FLAG_C, (1UL << 7) & op1_val);
    op1_val <<= 1;
    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);

    setByteOperand(op1, op1_val);

}

void sraFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    bool msb = (bool) ((1UL << 7) & op1_val);
    op1_val >>= 1;

    if(msb)
        op1_val |= (1UL << 7);

    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setFlag(FLAG_C, false);

    setByteOperand(op1, op1_val);

}

void srlFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    setFlag(FLAG_C, op1_val & 1);
    op1_val >>= 1;
    
    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setByteOperand(op1, op1_val);

}

void swapFunction(operand op1, operand op2){
    Byte op1_val = getByteOperand(op1);
    Byte low_nibble = op1_val & 0xF ;
    op1_val >>= 4;
    op1_val |= (low_nibble << 4);

    setFlag(FLAG_Z, op1_val == 0);
    setFlag(FLAG_N, false);
    setFlag(FLAG_H, false);
    setFlag(FLAG_C, false);
    
    setByteOperand(op1, op1_val);


}

void bitFunction(operand op1, operand op2){
    Byte op2_val = getByteOperand(op2);

    setFlag(FLAG_Z, (1UL << op1) & op2_val);
    setFlag(FLAG_H, true);
    setFlag(FLAG_N, false);
}

void resFunction(operand op1, operand op2){
    Byte op2_val = getByteOperand(op2);
    op2_val &= (~(1UL << op1));
    setByteOperand(op2, op2_val);

}

void setFunction(operand op1, operand op2){
    Byte op2_val = getByteOperand(op2);
    op2_val |= (1UL << op1);
    setByteOperand(op2, op2_val);

}

