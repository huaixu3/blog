#include<stdio.h>
#include<malloc.h>
//define lnode struc
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode;
void initLnode(Lnode *L)
{
	L->data=1;
	L->next=NULL;
}
void destroyLnode(Lnode *L)
{
	Lnode *p;
	do
	{
		p=L->next;
		free(L);
		L->next=p;
	}while(L->next!=NULL);
}
void displayLnode(Lnode L)
{
	printf("=====print start======\n");
	do
	{
		printf("%d\t",L.data);
		if(L.next!=NULL)
			L=*L.next;
	}while(L.next!=NULL);
	printf("\n========print end=======\n");
			
}
int findElem(Lnode *L,int e)
{
	int i=0;
	do
	{
		if(L->data>=e)return i;
		if(L->next!=NULL) L=L->next;
		i++;
	}while(L->next!=NULL);
	return --i;
}
void insertElem(Lnode *L,int e)
{
	int n;
	Lnode *temp;
	//n=findElem(L,e);
	n=1;
	temp=(Lnode*)malloc(sizeof(Lnode));
	temp->data=e;
	temp->next=L->next;
	L->next=temp;
	
}
int main()
{
	Lnode L;
	initLnode(&L);
	displayLnode(L);

	insertElem(&L,3);
	displayLnode(L);
	//destroyLnode(&L);//test end destroy Lnode
	L=*L.next;
	printf("%d/n",L.data);
	return 0;
}
