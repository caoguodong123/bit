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


typedef struct Node{
	ArcNode *data;
	struct Node *next;
	
}Node,*SqStack;


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
		return;
		
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


int main(){
	
	ALGraph G;
	CreatALGraph(G);
	DFSTraverse(G);
	dfsTraverse(G);
	return 0;
}


