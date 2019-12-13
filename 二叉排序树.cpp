#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define INCREMENT 10

typedef int TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


typedef struct{
	int top;
	int stacksize;
	BiTree *data;
}SqStack;

void InitStack(SqStack &S){
	S.data=(BiTree *)malloc(MAX*sizeof(BiTree));
	S.stacksize=MAX;
	S.top=0;
}

int StackEmpty(SqStack S){
	if(S.top==0)
		return 1;
	return 0;
}

void GetTop(SqStack S,BiTree &bt){
	if(!StackEmpty(S)){
		bt=S.data[S.top-1];
	}
	return;
}

int GetTop1(SqStack S,BiTree &bt){
	if(!StackEmpty(S)){
		bt=S.data[S.top-1];
		return 1;
	}
	return 0;
}


void Push(SqStack &S,BiTree bt){
	S.data[S.top++]=bt;
	if(S.top==S.stacksize)
	{
		S.data=(BiTree *)realloc(S.data,(S.stacksize+INCREMENT)*sizeof(BiTree));
		S.stacksize+=INCREMENT;
	}
}

void Pop(SqStack &S,BiTree &bt){
	if(!StackEmpty(S))
		bt=S.data[--S.top];
	return ;
}



void InOrderTraverse(BiTree bt){
	//中序遍历 空不进栈 
	BiTree p;
	SqStack S;

	printf("InOrderTraverse:\n");
	if(bt){
		p=bt;
		InitStack(S);
		while(p || !StackEmpty(S)){
			while(p){
				Push(S,p);
				p=p->lchild;
			}

			if(!StackEmpty(S)){
				Pop(S,p);
				printf("%d  ",p->data);
				p=p->rchild;
			}	
		}
	}
	putchar('\n');
}

void InOrderTraverse_1(BiTree bt){
	//中序遍历 空进栈 
	BiTree p;
	SqStack S;
	
	printf("InOrderTraverse:\n");
	if(bt){
		InitStack(S);
		Push(S,bt);
		while(!StackEmpty(S)){
			while(GetTop1(S,p) && p){
				Push(S,p->lchild);
			}
			
			Pop(S,p);
			
			if(!StackEmpty(S)){
				Pop(S,p);
				printf("%d  ",p->data); 
				Push(S,p->rchild);
			}
			
			
		}
		
	}
	putchar('\n');
}


void CreatSearchBiTree(BiTree &bst,int *a,int n){
	int i;
	BiTree p,f,s;
	if(n<1){
		bst=NULL;
		return;
	}
	
	bst=(BiTree)malloc(sizeof(BiTNode));
	bst->data=a[0];
	bst->lchild=NULL;
	bst->rchild=NULL;
	for(i=1;i<n;i++){
		p=bst;f=NULL;
		while(p){
			if(p->data==a[i]){
				break;
			}else if(p->data<a[i]){
				f=p;
				p=p->rchild;
			}else{
				f=p;
				p=p->lchild;
			}
		}
		
		if(!p){
					
			s=(BiTree)malloc(sizeof(BiTNode));
			s->data=a[i];
			s->lchild=NULL;
			s->rchild=NULL;
			if(!f->lchild){
				f->lchild=s;
			}else{
				f->rchild=s;
			}
		}
	}	
}

BiTree SearchBST(BiTree T,int key){
	if(!T){
		return NULL;
	}
	if(T->data==key){
		return T;
	}else if(T->data<key){
		return SearchBST(T->rchild,key);
	}else{
		return SearchBST(T->lchild,key);
	}
}

int SearchBST1( BiTree T, int key, BiTree f, BiTree &p ){
	if(!T){
		p=f;
		return 0;
	}
	if(T->data==key){
		p=T;
		return 1;
	}else if(T->data<key){
		return SearchBST1(T->rchild,key,T,p);
	}else{
		return SearchBST1(T->lchild,key,T,p);
	}
}

void InsertBST( BiTree &T, int e ){
	BiTree p,f,s;
	if(!SearchBST1(T,e,NULL,p)){
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=e;
		s->lchild=NULL;
		s->rchild=NULL;
		if(p->lchild){
			p->rchild=s;
		}else{
			p->lchild=s;
		}
	}
}


int main(){
	BiTree bt;
	int *a,n,i;
	
	printf("please input you will input how many num:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		printf("%d",a[i]);
	}
	
	CreatSearchBiTree(bt,a,n);
	InOrderTraverse_1(bt);
	//InsertBST(bt,0);
	//InOrderTraverse(bt);
	
	
	return 0;
}
