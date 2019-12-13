#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char data;
	struct Node *next;
	
}Node,*SqStack;


void InitStack(SqStack &S){
	S=(SqStack)malloc(sizeof(Node));
	S->next=NULL;
}

void Push(SqStack &S,char e){
	SqStack temp;
	temp=(SqStack)malloc(sizeof(Node));
	temp->data=e;
	temp->next=S->next;
	S->next=temp;
}

int StackEmpty(SqStack S){
	if(S->next==NULL)
		return 1;
	return 0;
}

void Pop(SqStack &S,char &e){
	SqStack temp;
	
	if(StackEmpty(S))
		return;
	
	temp=S->next;
	e=temp->data;
	S->next=temp->next;
	free(temp);
}

void GetTop(SqStack S,char &e){
	if(StackEmpty(S))
		return;
		
	e=S->next->data;
}

void display(SqStack S){
	SqStack temp;
	temp=S->next;
	while(temp){
		printf("%c",temp->data);
		temp=temp->next;
	}
	putchar('\n');
}

int main(){
	SqStack S;
	char c,d;
	int i;
	InitStack(S);
	printf("please input the String:\n");
	while((c=getchar())!='0'){
		if(c=='(' || c=='[' || c=='{'){
			Push(S,c);
		}else if(c==')'){
			if(StackEmpty(S)){
				printf("≤ª∆•≈‰\n");
				return 0;
			}
			
			Pop(S,d);
			if(d=='('){
				continue;
			}else{
				printf("≤ª∆•≈‰\n");
				return 0;
			}
		}else if(c==']'){
			if(StackEmpty(S)){
				printf("≤ª∆•≈‰\n");
				return 0;
			}
			
			Pop(S,d);
			if(d=='['){
				continue;
			}else{
				printf("≤ª∆•≈‰\n");
				return 0;
				
				} 
			
		}else if(c=='}'){
			if(StackEmpty(S)){
				printf("≤ª∆•≈‰\n");
				return 0;
			}
			
			Pop(S,d);
			if(d=='{'){
				continue;
			}else{
				printf("≤ª∆•≈‰\n");
				return 0;
			
		}		
	}
	} 
	 
	if(StackEmpty(S))
		printf("∆•≈‰\n");
	else
		printf("≤ª∆•≈‰\n");
	return 0;
}

