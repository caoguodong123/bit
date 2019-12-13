#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
	ElemType *data;
	int length;
}SSTable;

typedef struct{
	ElemType data;
	int weizhi;
}Block;

void InitSSTable(SSTable &sst){
	int i,j;
	int flag;
	
	printf("please input you need how many num:");
	scanf("%d",&sst.length);
	sst.data=(ElemType *)malloc((sst.length+1)*sizeof(ElemType));
	
	srand(time(0));
	for(i=1;i<=sst.length;i++){
		sst.data[i]=rand()%90+10;
		flag=1;
		while(flag){
			for(j=1;j<i;j++){
				if(sst.data[j]==sst.data[i]){
					sst.data[i]=rand()%90+10;
					break;
				}
			}
			if(j==i){
				flag=0;
			}
		}
	}
	

	
}

void sort(SSTable &sst){
	int i,j;
	ElemType k;
	
	for(i=1;i<=sst.length;i++){
		for(j=i+1;j<=sst.length;j++){
			if(sst.data[i]>sst.data[j]){
				k=sst.data[i];
				sst.data[i]=sst.data[j];
				sst.data[j]=k;
				
			}
		}
	}
	
}

void display(SSTable sst){
	int i;
	
	for(i=1;i<=sst.length;i++){
		printf("%5d",sst.data[i]);
	}
	putchar('\n');
	
}

void Search_Bin(SSTable sst,ElemType  key){
	int low,high;
	int mid;
	int flag=0;
	low=1;high=sst.length;
	
	while(low<=high){
		mid=(low+high)/2;
		if(sst.data[mid]<key){
			low=mid+1;
		}else if(sst.data[mid]>key){
			high=mid-1;
		}else if(sst.data[mid]==key){
			printf("Find it!!\n");
			flag=1;
			break;
		}
	}
	if(!flag)
		printf("NO Find!\n");
}

void Search_Bin1(SSTable sst,ElemType  key,int low,int high){
	int mid;
	
	if(low<=high){
		mid = (low+high)/2;
		if(sst.data[mid]<key){
			Search_Bin1(sst,key,mid+1,high);
			return;
		}else if(sst.data[mid]>key){
			Search_Bin1(sst,key,low,mid-1);
			return;
		}else if(sst.data[mid]==key){
			printf("Find it!!\n");
			return;
		}
				
	}
	printf("NO Find!\n");
	
}

void BlockSearch(SSTable sst,Block *a,int n,int key){
	int i,j;
	
	for(i=1;i<=n;i++){
		if(key<=a[i].data){
			break;
		}
	}
	
	for(j=a[i].weizhi;j<=a[i+1].weizhi;j++){
		if(sst.data[j]==key){
			printf("find it\n");
			return;
			//return j;
		}
	}
	
	printf("No find\n");
	//return -1;
	return;

}


int main(){
	SSTable sst;
	ElemType key;
	int n,i;
	Block *b;
	
	InitSSTable(sst);
	display(sst);
	sort(sst);
	display(sst);
	printf("please input you will find the num:");
	scanf("%d",&key);
	Search_Bin(sst,key);
	
	/*
	Search_Bin1(sst,key,1,sst.length);
	
	printf("please input the you will split block num:");
	scanf("%d",&n);
	
	b=(Block *)malloc((n+1)*sizeof(Block));
	for(i=1;i<=n;i++){
		printf("please input the block:");
		scanf("%d%d",&b[i].data,&b[i].weizhi);
	}
	printf("please input you will find the num:");
	scanf("%d",&key);
	//BlockSearch(sst,b,n,key);
	
	*/
	return 0;
	
}
