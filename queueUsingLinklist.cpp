#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *link;
};

struct queue{
	struct node *front, *rear;
};
struct queue *createqueue(){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->front=q->rear=NULL;
	return q;
}
void enqueue(struct queue *q, int num){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data= num;
	temp->link= NULL;
    if(q->rear==NULL){
	    q->front=q->rear=temp;
		return; 
	}
	q->rear->link=temp;
	q->rear=temp;
}
void dequeue(struct queue *q){
	int num;
	struct node *temp;
	if(q->front==NULL)
	   {
	   	printf("queue is empty");
		return;
	   }
	   num=q->front->data;
	   temp=q->front;
	   q->front=q->front->link;
	   free(temp);
//	   return num;
}
int main(){
	struct queue *Q=createqueue();
	enqueue(Q,10);
	enqueue(Q,4);
	enqueue(Q,33);
	enqueue(Q,16);
	dequeue(Q);
	enqueue(Q,22);
	dequeue(Q);
	printf("%d\t %d",Q->front->data,Q->rear->data);
	return 0;

}




