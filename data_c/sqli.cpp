#include<stdio.h>
#include<stdlib.h>

#define Initsize 10
typedef struct{
	int *data;
	int MaxSize;
	int length;
}Sqlist;
void InitList(Sqlist &L)
{
	L.data=(int *)malloc(sizeof(int)*Initsize);
	L.length=0;
	L.MaxSize=10;
}
void IncreaseSize(Sqlist &L,int len)
{
	int *temp;
	int i=1;
	temp=(int *)malloc(sizeof(int)*(len+L.MaxSize));
	for(i=1;i<=L.MaxSize;i++)
	{
		temp[i-1]=L.data[i-1];
	}
	L.MaxSize=L.MaxSize+len;
	free(L.data);
	L.data=&temp[0];
}
void ListInsert(Sqlist &L,int i,int e){
	

}
int main(){

	Sqlist L;
	InitList(L);
	IncreaseSize(L,5);
return 0;
}
