#include<stdio.h>
#include "../lib/instructionset.h"

int main()
{
    char str[100];
    scanf("%s", str);
    printf("%d\n", search(str));
}
