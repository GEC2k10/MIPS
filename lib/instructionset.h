#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NOPCODES ((sizeof(opcodes) / sizeof(const char *)) - 1)

const char* opcodes[] = {
	"add","addi","addiu","addu","and","andi",
    "beq","bne","j","jal","jr","lbu","lhu","lui",
    "lw","nor","or","ori","slt","slti","sltiu",
    "sltu","sll","srl","sb","sh","sw","sub","subu"
};

int search(char *opcode)
{
    int start = 0, end = NOPCODES, middle, cmp;

    while(start <= end)
    {
        middle = (start + end) / 2;
        cmp = strcmp(opcodes[middle], opcode);

        if(cmp == 0)
        {
            return middle;
        }
        if(cmp < 0)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}
