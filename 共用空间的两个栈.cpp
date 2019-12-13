//公用存储空间的两个栈 

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int *base;
	int stacksize;
	int topLow;
	int topHigh;
	
}SqStack;

void InitStack(SqStack &S){
	S.base=(int *)malloc(MAX*sizeof(int));
	S.stacksize=MAX;
	S.topLow=0;
	S.topHigh=MAX-1;	
}

int isEmpty(SqStack S){
	if(S.topHigh==MAX-1 && S.topLow==0)
		return 1;
	
	return 0;		
}

int isFull(SqStack S){
	if(S.topLow-S.topHigh==1)
		return 1;
	return 0;
}

void Pop(SqStack &S,int &e,int i){
	if(isEmpty(S))
		return;
	if(i==1){
		e=S.base[--S.topLow];
	}else if(i==2){
		e=S.base[++S.topHigh];
	}else{
		printf("ERROR!");
	}
	
}

void Push(SqStack &S,int e,int i){
	if(isFull(S))
		return;
	if(i==1){
		S.base[S.topLow++]=e;
	}else if(i==2){
		S.base[S.topHigh--]=e;
	}else{
		printf("ERROR!");
	}
	
	
}

void getTop(SqStack S,int &e,int i){
	if(isEmpty(S))
		return;
	if(i==1){
		e=S.base[S.topLow-1];
	}else if(i==2){
		e=S.base[S.topHigh+1];
	}else{
		printf("ERROR!");
	}
	
}

void display(SqStack S,int i){
	int j;
	if(isEmpty(S))
		return;
	if(i==1){
		j=S.topLow-1; 
		while(j>=0){
			printf("%d\t",S.base[j]);
			j--;
		}
	}else if(i==2){
		j=S.topHigh+1;
		while(j<MAX){
			printf("%d\t",S.base[j]);
			j++;
		}
	}else{
		printf("ERROR!");
	}
	
}

int main(){
	SqStack S;
	InitStack(S);
	Push(S,3,1);
	Push(S,4,1);
	Push(S,5,1);
	Push(S,6,1);
	Push(S,7,1);
	Push(S,8,2);
	display(S,1);
	return 0;
}
