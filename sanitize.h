#include<stdio.h>
#include<string.h>
int getlen(FILE *fp)
{
	fseek(fp,0,SEEK_END);
	int end=ftell(fp);
	rewind(fp);
	return end;
}

int sanitize(char mnemonic[])
{
	FILE *fp=fopen("InstructionSet","r");
	int end=getlen(fp);
	char high,low,mid,flag;
	high=end/5;
	low=0;
	while(mid >
