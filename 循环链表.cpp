//Ñ­»·Á´±í 
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void creatList(LinkList &L){
	LinkList p,temp,rear;
	int x;
	p=(LinkList)malloc(sizeof(LNode));
	L=p;
	scanf("%d",&x);
	while(x){
	temp=(LinkList)malloc(sizeof(LNode));
	temp->data=x;
	p->next=temp;
	p=temp;
	scanf("%d",&x);
		
	}
	p->next=L->next;
	L=p;	
}

void insertList(LinkList &L,int i,int e){
	int x=1;
	LinkList p,temp;
	p=L->next;
	while(x<i-1){
		p=p->next;
		x++;
	}
	
	temp=(LinkList)malloc(sizeof(LNode));
	temp->data=e;
	temp->next=p->next;
	p->next=temp; 
	
}

void deleteList(LinkList &L,int i,int &e){
	int x=1;
	LinkList p,temp;
	p=L->next;
	while(x<i-1){
		p=p->next;
		x++;
	}
	temp=p->next;
	p->next=temp->next;
	free(temp);
	
}

void display(LinkList L){
		LinkList p;
		p=L->next;
		printf("%d\t",p->data);
		while(p!=L){
			p=p->next;
			printf("%d\t",p->data);
			
		}
		
}

int main(){
	int e;
	LinkList L;
	creatList(L);
	insertList(L,1,5);
	display(L);
	deleteList(L,2,e);
	display(L);
	
	return 0;
}
