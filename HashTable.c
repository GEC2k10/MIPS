#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{	
	char OPCODE[6];
	struct node * next;
};
typedef struct node node;
int H(char * ); //Hash function.Hash function depends on the first char of opcode
void CreateHashTable(void);
void Insert(node **,char *,int);
int Search(node **,char *);


void main()
{
	CreateHashTable();
}


void CreateHashTable()
{
	node *Bucket[7];
	FILE *fp;
	char opcode[6],i;
	for(i=0;i<7;i++)//initializing Bucket to NULL
		Bucket[i]=NULL;
	fp=fopen("InstructionSet","r");
	while(fscanf(fp,"%s",opcode)!=EOF)
		Insert(Bucket,opcode,H(opcode));//Insert opcode with bucket number-H(opcode[0]) into Bucket 
}


int Search(node *Bucket[],char FindMe[])
{
	node *temp;
	if(H(FindMe)==-1){
//		printf("H=%d %s\n",H(FindMe),FindMe);
		return 0;
	}
	temp=Bucket[H(FindMe)];
	if(temp==NULL)
		return 0;
	else {
		while(temp!=NULL) {
//			printf("%s\n",temp->OPCODE);
			if(!(strcmp(temp->OPCODE,FindMe)))
				return 1;
			temp=temp->next;
		}
	}
	return 0;
}
void Insert(node *Bucket[],char opcode[],int Bkt_num)
{
	node *new,*temp=Bucket[Bkt_num];
	new=(node *)malloc(sizeof(node)); //Creates new node
	new->next=NULL;
	strcpy(new->OPCODE,opcode);
	if(temp==NULL) {
		Bucket[Bkt_num]=new;
	}
	else {
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}
}
int H(char A[])
{
	switch(A[0]){
		case 'a':
			return 0;
		case 'b':
			return 1;
		case 'j':
			return 2;
		case 'l':
			return 3;
		case 'n':
			return 4;
		case 'o':
			return 5;
		case 's':
			return 6;
		default :
			return -1;
	}
}
