//5 张怀旭 实习题目-线性表的基本操作
//创建线性表并完成插入删除等操作

#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#define InitSize 100
#define Addsize 10
typedef struct{
	int *data;
	int length,Maxsize;
}SqList;
bool ListInsert(SqList &L,int i,int e){
	if (i<1)
		return false;
	if (i>L.Maxsize){
		int *_data=L.data;
		L.data=(int *)malloc(sizeof(int)*(L.Maxsize+Addsize));
		for(int y=1;y<=L.Maxsize;y++)
			L.data[y]=_data[y];
		L.Maxsize=L.Maxsize+Addsize;
		free(_data);
	}

	for(int j=L.length;j>=i;j--)
		L.data[j+1]=L.data[j];
	L.data[i]=e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L,int i){
	if(i<1||i>L.length)
		return false;
	for(int j=i;j<L.length;j++)
		L.data[j]=L.data[j+1];
	L.length--;
	return true;
}
int locaElem(SqList &L,int e){
	for(int j=0;j<L.length;j++)
		if(L.data[j]==e)
			return j;
	return 0;
}
void Listprint(SqList L){
	printf("\nprint start\n");
	for(int j=1;j<=L.length;j++)
		printf("%d\t",L.data[j]);
	printf("\nend\n");
}
void revease(SqList &L){
	int *_data=L.data;
	L.data=(int *)malloc(sizeof(int)*(L.length));
	for(int y=1;y<=L.length;y++)
			L.data[y]=_data[L.length-y+1];
}

int main(){
  	//q1 Init SqList
	SqList L; 
	L.length=0;
	L.data=(int *)malloc(sizeof(int)*InitSize);
	L.Maxsize=InitSize;
	//#q2 键盘输入5个整数并存入顺序表中
	int e=0;
	printf("q1：请输入5个整数：\n");
	for(int i=1;i<=5;i++){
		scanf("%d",&e);
		ListInsert(L,i,e);
	}
	Listprint(L);
	//q3  键盘输入两个数 i 和x 插入到第i个位置
	int ind;
	printf("q2 请输入你想插入的位置序号：\n");
	scanf("%d",&ind);
	printf("q2 请输入你想插入数字：\n");
	scanf("%d",&e);
	ListInsert(L,ind,e);
	Listprint(L);
	//q4  查找相等值的数 返回相应的位置 若无则是0
	printf("q3 请输入你想要查找的数字：\n");
	scanf("%d",&e);
	ind=locaElem(L, e);
	printf("q4 它的序号是: %d\n",ind);
	Listprint(L);
	//q5 删除指定序号i的值	
	printf("q5 请输入你想要删除的序号：\n");
	scanf("%d",&ind);
	ListDelete(L,ind);
	Listprint(L);
	//end
	//q6 逆序顺序表
	revease(L);
	Listprint(L);
	free(L.data);
	return 0;
}

//遇到的问题：边界问题，容易考虑出错，选择从一开始不错，0号用来存放线性表大小或者length属性
//多用print可以看到那里出错了
//函数的引用传值是个好东西
//2021.03.19
