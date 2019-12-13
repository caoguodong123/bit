//����ʵ�����Ա� 
#include<stdio.h>
#include<stdlib.h>
#define INITMAX 100
#define ADD 10
 
typedef int ElemType;
typedef struct{
	ElemType *data;
	int length;//��ǰ����洢���� 
	int listsize;//��ǰ����������� 
}Sqlist;

void InitList(Sqlist &L){ 
	//��ʼ�����Ա� 
	L.data=(ElemType *)malloc(INITMAX*sizeof(ElemType)); 
	L.length=0;
	L.listsize=INITMAX;
	
}

void addCapicity(Sqlist &L){
	//����
	 L.data=(ElemType *)realloc(L.data,ADD*sizeof(ElemType));
	 L.listsize+=ADD;
}

int ListLength(Sqlist L){
	//�õ����� 
	return L.length;
} 

void ListInsert(Sqlist &L,int i,ElemType e){
	//�ڵ�I��λ�ò���Ԫ �� 
	int j,k=0;
	int q;
	q=i;
	if(i<1){
		exit(0);
	}
	
	if(L.length+1>L.listsize)
		addCapicity(L);
		 
	for(j=L.length-1;j>=q;j--){
		L.data[j+1]=L.data[j];
	}
	
	L.data[q]=e;
	L.length++;
	
}

void ListDelete(Sqlist &L,int i,ElemType &e){
	int j;
	e=L.data[i-1];
	for(j=i-1;j<L.length-1;j++){
		L.data[j]=L.data[j+1];
	}
	L.data[j]=0;
	L.length--;
}



void display(Sqlist L){
	int i;
	for(i=0;i<L.length;i++){
		printf("%d\t",L.data[i]);
	}
	printf("\n");
}

int LocateElem(SqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;
	}
	
	return -1;
	
}

int main(){
	Sqlist L;
	int x;
	int i=0;
	InitList(L);
	scanf("%d",&x);
	
	do{
		ListInsert(L,i++,x);
		scanf("%d",&x);
	
	}while(x);
	
	display(L);
	
	
	
	
	return 0;
}
