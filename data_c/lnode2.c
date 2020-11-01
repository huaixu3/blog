#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode;
void displayLnode(Lnode *L)//ok
 {
         printf("=====print start======\n");
         printf("%d\t",L->data);
         while(L->next)
         {
                 L=L->next;
                 printf("%d\t",L->data);
         }
         printf("\n========print end=======\n");
 
 }
void destroyList(Lnode *L)
{
	Lnode *temp;
	while(L){
		temp=L->next;
		free(L);
		L=temp;}
}
void insertElem(Lnode *L,int i,int e){
	Lnode *temp=(Lnode*)malloc(sizeof(Lnode));
	temp->data=e;
	i--;
	while(i){
		L=L->next;
		i--;}
	temp->next=L->next;
	L->next=temp;
}
void deleteElem(Lnode *L,int i){
	Lnode *temp,*d;
	i-=2;
	while(i){
		L=L->next;
		i--;}
	temp=L;
	L=L->next;
	d=L;
	L=L->next;
	free(d);
	temp->next=L;
}	

int main()
{
	Lnode *L;
	int i=0;
	L=(Lnode*)malloc(sizeof(Lnode));
	L->next=NULL;
	L->data=0;
	//initlist
	for(i=1;i<=9;i++){
		insertElem(L,i,i);
	}
	insertElem(L,5,8);
	deleteElem(L,6);
	insertElem(L,8,0);
	displayLnode(L);
	destroyList(L);
	return 0;
}
