#include<stdio.h>
#include "../lib/instructionset.h"

int main(int argc, char *argv)
{
    char str[100];
    scanf("%s", str);
    intialize_opcodes();
    printf("%d\n", search(str));
}
