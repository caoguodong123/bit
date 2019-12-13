 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct DLNode{
 	int data;
 	struct DLNode *pre;
 	struct DLNode *next;
 	
 }DLNode,*DLinkList;
 
 void Input_Tail(DLinkList &L){
	DLinkList p,temp;
	int x;
	temp = (DLinkList)malloc(sizeof(DLNode));
	L = temp; L->pre=NULL;L->next=NULL;
	p=L;
	
	
	do{
		scanf("%d",&x);
		temp = (DLinkList)malloc(sizeof(DLNode));
		temp->data=x;
		p->next=temp;
		temp->pre=p;
		p=temp;
	} while(x);
	p->next=NULL;
			
 }
 
 void display(DLinkList L){
 	DLinkList p;
 	p=L->next;
 	while(p){
 		printf("%d\t",p->data);
 		p=p->next;
	}
 }
 
DLinkList search(DLinkList &L,int i){
	DLinkList p;
	int x=1;
	p=L->next;
	while(x<i){
		p=p->next;
		x++;
	}	
	
	printf("\n%d\n",p->data);
	
	return p;
}
 
 
void InsertList(DLinkList &L,int i,int e){
//在第i个元素之前插入一个元素 
	DLinkList p,temp,pn;
	temp=search(L,i-1);
	pn=temp->next; 
	
	p=(DLinkList)malloc(sizeof(DLNode));
	p->data=e;
	
	pn->pre=p;
	p->next=pn;
	p->pre=temp;
	temp->next=p;
		
}

void DeleteList(DLinkList &L,int i ,int &e){
	DLinkList temp,p;
	temp=search(L,i-1);
	p=temp->next; 
	e=p->data;
	p->next->pre=temp;
	temp->next=p->next;
	free(p);
}
 
 int main(){
 	DLinkList La;
 	int x;
 	Input_Tail(La);
 	display(La);
 //	InsertList(La,3,5);
//	display(La);
 	DeleteList(La,4,x);
 	display(La);
 	
 	return 0;
 }
