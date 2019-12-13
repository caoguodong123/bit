#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
	int id;
	int score;
	int ranking;
	char name[MAX];
}Student;

void InputStudent(){
	int i;
	int num;
	FILE *fp;
	Student s;
	
	if((fp=fopen("G:\\a.txt","w"))==NULL){
		printf("InError");
		exit(0);
	}
	printf("please input you will input how many student:");
	scanf("%d",&num);
	
	
	
	for(i=0;i<num;i++){
		printf("please input the id:");
		scanf("%d",&s.id);
		printf("please input the name:");
		scanf("%s",s.name);
		printf("please input the score:");
		scanf("%d",&s.score);
		fprintf(fp,"%s %d %d",s.name,s.id,s.score);
		
	}
	
	fclose(fp);
	
}

void OutputStudent(){
	FILE *fp;
	Student s;
	
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d",s.name,&s.id,&s.score)!=EOF)){
		printf("%s %d %d\n",s.name,s.id,s.score);
	}
	
	fclose(fp);
}

void InsertSort(){
//直接插入排序 
	int i,j;
	int k=1;
	FILE *fp;
	int flag;
	Student s[MAX];
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d",s[k].name,&s[k].id,&s[k].score)!=EOF)){
		k++;
	}
	
	k--;
		
	for(i=2;i<=k;i++){
		if(s[i].score<s[i-1].score){
			s[0]=s[i];
			s[i]=s[i-1];
			
			for(j=i-2;s[0].score<s[j].score;j--){
				s[j+1]=s[j];
			}
			s[j+1]=s[0];
		}
	}
	s[0].score=10000;
	for(i=k;i>=1;i--){
		flag=0;
		if(s[i].score==s[i+1].score)
		{
			s[i].ranking=s[i+1].ranking;
			flag=1;
		}
		if(!flag)
			s[i].ranking=k-i+1;
		printf("%s %3d %3d %3d\n",s[i].name,s[i].id,s[i].score,s[i].ranking);	
	}
	
	fclose(fp);
}

void BubbleSort(){
	int i,j,k=1;
	FILE *fp;
	Student s[MAX];
	int flag;
	Student temp;
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d",s[k].name,&s[k].id,&s[k].score)!=EOF)){
		k++;
	}
	
	k--;
	
	for(i=1;i<=k;i++){
		for(j=i+1;j<=k;j++){
			if(s[j].score<s[i].score){
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
	s[0].score=10000;
	for(i=k;i>=1;i--){
		flag=0;
		if(s[i].score==s[i+1].score)
		{
			s[i].ranking=s[i+1].ranking;
			flag=1;
		}
		if(!flag)
			s[i].ranking=k-i+1;
		printf("%s %3d%3d%3d\n",s[i].name,s[i].id,s[i].score,s[i].ranking);	
	}
	
	fclose(fp);
	
}

void SelectionSort(){
	int i,j,k=1;
	int l;
	FILE *fp;
	Student s[MAX];
	Student temp;
	int flag;
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d %d",s[k].name,&s[k].id,&s[k].score)!=EOF)){
		k++;
	}
	
	k--;
	
	for(i=1;i<=k;i++){
		l=i;
		for(j=i+1;j<=k;j++){
			if(s[l].score>s[j].score){
				l=j;
			}
		}
		
		if(l!=i){
			s[0]=s[i];
			s[i]=s[l];
			s[l]=s[0];
		}
		
	}
	
	s[0].score=10000;
	for(i=k;i>=1;i--){
		flag=0;
		if(s[i].score==s[i+1].score)
		{
			s[i].ranking=s[i+1].ranking;
			flag=1;
		}
		if(!flag)
			s[i].ranking=k-i+1;
		printf("%s %3d%3d%3d\n",s[i].name,s[i].id,s[i].score,s[i].ranking);	
	}
	
	fclose(fp);
}

void HeapAdjust(Student *x,int s,int m){
	int j;
	x[0]=x[s];
	
	for(j=2*s;j<=m;j*=2){
		if(j<m&&x[j].score<x[j+1].score){
			j++;
		}
		if(x[0].score>x[j].score){
			break;
		}else{
			x[s]=x[j];
			s=j;
		}

	}
	x[s]=x[0];
}

void HeapSort(){
	int i,j,k=1;
	FILE *fp;
	Student s[MAX];
	Student temp;
	int flag;
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d",s[k].name,&s[k].id,&s[k].score)!=EOF)){
		k++;
	}
	
	k--;
	
	for(i=k/2;i>0;i--){
		//初始堆
		HeapAdjust(s,i,k); 
	}
	
	for(i=k;i>1;i--){
		s[0]=s[1];
		s[1]=s[i];
		s[i]=s[0];
		HeapAdjust(s,1,i-1);
	}
	
	s[0].score=10000;
	for(i=k;i>=1;i--){
		flag=0;
		if(s[i].score==s[i+1].score)
		{
			s[i].ranking=s[i+1].ranking;
			flag=1;
		}
		if(!flag)
			s[i].ranking=k-i+1;
		printf("%s %3d%3d%3d\n",s[i].name,s[i].id,s[i].score,s[i].ranking);	
	}
	
	fclose(fp);
}

