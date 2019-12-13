#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType coef;
	ElemType expn;
	struct LNode *next;	
}LNode,*LinkList;

void Input_Tail(LinkList &L){
	//β�巨ʵ������ 
	LinkList follow;
	LinkList newNode;
	int x;
	int y; 
	newNode = (LinkList)malloc(sizeof(LNode));
	L=newNode;
	
	
	follow=L;
	scanf("%d,%d",&x,&y);
	
	do{
		newNode = (LinkList)malloc(sizeof(LNode));
		newNode->coef=x;
		newNode->expn=y;
		follow->next=newNode;
		follow=newNode;
		scanf("%d,%d",&x,&y);
	}while(x!=0 || y!=0);
	follow->next=NULL;
}

void Input_Head(LinkList &L){
	//ͷ�巨ʵ������
	LinkList newNode;
	int x;
	int y;
	scanf("%d,%d",&x,&y);
	L->next=NULL;
	do{
		newNode = (LinkList)malloc(sizeof(LNode));
		newNode->coef=x;
		newNode->expn=y;
		newNode->next=L->next;
		L->next=newNode;
		scanf("%d,%d",&x,&y);
	}while(x!=0 || y!=0);
	
	
	 
}



void Insert(LinkList &L,int i,ElemType coef,ElemType expn){
	// ��iλ��ǰ����Ԫ��e
	LinkList temp;
	LinkList newNode;
	
	int x=1;
	temp=L->next;
	while(x!=i-1){
		temp=temp->next;
		x+=1;
	}
	
	newNode=(LinkList)malloc(sizeof(LNode));
	newNode->coef=coef;
	newNode->expn=expn;
	newNode->next=temp->next;
	temp->next=newNode; 
	
	 
}

void add(LinkList &La,LinkList &Lb){
	//����ʽ��� 
	LinkList pa,pb,pre,temp;
	int x;
	pa=La->next;
	pb=Lb->next;
	pre=La;
	
	
	while(pa&&pb){
		if(pa->expn<pb->expn){
			pre=pa;
			pa=pa->next;
		}else if(pa->expn==pb->expn){
			x=pa->coef+pb->coef;
			if(x){
				pa->coef=x;
				pre=pa;
				pa=pa->next;
			}else{
				pre->next=pa->next;
				free(pa);
				pa=pre->next;
			}
			temp=pb;pb=pb->next;free(temp);
		}else{
			pre->next=pb;pre=pb;pb=pb->next;pre->next=pa;
		}
	}
	if(pb){
		pre->next=pb;
	}
	
	free(Lb);
}


int length(LinkList L){
	//���� 
	LinkList temp;
	int x = 0;
	temp=L->next;
	while(temp){
		x++;
		temp=temp->next;
	}
	
	return x;
}


void display(LinkList L){
	//չʾ���� 
	LinkList follow;
	follow=L->next;
	while(follow){
		printf("%d,%d\t",follow->coef,follow->expn);
		follow=follow->next;
	}
	putchar('\n');
}


void QiuDao(LinkList &La){
	//�� 
	LinkList pa,fa,temp;
	pa=La->next;
	fa=La;
	if(pa->expn==0){
			temp=pa;
			pa=pa->next;
			fa->next=pa;
			free(temp);
			} 
	while(pa){
			pa->coef=(pa->expn)*(pa->coef);
			pa->expn=pa->expn-1;
			fa=pa;
			pa=pa->next;
		
	}
}

int main(){
	LinkList La,Lb,Lc;
	int x;
	Input_Tail(La);
	//Input_Tail(Lb);
	display(La);
	//display(Lb);
	//add(La,Lb);
	QiuDao(La);
	display(La);
	
	
	
	return 0;
}
