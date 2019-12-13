#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
	int *base;
	int front;
	int rear;
}Queue;


int main(){
	Queue QM,QF;
	int num,i,j,k,xM,xF;
	
	printf("please input you want to star times:");
	scanf("%d",&num);
	
	
	if(QM.front<QM.rear)
		xM=QM.rear-QM.front;
	else{
		xM=QM.rear+MAX-QM.front;
	}
	if(QF.front<QF.rear)
		xF=QF.rear-QF.front;
	else{
		xF=QF.rear+MAX-QF.front;
	}
	
	
	i=0;
	while(i<num){
		
		if(xM<xF){
			j=0;
			while(j<xM){
				
				
			}
		}
			
		
		i++;
	}
	
	return 0;
}