int  Partition(Student s[], int low, int high)
{ 	
	int pivotkey;
    s[0] = s[low];  
    pivotkey = s[low].score;
    while(low<high){
         while(low<high && s[high].score>=pivotkey) --high;
         if(low<high)
             s[low++] = s[high];    
         while(low<high && s[low].score<=pivotkey) ++low;
         if(low<high)
             s[high--] = s[low];     
    }
    s[low] = s[0];
    return low;
}
void  Qsort(Student s[], int low, int high)
{
	int pivotloc;
    if(low<high){
        pivotloc = Partition(s, low, high);
        Qsort(s, low, pivotloc-1);
        Qsort(s, pivotloc+1, high);
   }
} 


void QuickSort()
{
	FILE *fp;
	Student s[MAX];
	int i,flag,k=0;
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d",s[k].name,&s[k].id,&s[k].score)!=EOF)){
		k++;
	}
	
	k--;
	
    Qsort(s,1,k);
    
    s[0].score=10000;
	for(i=k;i>=1;i--){
		flag=0;
		if(s[i].score==s[i+1].score)
		{
			s[i].ranking=s[i+1].ranking;
			flag=1;
		}
		if(!flag)
			s[i].ranking=k-i+1;
		printf("%s %3d%3d%3d\n",s[i].name,s[i].id,s[i].score,s[i].ranking);	
	}
	
	fclose(fp);
}

void Merge( Student SR[], Student TR[], int i, int m, int n )
{//将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
	int j,k;
   j = m+1;  k = i;
   while( i <= m && j <= n )
      if( SR[i].score <= SR[j].score )   TR[k++] = SR[i++];
      else  TR[k++] = SR[j++];
   while( i <= m)    TR[ k++] = SR[i++];
   while( j <= n)     TR[ k++] = SR[j++];
}//Merge 

void MSort( Student SR[],Student TR1[], int s, int t)
{//将SR[s..t]归并排序为TR1[s..t]。
	int m;
	Student TR2[20];
    if( s == t )   TR1[s] = SR[s];
    else 
    {    m = ( s+t )/2;         //将SR[s..t]平分为SR[s..m]和SR[m+1..t]
          MSort( SR, TR2, s, m ); //将SR[s..m]归并为有序的TR2[s..m] 
          MSort( SR, TR2, m+1, t); //将SR[m+1..t]归并为有序的TR2[m+1..t] 
          Merge( TR2, TR1, s, m, t ); //将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] 
    }
}//MSort  

void MergeSort()
{//对顺序表L作归并排序
	FILE *fp;
	Student s[MAX];
	int i,flag,k=0;
	if((fp=fopen("G:\\a.txt","r"))==NULL){
		printf("Error");
		exit(0);
	}
	
	while((fscanf(fp,"%s %d %d",s[k].name,&s[k].id,&s[k].score)!=EOF)){
		k++;
	}
	
	k--;
		
    MSort( s, s, 1, k );
    
    s[0].score=10000;
	for(i=k;i>=1;i--){
		flag=0;
		if(s[i].score==s[i+1].score)
		{
			s[i].ranking=s[i+1].ranking;
			flag=1;
		}
		if(!flag)
			s[i].ranking=k-i+1;
		printf("%s %3d%3d%3d\n",s[i].name,s[i].id,s[i].score,s[i].ranking);	
	}
	
	fclose(fp);
}//MergeSort


int main(){
	Student *s;
	int num;
	
	while(1){
		printf("please input the num to choice you will to do:\n");
		printf("1. input the student infomation\n");
		printf("2. 直接插入排序\n");
		printf("3. 冒泡排序\n");
		printf("4. 快速排序\n");
		printf("5. 简单选择排序\n");
		printf("6. 堆排序\n");
		printf("7. 2-路归并排序\n");
		printf("8. 输出学生信息\n");
		printf("0. exit\n");
		scanf("%d",&num);
		
		switch(num){
			case 1:InputStudent();break;
			case 2:InsertSort();break;
			case 3:BubbleSort();break;
			case 4:QuickSort();break;
			case 5:SelectionSort();break;
			case 6:HeapSort();break;
			case 7:MergeSort();break;
			case 8:OutputStudent();break;
			case 0:return 0;
			default :break;
		} 
	}
	
	
	return 0;
}
