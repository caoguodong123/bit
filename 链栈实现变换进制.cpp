#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node{
	int data;
	struct Node *next;
	
}Node,*LinkStack;


void InitStack(LinkStack &S){
	S=(LinkStack)malloc(sizeof(Node));
	S->next=NULL;
}

void Push(LinkStack &S,ElemType e){
	LinkStack temp;
	temp=(LinkStack)malloc(sizeof(Node));
	temp->data=e;
	temp->next=S->next;
	S->next=temp;
}

int StackEmpty(LinkStack S){
	if(S->next==NULL)
		return 1;
	return 0;
}

void Pop(LinkStack &S,ElemType &e){
	LinkStack temp;
	
	if(StackEmpty(S))
		return;
	
	temp=S->next;
	e=temp->data;
	S->next=temp->next;
	free(temp);
}

void GetTop(LinkStack S,int &e){
	if(StackEmpty(S))
		return;
		
	e=S->next->data;
}

void display(LinkStack S){
	LinkStack temp;
	temp=S->next;
	while(temp){
		printf("%d",temp->data);
		temp=temp->next;
	}
	putchar('\n');
}

int main(){
	LinkStack S;
	int num,d;
	int i;
	
	printf("please input the number and the jinzhi:");
	scanf("%d%d",&num,&d);
	InitStack(S);
	while(num){
		Push(S,num%d);
		num/=d;
	}
	
	display(S);
	
	return 0;
}

