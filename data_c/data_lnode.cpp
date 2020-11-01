#include<stdio.h>
#include<malloc.h>
//define lnode struc
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode;
void displayLnode(Lnode &L);
void initLnode(Lnode &L)//ok
{
	int i=0;
	Lnode *T=&L;
	for(i=0;i<=9;i++)
	{
		L.data=i;
		L.next=(Lnode*)malloc(sizeof(Lnode));
 		printf("%p\n",L.next);
		L=*L.next;
	}
	L=*T;
	displayLnode(L);
//	Lnode *T=&L;
//	int i;
//	L.data=0;
//	L.next=(Lnode *)malloc(sizeof(Lnode));
//	T=L.next;
//	for(i=1;i<=9;i++){
//		T->next=(Lnode*)malloc(sizeof(Lnode));
//		T->data=i;
//		T=T->next;
//	}
}
void destroyLnode(Lnode &L)//ok
{
	Lnode temp;
	temp=*L.next;
	free(&L);
	while(temp.next){
		L=*temp.next;
		temp=*temp.next;
		free(&L);
	}
}
void displayLnode(Lnode &L)//ok
{
	printf("=====print start======\n");
	printf("%d\t",L.data);
	while(L.next)
	{
		L=*L.next;
		printf("%d\t",L.data);
	}
	printf("\n========print end=======\n");
			
}
void insertElem(Lnode &L,int e)
{
	Lnode *T;
	T=(Lnode*)malloc(sizeof(Lnode));
	//L_temp=L;
	//while(L.data<e)
	//{
	//	if(L.next==NULL)break;
	//	L=*L.next;
	//}
	//temp=(Lnode*)malloc(sizeof(Lnode));
	//temp->data=e;
	//temp->next=L.next;
	//L.next=temp;
	//L=L_temp;
	//if(L.next==NULL)L.next=temp;
}
int main()
{
	Lnode L;
	printf("%p",L.next);
	initLnode(L);
	printf("%p",L.next);
//	printf("%d",L.data);
//	L=*L.next;
//	L.data=1;
//	printf("%d",L.data);
	displayLnode(L);
//	L=*L.next;
	//L=*L.next;

	//insertElem(L,3);
	//insertElem(L,4);
//	displayLnode(L);
	//destroyLnode(L);//test end destroy Lnode
	return 0;
}
