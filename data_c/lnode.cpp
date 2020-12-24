#include<stdio.h>
#include<stdlib.h>

 typedef struct Lnode{
	 int data;
	 struct Lnode *next;
 }Lnode,*LinkList;
void initLnode(LinkList &L){
	L=(LinkList)malloc(sizeof(Lnode));
	L->data=1;
	L->next=NULL;
}
bool ListInsert(LinkList &L,int i,int e){
	//判断是否合法i
	if(i<1)
		return false;
	Lnode *s=(Lnode *)malloc(sizeof(Lnode));
	Lnode *p=L;
	int j=0;
	//找到相应的位置
	while(p!=NULL &&j<i-1)
		p=p->next,j++;
	if(p==NULL)
		return false;
	s->next=p->next;
	s->data=e;
	p->next=s;
	return true;
}
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	int j=0;
	Lnode *p=L;
	while(p->next!=NULL && j<i-1)
		p=p->next,j++;
	e=p->next->data;
	p->next=p->next->next;
	return true;
}
void printLnode(LinkList &L){
	printf("====start=====\n");
	Lnode p=*L;
	printf("%d\t",p.data);
	while(p.next!=NULL)
		p=*p.next,printf("%d\t",p.data);
	printf("\n====end=====");
}

int main(){
LinkList L;
initLnode(L);
printLnode(L);
for(int i=1;i<5;i++)
	ListInsert(L,i,i+4);
printLnode(L);
int e=0;
ListDelete(L,3,e);
printLnode(L);
printf("%d",e);
return 0;
}

