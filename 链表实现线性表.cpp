#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;//������ 
	struct LNode *next;	//ָ���� 
}LNode,*LinkList;

void Input_Tail(LinkList &L){
	//β�巨ʵ������ 
	LinkList follow;
	LinkList newNode;
	int x;

	follow=L;//����ڵ� 
	scanf("%d",&x);
	
	do{
		newNode = (LinkList)malloc(sizeof(LNode));
		newNode->data=x;//�����½ڵ㲢��ʼ�� 
		follow->next=newNode;
		follow=newNode;
		scanf("%d",&x);
	}while(x);
	follow->next=NULL;
}

void Input_Head(LinkList &L){
	//ͷ�巨ʵ������
	LinkList newNode;
	int x;
	scanf("%d",&x);
	L->next=NULL;//��ʼ�� 
	do{
		newNode = (LinkList)malloc(sizeof(LNode));
		newNode->data=x;
		newNode->next=L->next;
		L->next=newNode;
		scanf("%d",&x);
	}while(x);
	
	
	 
}

int search1(LinkList L,int data){
	//����һ��Ԫ�أ���������λ�� 
	int count=1;
	LinkList follow=L->next;
	
	while(follow && (follow->data!=data)){
		count++;
		follow=follow->next;
	}
	
	if(follow){
		return count;
	}	
	
	return 0;
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
		count++;
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
void Delete(LinkList &L,int i,ElemType &e){
	LinkList pre,temp;
	pre = search(L,i-1);
	temp = pre->next;
	
	e=temp->data;
	pre->next = temp->next;
	free(temp); 
} 


int length(LinkList L){
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
		printf("%d\t",follow->data);
		follow=follow->next;
	}
	putchar('\n');
} 

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){
	//�鲢������������Lc ��С����
	LinkList la,lb,lc,temp;
	Lc=La;
	lc=Lc;
	la=La->next;
	lb=Lb->next;
	while(la&&lb){
		if(la->data<lb->data){
			lc->next=la;
			lc=la;
			la=la->next;
			
		}else if(la->data>lb->data){
			lc->next=lb;
			lc=lb;
			lb=lb->next;
			
		}else{
			lc->next=la;
			lc=la;
			la=la->next;
			temp=lb;
			lb=lb->next;
			free(temp);
		}
	
	}

	(la==NULL)? lc->next=lb:lc->next=la;
	free(Lb);
}

void MergeList1(LinkList &La,LinkList &Lb,LinkList &Lc){
	//�鲢������������Lc �Ӵ󵽵�С 
	LinkList la,lb,lc,temp;
	Lc=lc=La;
	la=La->next;
	lb=Lb->next;
	Lc->next=NULL;
	while(la&&lb){
		if(la->data<lb->data){
			lc=la;
			la=la->next;
			lc->next=Lc->next;
			Lc->next=lc;
			
		}else if(la->data>lb->data){
			lc=lb;
			lb=lb->next;
			lc->next=Lc->next;
			Lc->next=lc;
		}else{
			lc=la;
			la=la->next;
			lc->next=Lc->next;
			Lc->next=lc; 
			temp=lb;
			lb=lb->next;
			free(temp);
		}
		
		
	} 
	
	while(la){
		lc=la;
		la=la->next;
		lc->next=Lc->next;
		Lc->next=lc;
	}
	
	while(lb){
		lc=lb;
		lb=lb->next;
		lc->next=Lc->next;
		Lc->next=lc;
	}
	
	free(Lb);
}


void reversal(LinkList &L){
	//�͵�����
	LinkList r,q,p;
	p=L->next; 
	q=NULL;
	while(p){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	L->next=q;
}

void Search(LinkList L,int k){
	//ɨ��һ���ҳ�������K��Ԫ�ز����
	//��������������a������b��a����k��Ԫ�غ�b��ʼ������
	//��a�ߵ����һ��Ԫ�أ�b�պ��ߵ�������k��Ԫ�� 
	LinkList a,b;
	b=L->next;
	int count=1;
	
	while(b){
		if(count==k){
			a=L->next;
			b=b->next;
			count++;
			
		}else if(count>k){
			a=a->next;
			b=b->next;
		}else{
			b=b->next;
			count++;
		}
	} 
	
	printf("\n%d\n",a->data);
}
void InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

int main(){
	LinkList L,La,Lb,Lc;
	int x;
	InitList(L);
	Input_Tail(L);
	display(L);
//	Input_Head(L);
//	display(L);
//	Input_Tail(La);
//	Input_Tail(Lb);
//	display(La);
//	display(Lb);
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
