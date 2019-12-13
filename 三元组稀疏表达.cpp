#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 12500

typedef int ElemType;
typedef struct{
	int i,j;
	ElemType e;
}Triple;

typedef struct{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

void TransposeSMatrix(TSMatrix M,TSMatrix &T){
	//矩阵转置 
	int *num,*cpot;
	int col,p,q;
	num=(int *)malloc((M.nu+1)*sizeof(int));
	cpot=(int *)malloc((M.nu+1)*sizeof(int));
	
	T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
	
	for(col=1;col<=M.nu;col++){
		num[col]=0;
	}
	for(p=1;p<=M.tu;p++){
		num[M.data[p].j]++;
	}
	cpot[1]=1;
	for(col=2;col<=M.nu;col++){
		cpot[col]=cpot[col-1]+num[col-1];
	}
	for(p=1;p<=M.tu;p++){
		col=M.data[p].j;
		q=cpot[col];
		T.data[q].i=M.data[p].j;
		T.data[q].j=M.data[p].i;
		T.data[q].e=M.data[p].e;
		cpot[col]++;
	}
}

void InitMatrix(TSMatrix &M){
	//矩阵初始化 
	int mu,nu,tu;
	int i;
	printf("you will input how many elem , row , col:");
	scanf("%d%d%d",&tu,&mu,&nu);
	M.tu=tu;
	M.mu=mu;
	M.nu=nu;
	printf("\n please input as the fram 3 6 8: \n");
	for(i=1;i<=tu;i++){
		scanf("%d%d%d",&M.data[i].i,&M.data[i].j,&M.data[i].e);
	}	
}

void display(TSMatrix M){
	//展示矩阵 
	int i,j,k,q;
	for(i=1;i<=M.mu;i++){
		for(j=1;j<=M.nu;j++){
			q=0;
			for(k=1;k<=M.tu;k++){
				if(i==M.data[k].i && j==M.data[k].j){
					printf("%d  ",M.data[k].e);
					q=1;
					break;
				}
			}
			if(!q)
				printf("0  ");
		}
		printf("\n");
	}
}

void add(TSMatrix M,TSMatrix T,TSMatrix &S){
	//矩阵求和
	int i1,i2,j,k=1;
	int flag=0;
	S.mu=M.mu;
	S.nu=M.nu;
	j= M.tu<T.tu? M.tu:T.tu;
	i1=i2=1;
	
	

	for(i1=1;i1<=M.tu;i1++){
		flag=0;
		for(i2=1;i2<T.tu;i2++){
			if(M.data[i1].i==T.data[i2].i && M.data[i1].j==T.data[i2].j){
				S.data[k].i=M.data[i1].i;
				S.data[k].j=M.data[i1].j;
				S.data[k].e=T.data[i2].e+M.data[i1].e;
				T.data[i2].e=0;
				k++;
				flag=1;
				break;
			}
		}
		if(!flag){
			S.data[k].i=M.data[i1].i;
			S.data[k].j=M.data[i1].j;
			S.data[k].e=M.data[i1].e;
			k++;
		}
		
		
	}
	
	for(i1=1;i1<=T.tu;i1++){
		if(T.data[i1].e==0)
			continue;
		S.data[k].i=T.data[i1].i;
		S.data[k].j=T.data[i1].j;
		S.data[k].e=T.data[i1].e;
		k++;	
	}
	
	S.tu=k-1;
	
		
}

int main(){
	TSMatrix M,T;
	InitMatrix(M);
	TransposeSMatrix(M,T);
	display(M);
	putchar('\n');
	display(T);
	
}
