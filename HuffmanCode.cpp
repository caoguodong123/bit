#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;


void Select(HuffmanTree HT,int n,int &s1,int &s2){
	int i;
	int min1,min2;
	int flag=0;
	int temp;
	for(i=1;i<=n;i++){
		if(HT[i].parent==0){
			if(flag==0){
				min1=i;
				flag=1;
			}
			if(HT[i].weight<=HT[min1].weight){
				min1=i;
			}
			
		}
	}
	flag=0;
	for(i=1;i<=n;i++){
			
		if(HT[i].parent==0 && min1!=i){
			if(flag==0){
				min2=i;
				flag=1;
			}
			if(HT[i].weight==HT[min1].weight){
					continue;
			}else if(HT[i].weight<=HT[min2].weight)
				min2=i;
			
		}
	}
	s1=min1;
	s2=min2;
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	int m,i;
	int s1,s2;
	int start;
	int c,f;
	char *cd;
	int j;
	
	if(n<=1){
		return;
	}
	
	m=n*2-1;
	
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1;i<=n;i++){
		HT[i].weight=*(w+i-1);
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].parent=0;
		printf("\n%d,%d,%d,%d",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
	
	for(i=n+1;i<=m;i++){
		HT[i].weight=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].parent=0;
		printf("\n%d,%d,%d,%d",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
	
	for(i=n+1;i<=m;i++){
		Select(HT,i-1,s1,s2);
		printf("\n%d\t%d\n",s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[i].lchild=s1;
		HT[i].rchild=s2; 
		printf("\n%d,%d,%d,%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
	
	for(i=1;i<=m;i++){

		printf("\n%d,%d,%d,%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
	
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
	cd = (char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++){
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(c==HT[f].lchild){
				cd[--start]='0';
			}else{
				cd[--start]='1';
			}
			
			
		}
		
		HC[i]=(char *)malloc((n-start)*sizeof(char));
			strcpy(HC[i],&cd[start]);
			for(j=start;j<n;j++)
				printf("%c",cd[j]);
				
			putchar('\n');
	
	}
	
	free(cd);
	
}

int main(){
	int *w;
	int n;
	int i;
	HuffmanTree ht;
	HuffmanCode hc;
	
	printf("you will input how many num:");
	scanf("%d",&n);
	w=(int *)malloc(n*sizeof(int));
	printf("please input :\n");
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		printf("%d\t",w[i]);
		
	}
		
	HuffmanCoding(ht,hc,w,n);
	
	
	return 0;
}
