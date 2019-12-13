 #include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define ADD 10

typedef int ElemType;

typedef struct{
	ElemType *base;
	int top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S){
	S.base=(ElemType *)malloc(MAX*sizeof(ElemType));
	S.top=-1;//初始化 
	S.stacksize=MAX;
}

int getLength(SqStack S){
	//得到长度 
	return S.top+1;//S.top+1;
} 

int StackEmpty(SqStack S){
	if(!getLength(S)){//S.top=-1;
		return 1;
	}

	return 0;
}


int StackFull(SqStack S){
	if(getLength(S)==S.stacksize){//S.top+1==S.stacksize
		return 1;
	}
	return 0;
}

void addCapicity(SqStack &S){
	//扩容
	 S.base=(ElemType *)realloc(S.base,ADD*sizeof(ElemType));
	 S.stacksize+=ADD;
}



void GetTop(SqStack S,ElemType &e){
	if(!StackEmpty(S)){
		e=S.base[S.top];//S.top	
	}else{
		exit(0);
	}
	
}

void Push(SqStack &S,ElemType e){
	if(StackFull(S)){
		addCapicity(S);
	}
	S.base[++S.top]=e;//++S.top
}

void Pop(SqStack &S,ElemType &e){
	if(!StackEmpty(S)){
		e=S.base[S.top--];//S.top--;
	}else{
		exit(0);
	}
	
}

void display(SqStack S){
	int i;
	for(i=getLength(S)-1;i>=0;i--){
		printf("%d\t",S.base[i]);
	}
	printf("\n");
}

int main(){
	SqStack S;
	InitStack(S);
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	display(S);
	return 0;
}
