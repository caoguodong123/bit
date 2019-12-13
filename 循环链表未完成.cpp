#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;	
}LNode,*LinkList;

void Input_Tail(LinkList &){
	//β�巨ʵ������ 
	LinkList follow;
	LinkList newNode;
	int x;
	newNode = (LinkList)malloc(sizeof(LNode));
	L=newNode;
	
	
	follow=L;
	scanf("%d",&x);
	
	do{
		newNode = (LinkList)malloc(sizeof(LNode));
		newNode->data=x;
		follow->next=newNode;
		follow=newNode;
		scanf("%d",&x);
	}while(x);
	follow->next=NULL;
}




LinkList search(LinkList L,int x){
	//��λ�����Ԫ�أ���������Ԫ�� 
	int count=0;
	LinkList follow;
	follow = L;
	while(follow){
		if(count==x){
			return follow;
		}
		follow=follow->next;
	}
	
	return NULL;	
}

void Insert(LinkList &L,int i,ElemType e){
	// ��iλ��ǰ����Ԫ��e
	LinkList temp;
	LinkList newNode;
	temp=search(L,i-1);
	newNode=(LinkList)malloc(sizeof(LNode));
	newNode->data=e;
	newNode->next=temp->next;
	temp->next=newNode; 
	
	 
}



void display(LinkList L){
	//չʾ���� 
	LinkList follow;
	follow=L->next;
	while(follow){
		printf("%d\t",follow->data);
		follow=follow->next;
	}
	putchar('\n');
}



int main(){
	LinkList La,Lb,Lc;
	int x;
	Input_Tail(La);
	Input_Tail(Lb);
	display(La);
	display(Lb);
	//scanf("%d",&x);
	//printf("\n%d\n",search1(L,x));
	//Insert(L,1,0);
	MergeList(La,Lb,Lc);
	display(Lc);
	//reversal(La);
	//display(La);
	
	//reversalSearch(La,3);
	
	//printf("\n%d",length(La));
	
	return 0;
}
