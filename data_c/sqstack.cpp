#include<stdio.h>
#include<stdlib.h>

//定义静态stack
//传销 增删 改查
#define maxsize 10
typedef struct{
	int data[maxsize];
	int top ;
} Sqstack;

void InitStack(Sqstack &s){
	s.top=-1;

}
bool Push(Sqstack &S,int e){
	//检查是否满栈
	if(S.top==maxsize-1)
		return false;
	S.top++;
	S.data[S.top]=e;
	return true;
}
bool Pop(Sqstack &S,int &e){
	//判断是否空栈
	if(S.top==-1)
		return false;
	e=S.data[S.top];
	S.top--;
	return true;
}
bool gettop(Sqstack S,int &e){
	if(S.top==-1)
		return false;
	e=S.data[S.top];
	return true;
}
int main(){
	Sqstack S;
	int e=-1;
	InitStack(S);
	Push(S,1);
	Push(S,9);
	Pop(S,e);
	printf("first pop:%d",e);
	return 0;
}
