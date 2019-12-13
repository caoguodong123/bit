//邻接表存储图 

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int visited[MAX]={0};
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;


typedef struct VNode{
	char data;
	ArcNode *firstArc;
	
}VNode,AdjList[MAX];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

typedef struct ArcCell{
	int adj;
}ArcCell,AdjMatrix[MAX][MAX];

typedef struct {
	char vexs[MAX];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;

typedef struct Node{
	ArcNode *data;
	struct Node *next;
	
}Node,*SqStack;



typedef struct QNode{
	ArcNode *data;
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

void EnQueue(Queue &Q,ArcNode* e){
	L temp;
	temp=(L)malloc(sizeof(QNode));
	temp->data=e;
	Q.rear->next=temp;
	Q.rear=temp;
}

void DeQueue(Queue &Q,ArcNode* &e){
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




void InitStack(SqStack &S){
	S=(SqStack)malloc(sizeof(Node));
	S->next=NULL;
}

void Push(SqStack &S,ArcNode* e){
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

void Pop(SqStack &S,ArcNode* &e){
	SqStack temp;
	
	if(StackEmpty(S))
		return;
	
	temp=S->next;
	e=temp->data;
	S->next=temp->next;
	free(temp);
}

void GetTop(SqStack S,ArcNode* &e){
	if(StackEmpty(S))
	{
		e=NULL;
		return;
	}
		
		
	e=S->next->data;
}



int LocationVex(ALGraph G,char c){
	int i;
	printf("i am run\n");
	for(i=0;i<G.vexnum;i++){
		if(G.vertices[i].data==c)
		{
			printf("i am %d\n",i);
			return i;
		}
			
		
	}
	
	return -1;
}

void CreatALGraph(ALGraph &G){
	int vexnum,arcnum;
	int i,j,k;
	char c,v1,v2;
	ArcNode *newArc,*p;
	
	printf("please input the vexnum and arcnum:");
	scanf("%d%d",&vexnum,&arcnum);
	G.arcnum=arcnum;
	G.vexnum=vexnum;
	getchar();
	for(i=0;i<vexnum;i++){
		printf("please input the vex data:");
		scanf("%c",&c);
		getchar();
		G.vertices[i].data=c;
		printf("%c\n",G.vertices[i].data);
		G.vertices[i].firstArc=NULL;
	}
	
	
	for(k=0;k<arcnum;k++){
		printf("please input the arc:\n");
		scanf("%c%c",&v1,&v2);
		getchar();
		printf("%c%c\n",v1,v2);
		i=LocationVex(G,v1);
		j=LocationVex(G,v2);
		printf("%d %d\n",i,j);
		newArc=(ArcNode *)malloc(sizeof(ArcNode));
		newArc->adjvex=j;
		newArc->next=NULL;
		
		p=G.vertices[i].firstArc; 
		if(!p){
			G.vertices[i].firstArc=newArc;
		}else{
			while(p->next){
				p=p->next;
			}
			p->next=newArc;
		}
		
	}
	
}

void visit(ALGraph G,int v){
	printf("%c\n",G.vertices[v].data);
}

void DFS(ALGraph G,int v){
	ArcNode *p;
	visited[v]=1;
	visit(G,v);
	for(p=G.vertices[v].firstArc;p;p=p->next){
		if(visited[p->adjvex]!=1){
			DFS(G,p->adjvex);
		}
	}
}


void dfs(ALGraph G,int v){
	//从第v个顶点遍历图
	ArcNode *newNode,*p;
	SqStack S;
	visited[v]=1;
	visit(G,v);
	p=G.vertices[v].firstArc;
	
	InitStack(S);
	while(p || !StackEmpty(S)){
		while(p){
			if(visited[p->adjvex]){
				p=p->next;	
			}else{
				visited[p->adjvex]=1;
				visit(G,p->adjvex);
				Push(S,p);
				p=G.vertices[p->adjvex].firstArc;
			}	
		}
		
		if(!StackEmpty(S)){
			Pop(S,p);
			p=p->next;
		}
		
	}
}


void DFSTraverse(ALGraph G){
	int i;
	
	for(i=0;i<G.vexnum;i++){
		visited[i]=0; 
	}
	for(i=0;i<G.vexnum;i++){
		if(visited[i]==0){
			DFS(G,i);
			//dfs(G,i);
		}
			
	}
}


void dfsTraverse(ALGraph G){
	int i;
	
	for(i=0;i<G.vexnum;i++){
		visited[i]=0; 
	}
	for(i=0;i<G.vexnum;i++){
		if(visited[i]==0){
			dfs(G,i);
		}
			
	}
}

void BFS(ALGraph G,int v){
	ArcNode *p;
	Queue Q;
	int i;
	InitQueue(Q);
	visit(G,v);
	while(p || !QueueEmpty(Q)){
		while(p){
			visit(G,p->adjvex);
			EnQueue(Q,G.vertices[p->adjvex].firstArc);
			p=p->next;
		}
		
		if(!QueueEmpty(Q)){
			DeQueue(Q,p);
		}		
	}
	
}

void BFSTraverse(ALGraph G){
	int i;
	for(i=0;i<G.vexnum;i++){
		visited[i]=0;
	}
	
	for(i=0;i<G.vexnum;i++){
		if(visited[i]!=1){
			BFS(G,i);
		}
	}
} 


void InitMGraph(MGraph &MG){
	int i,j;
	for(i=0;i<MG.vexnum;i++){
		for(j=0;j<MG.vexnum;j++){
			MG.arcs[i][j].adj=0;
		}
	}
}
void displayMG(MGraph &MG){
	int i,j;
	for(i=0;i<MG.vexnum;i++){
		for(j=0;j<MG.vexnum;j++){
			printf("%d ",MG.arcs[i][j]);
		}
		putchar('\n');
	}
}

void dfs1(ALGraph G,MGraph &MG,int v){
	//从第v个顶点遍历图
	ArcNode *newNode,*p,*q;
	SqStack S;
	visited[v]=1;
	
	p=G.vertices[v].firstArc;
	
	InitStack(S);
	while(p || !StackEmpty(S)){
		while(p){
			if(visited[p->adjvex]){
				p=p->next;	
			}else{
				visited[p->adjvex]=1;
				//visit(G,p->adjvex);
				GetTop(S,q);
				if(q){
					MG.arcs[q->adjvex][p->adjvex].adj=1;
				}else{
					MG.arcs[0][p->adjvex].adj=1;
				}
				Push(S,p);
				p=G.vertices[p->adjvex].firstArc;
			}	
		}
		
		if(!StackEmpty(S)){
			Pop(S,p);
			p=p->next;
		}
		
	}
}

void dfsTraverse1(ALGraph G,MGraph &MG){
	int i;
	
	for(i=0;i<G.vexnum;i++){
		visited[i]=0; 
	}
	for(i=0;i<G.vexnum;i++){
		if(visited[i]==0){
			dfs1(G,MG,i);
		}
			
	}
}


void Transform(ALGraph AG,MGraph &MG){
	int i;
	
	MG.arcnum=AG.arcnum;
	MG.vexnum=AG.vexnum;
	
	for(i=0;i<AG.vexnum;i++){
		MG.vexs[i]=AG.vertices[i].data;
	}
	InitMGraph(MG);
	dfsTraverse1(AG,MG);
	
		
}


int main(){
	
	ALGraph G;
	MGraph MG;
	CreatALGraph(G);
	DFSTraverse(G);
	dfsTraverse(G);
	BFSTraverse(G);
	Transform(G,MG);
	displayMG(MG);
	return 0;
}


