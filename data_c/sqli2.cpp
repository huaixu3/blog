#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef struct{
	int data[Maxsize];
	int length;
}SqList;
bool ListInsert(SqList &L,int i,int e){
	if (i>L.length||i<1)
		return false;
	if (i>Maxsize)
		return false;
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length)
		return false;
	e=L.data[i];
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
}
int getElem(SqList &L,int i){
	return L.data[i-1];
}
int locaElem(SqList &L,int e){
	for(int j=0;j<L.length;j++)
		if(L.data[j]==e)
			return L.data[j];
	return -1;
}
void Listprint(SqList L){
	printf("\nstart\n");
	for(int j=0;j<L.length;j++)
		printf("%d\t",L.data[j]);
	printf("\nend");
}
int main(){
	SqList L;
	L.length=1;
	L.data[0]=1;
	int e;
	for(int i=1;i<4;i++)
		ListInsert(L,i,i+2);
	ListDelete(L,2,e);
	Listprint(L);
	return 0;
}

