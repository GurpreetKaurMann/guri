#include<stdio.h>
#include<conio.h>
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int A[],int n,int i){
	int lar=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && A[lar]<A[l])
	   lar=l;
	   
	if(r<n && A[lar]<A[r])
	   lar=r;
	if(lar!=i){
		swap(&A[lar],&A[i]);
		heapify(A,n,lar);
	}
}
void heapsort(int A[],int n)
{
	
	for(int i=n/2 -1;i>=0;i--)
	    heapify(A,n,i);
	for(int i=n-1;i>=0;i--){
		swap(&A[i],&A[0]);
		heapify(A,i,0);
	}
}
void display(int A[],int n){
	printf("\n");
	for(int i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
}
int main(){
	int i,n,num,A[10];
	printf("enter no of elements");
	scanf("%d",&n);
	printf("\nenter elements");
	for(i=0;i<n;i++)
	     scanf("%d",&A[i]);
	heapsort(A,n);
	printf("sorted list is:\n");
	display(A,n);
	return 0;
}
