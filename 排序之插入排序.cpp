#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

typedef int InfoType;
typedef struct{
	int key;
	InfoType otherInfo;
}RedType;
typedef struct{
	RedType r[MAX+1];
	int length;
}SqList;

void InitSqList(SqList &L){
	int i,j;
	int flag;
	printf("please input the num:");
	scanf("%d",&L.length);
	srand(time(0));
	for(i=1;i<=L.length;i++){
		L.r[i].key=rand()%90+10;
		flag=1;
		while(flag){
			for(j=1;j<i;j++){
				if(L.r[j].key==L.r[i].key){
					L.r[i].key=rand()%90+10;
					break;
				}
			}
			if(j==i){
				flag=0;
			}
		}
	}
}
void display(SqList L){
	int i;
	
	for(i=1;i<=L.length;i++){
		printf("%d  ",L.r[i].key);
		
	}
	putchar('\n');
}

void InsertSort(SqList &L){
//Ö±½Ó²åÈëÅÅÐò 
	int i,j;
	
	for(i=2;i<=L.length;i++){
		if(L.r[i].key<L.r[i-1].key){
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(j=i-2;L.r[0].key<L.r[j].key;j--){
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
}

void Bin_InsertSort(SqList &L){
//ÕÛ°ë²åÈëÅÅÐò 
	int i,j;
	int low,high,mid;
	
	for(i=2;i<=L.length;i++){
		low=1;high=i-1;
		L.r[0]=L.r[i];
		while(low<=high){
			mid=(low+high)/2;
			if(L.r[mid].key>=L.r[0].key){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}
		
		for(j=i-1;j>high;j--){
			L.r[j+1]=L.r[j];
		}
		L.r[high+1]=L.r[0];
	}
	
}

void Two_InsertSort(SqList &L){
	SqList D;
	int x,low,high,mid;
	int i,j,first,final;
	
	first=final=1;
	D.r[1]=L.r[1];D.length=L.length;
	for(i=2;i<=L.length;i++){
		x=L.r[i].key;
		if(x<D.r[1].key){
			if(first==1){
				D.r[D.length].key=x;
				first=D.length;
			}else{
				low=first;high=D.length;
				while(low<=high){
					mid=(low+high)/2;
					if(x<D.r[mid].key){
						high=mid-1;
					}else{
						low=mid+1;
					}
				}
				
				for(j=first;j<=high;j++){
					D.r[j-1]=D.r[j];
				}
				D.r[high].key=x;
				first--;
			}
		}else{
			if(final==1){
				D.r[final+1].key=x;
				final++;
			}else{
				low=2;high=final;
				while(low<=high){
					mid=(low+high)/2;
					if(x<D.r[mid].key){
						high=mid-1;
					}else{
						low=mid+1;
					}
				}
				
				for(j=final;j>=high+1;j--){
					D.r[j+1]=D.r[j];
				}
				D.r[high+1].key=x;
				final++;
			}
		}
	}
	//display(D);
	for(i=1;i<=L.length;i++){
		L.r[i]=D.r[first++];
		first %= L.length;
		if(first==0){
			first=L.length;
		}
	}
		
}

void ShellInsert(SqList &L,int dk){
	//¶ÔË³Ðò±í×÷Ò»ÌËÏ£¶û²åÈëÅÅÐò
     int i,j;
	 for( i=dk+1; i<=L.length; i++ )
          if( L.r[i].key <= L.r[i-dk].key )
          {     L.r[0]=L.r[i];
                for( j=i-dk;j>0 && L.r[0].key<=L.r[j].key; j-=dk )
                     L.r[j+dk]=L.r[j];
                L.r[j+dk]=L.r[0];

          }

}
void ShellSort(SqList &L, int delta[], int n ){
	//¶ÔË³Ðò±íL×÷Ï£¶ûÅÅÐò
	int i;
     for( i=0; i<n; i++ ){
     	ShellInsert( L, delta[i] );
     	display(L);
	 }
        
    
}   
	


int main(){
	SqList L;
	int n,i;
	int a[MAX];
	
	InitSqList(L);
	display(L);
	//InsertSort(L);
	//display(L);
	//Bin_InsertSort(L);
	//display(L);
	//Two_InsertSort(L);
	//display(L);
	
	printf("please input the slipt num:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ShellSort(L,a,n);

	
	return 0;
}

