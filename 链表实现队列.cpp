//链表实现队列
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node , *L;

typedef struct Queue{
	L rear;
	L front;
}Queue; 

void InitQueue(Queue &Q){
	Q.front = (L)malloc(sizeof(Node));
	Q.rear = Q.front;
	Q.front->next=NULL;
}

int QueueEmpty(Queue Q){
	if(Q.front==Q.rear)
		return 1;
	return 0;
}

void EnQueue(Queue &Q,int e){
	L temp;
	temp=(L)malloc(sizeof(Node));
	temp->data=e;
	Q.rear->next=temp;
	Q.rear=temp;
}

void DeQueue(Queue &Q,int &e){
	L temp;
	if(QueueEmpty(Q))
		return ;
	temp=Q.front->next;
	if(temp==Q.rear){
		Q.rear=Q.front;
		Q.front->next=NULL;
		e=temp->data;
		free(temp);
	}else{
		Q.front->next=temp->next;
		e=temp->data;
		free(temp);
	}
}

void display(Queue Q){
	L temp;
	temp=Q.front->next;
	while(temp->next!=Q.rear){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

int main(){
	
	Queue Q;
	InitQueue(Q);
	EnQueue(Q,1);

	display(Q);
	
	
	return 0;
}
