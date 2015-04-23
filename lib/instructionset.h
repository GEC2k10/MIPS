#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NOPCODES 28

struct opcode
{
    char code[10];
    char format[10];
};

typedef struct opcode opcode;

opcode opcodes[NOPCODES];

void intialize_opcodes()
{
    FILE *fp = fopen("lib/instructions.txt", "r");
    int i = 0;
    while(fscanf(fp, "%s %s", opcodes[i].code, opcodes[i].format) != EOF)
    {
        i++;
    }
}

int search(char *code)
{
    int start = 0, end = NOPCODES, middle, cmp;

    while(start <= end)
    {
        middle = (start + end) / 2;
        cmp = strcmp(opcodes[middle].code, code);

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

int validate_format(opcode code, char *command)
{
    return 0;
}
