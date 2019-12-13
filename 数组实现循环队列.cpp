//数组实现循环队列 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	int *base;
	int rear;
	int front;
}Queue;

void InitQueue(Queue &Q){
	Q.base=(int *)malloc(MAX*sizeof(Queue));
	Q.front=Q.rear=0;
}

int QueueEmpty(Queue Q){
	if(Q.front==Q.rear)
		return 1;
		
	return 0;
}

int QueueFull(Queue Q){
	if((Q.rear+1)%MAX==Q.front)
		return 1;
	return 0;
}

void EnQueue(Queue &Q,int e){
	if(QueueFull(Q))
		return;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAX;
	
}

void DeQueue(Queue &Q,int &e){
	if(QueueEmpty(Q))
		return;
	e=Q.base[Q.front]; 
	Q.front=(Q.front+1)%MAX;
	
}

void GetTop(Queue Q,int &e){
	if(QueueEmpty(Q)){
		return ;
	}
	
	e=Q.base[Q.front];
}

void display(Queue Q){
	int x = (Q.rear-Q.front+MAX)%MAX;
	int i,j;
	i=Q.front;j=Q.rear;
	if(i<=j){
		while(i<j){
			printf("%d\t",Q.base[i]);
			i++;
		}
	}else{
		while(i!=j){
			printf("%d\t",Q.base[i]);
			i=(i+1)%MAX;
		}

	}
	
}

int main(){
	Queue Q;
	InitQueue(Q);
	EnQueue(Q,2);
	EnQueue(Q,2);
	EnQueue(Q,2);
	EnQueue(Q,2);
	EnQueue(Q,2);
	display(Q);
	
	return 0;
}
