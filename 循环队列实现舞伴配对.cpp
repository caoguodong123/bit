//数组实现xunhuan队列 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
	int sex;//0代表男生，1 代表女生
	char name[20]; 
}Data;
typedef struct{
	Data *base;
	int rear;
	int front;
}Queue;

void InitQueue(Queue &Q){
	Q.base=(Data *)malloc(MAX*sizeof(Data));
	Q.front=Q.rear=0;
}

int QueueEmpty(Queue Q){
	if(Q.front==Q.rear)
		return 1;
		
	return 0;
}

int QueueFull(Queue Q){
	if((Q.rear+1+MAX)%MAX==Q.front)
		return 1;
	return 0;
}

void EntryQueue(Queue &Q,int e,char s[] ){
	if(QueueFull(Q))
		return;
		
	Q.base[Q.rear].sex=e;
	strcpy(Q.base[Q.rear].name,s);
	Q.rear=(Q.rear+1)%MAX;
	
}

void OutQueue(Queue &Q,int &e,char *s){
	if(QueueEmpty(Q))
		return;
	e=Q.base[Q.front].sex;
	strcpy(s,Q.base[Q.front].name);
	Q.front=(Q.front+1)%MAX;
	
}

void GetTop(Queue Q,int &e,char *s){
	if(QueueEmpty(Q)){
		return ;
	}
	
	e=Q.base[Q.front].sex;
	strcpy(s,Q.base[Q.front].name);
}

void display(Queue Q){
	int x = (Q.rear-Q.front+MAX)%MAX;
	int i,j;
	i=Q.front;j=Q.rear;
	if(i<=j){
		while(i<j){
			printf("%s %d\t",Q.base[i].name,Q.base[i].sex);
			i++;
		}
	}else{
		while(i!=j){
			printf("%s %d\t",Q.base[i].name,Q.base[i].sex);
			i=(i+1)%MAX;
		}

	}
	
}

int length(Queue Q){
	if(Q.rear>Q.front)
		return Q.rear-Q.front;
	return Q.rear+MAX-Q.front;
}

void inputQ(Queue &Q){
	int i,j;
	int sex;
	char s[20];
	printf("you will input how many man for man:");
	scanf("%d",&i);
	j=0;
	while(j<i){
		printf("please input the name :");
		getchar();
		gets(s);
		printf("please input the sex 0 or 1:");
		scanf("%d",&sex);
		EntryQueue(Q,sex,s);	
		j++;
	}
	
	
	display(Q);
	putchar('\n');
	
}

void Match(Queue &QM,Queue &QF){
	int num;
	int i,j;
	int lm,lf;
	int sexM,sexF;
	char nameM[20],nameF[20];
	
	lm=length(QM);
	lf=length(QF);
	printf("please input you will Match how much times:");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		if(lm<lf){
			for(j=0;j<lm;j++){
				OutQueue(QM,sexM,nameM);
				EntryQueue(QM,sexM,nameM);
				OutQueue(QF,sexF,nameF);
				EntryQueue(QF,sexF,nameF);
				printf("%s %s\n",nameM,nameF);
			}	
			GetTop(QF,sexF,nameF);
			printf("下一出场者姓名：%s\n",nameF);	
		
			putchar('\n');
		}else if(lm>lf){
			for(j=0;j<lf;j++){
				OutQueue(QM,sexM,nameM);
				EntryQueue(QM,sexM,nameM);
				OutQueue(QF,sexF,nameF);
				EntryQueue(QF,sexF,nameF);
				printf("%s %s\n",nameM,nameF);
			}
			GetTop(QM,sexM,nameM);
			printf("下一出场者姓名：%s\n",nameM);	
			putchar('\n');
		}else{
			for(j=0;j<lm;j++){
				OutQueue(QM,sexM,nameM);
				EntryQueue(QM,sexM,nameM);
				OutQueue(QF,sexF,nameF);
				EntryQueue(QF,sexF,nameF);
				printf("%s %s\n",nameM,nameF);
			}	
			putchar('\n');
		}
	}
	
}

int main(){
	Queue QM,QF;
	InitQueue(QM);
	InitQueue(QF);
	inputQ(QM);
	inputQ(QF);
	
	Match(QM,QF);
	
	

	
	return 0;
}
