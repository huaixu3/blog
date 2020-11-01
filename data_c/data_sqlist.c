#include<stdio.h>
#define maxSize 10
typedef struct {
	int data[maxSize];
	int length;
}Sqlist;
void initList(Sqlist *A,int m)
{
	int i=0;
	for(i=0;i<=m;i++)
		A->data[i]=i+1;
	A->length=m+1;
}
void displayData(Sqlist A)
{
	int i,n;
	n=A.length-1;
	printf("=======print start=======\n");
	for(i=0;i<=n;i++)
		printf("%d\t",A.data[i]);
	printf("\n=======print end=========\n");
}
int findElem(Sqlist A,int a)
{
	int i=0;
	for(i=0;i<=A.length-1;i++)
		if(A.data[i]>=a)
			return i;
	return i;
}
void insertElem(Sqlist *A,int e)
{
	int i,n;
	n=findElem(*A,e);
	for(i=A->length-1;i>=n;i--)
		A->data[i+1]=A->data[i];
	A->data[n]=e;
	A->length++;
}
void deleteElem(Sqlist *A,int n)
{
	int i;
	for(i=n-1;i<=A->length;i++)
		A->data[i]=A->data[i+1];
	A->length--;

}
int main(){
	Sqlist A;
	int n=0;
	initList(&A,7);
	displayData(A);
	insertElem(&A,18);
	displayData(A);
	deleteElem(&A,3);
	displayData(A);
	insertElem(&A,3);
	displayData(A);
	return 0;
}

