#include <stdio.h>
#include <stdlib.h>
#define MAX 20






typedef struct QNode{
	int data;
	struct QNode *next;
}QNode , *L;

typedef struct Queue{
	L rear;
	L front;
}Queue; 

void InitQueue(Queue &Q){
	Q.front = (L)malloc(sizeof(QNode));
	Q.rear = Q.front;
	Q.front->next=NULL;
}

int QueueEmpty(Queue Q){
	if(Q.front==Q.rear)
		return 1;
	return 0;
}

void EnQueue(Queue &Q,int e){
	L temp;
	temp=(L)malloc(sizeof(QNode));
	temp->data=e;
	Q.rear->next=temp;
	Q.rear=temp;
}

void DeQueue(Queue &Q,int &e){
	L temp;
	if(QueueEmpty(Q))
		return ;
	temp=Q.front->next;
	if(temp==Q.rear){
		Q.rear=Q.front;
		Q.front->next=NULL;
		e=temp->data;
		free(temp);
	}else{
		Q.front->next=temp->next;
		e=temp->data;
		free(temp);
	}
}


typedef struct Node{
	int data;
	struct Node *next;
	
}Node,*SqStack;



void InitStack(SqStack &S){
	S=(SqStack)malloc(sizeof(Node));
	S->next=NULL;
}

void Push(SqStack &S,int e){
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

void Pop(SqStack &S,int &e){
	SqStack temp;
	
	if(StackEmpty(S))
		return;
	
	temp=S->next;
	e=temp->data;
	S->next=temp->next;
	free(temp);
}

void GetTop(SqStack S,int &e){
	if(StackEmpty(S))
	{
		e=NULL;
		return;
	}
		
		
	e=S->next->data;
}


int visited[MAX]={0};
typedef struct ArcCell{
	int adj;
}ArcCell,AdjMatrix[MAX][MAX];

typedef struct {
	char vexs[MAX];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;


int LocationVex(MGraph G,char c){
	int i;
	printf("i am run\n");
	for(i=0;i<G.vexnum;i++){
		if(G.vexs[i]==c)
		{
			printf("i am %d\n",i);
			return i;
		}
			
		
	}
	
	return -1;
}


void CreatGraph(MGraph &G){
	int i,j,k;
	char a,b;
	
	printf("please input the Graph vex and arc:");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;i++){
		printf("please input the Graph Vexs:");
		scanf("%c",&G.vexs[i]);
		getchar();	
		printf("%c\n",G.vexs[i]);
	}
	
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			G.arcs[i][j].adj=0;
		}
	}
	
	for(i=0;i<G.arcnum;i++){
		printf("please input the arc:");
		scanf("%c%c",&a,&b);
		getchar();
		j=LocationVex(G,a);
		k=LocationVex(G,b);
		G.arcs[j][k].adj=1;
		G.arcs[k][j].adj=1;
	}
}

void DFS(MGraph G,int num){
	int i;
	visited[num]=1;
	printf("%c  ",G.vexs[num]);
	for(i=0;i<G.vexnum;i++){
		if(!visited[i] && G.arcs[num][i].adj==1){
			DFS(G,i);
		}
		
	}
}


void dfs(MGraph G,int v){
	//从第v个顶点遍历图
	//ArcNode *newNode,*p;
	int i,j,k;
	SqStack S;
	InitStack(S);  
    Push(S,v);  
    printf("%c  ",G.vexs[v]);  
    visited[v] = 1;  

	
	

	while(!StackEmpty(S)){
	
		GetTop(S,i);
		
		for(j=0;j<G.vexnum;j++){
			if(G.arcs[i][j].adj && !visited[j]){
				Push(S,j);
				printf("%c  ",G.vexs[j]);
				visited[j]=1;
				
				i=j;
				j=0;
			}
		}
		
		
		if(!StackEmpty(S)){  
            Pop(S,k);  
        }  
	}
}





void DFSTraveres(MGraph G){
	int i;
	
	for(i=0;i<G.vexnum;i++){
		visited[i]=0;
	}
	
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){
			dfs(G,i);
			//DFS(G,i);
		}
	}
}

void BFSTraveres(MGraph G){
	int i,j,k;
	int count1=0;
	int count2=0;
	Queue Q;
	for(i=0;i<G.vexnum;i++){
		visited[i]=0;
	}
	InitQueue(Q);
	
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){
			visited[i]=1;
			printf("%c  ",G.vexs[i]);
			count1++;
			for(j=0;j<G.vexnum;j++){
				if(!visited[j] && G.arcs[i][j].adj==1){
					EnQueue(Q,j);
					visited[j]=1;
				}
			}
			
			while(!QueueEmpty(Q)){
				DeQueue(Q,k);
				printf("%c  ",G.vexs[k]);
				
				for(j=0;j<G.vexnum;j++){
					if(!visited[j] && G.arcs[k][j].adj==1){
						EnQueue(Q,j);
						visited[j]=1;
						count2++;
					}
				}
			
			}
			
		}
	}
	
	printf("\n%d  %d\n",count1,count2);
}

int main(){
	MGraph G1;
	
	CreatGraph(G1);
	DFSTraveres(G1);
	printf("\n----------\n");
	BFSTraveres(G1);
	
}
