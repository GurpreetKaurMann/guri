#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *link;
}*stack=NULL;
void push(struct node *top,int num){
	struct  node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	if(top==NULL)
	{
		temp->link=NULL;
		top=temp;
		//return;
	}
	else
	{
		temp->link=top;
		top=temp;
	}
	stack=top;
}
int pop(struct node *top){
	int num;
	struct node *temp;
	if(top==NULL)
	{
		printf("stack is empty");
		//break;
		//return 0;
		
	}
	else
	{
		/*temp=top;
		top=top->link;
		return temp->data;
		free(temp);*/
		
		temp=top;
		top=top->link;
		temp->link=NULL;
		stack=top;
		printf("\npopped element is %d",temp->data);
	}
}
void display(struct node *top){
	if(top==NULL)
	    printf("\nstack is empty!");
	else {
		printf("\nstack is : \n");
		while(top!=NULL){
			printf("%d\t",top->data);
			top=top->link;
		}
	}
}
int main(){
//	struct node *stack=NULL;
	int y;
	display(stack);
	push(stack,10);
	push(stack,20);
	push(stack,22);
	push(stack,12);
	push(stack,15);
	push(stack,14);
	push(stack,2);
	push(stack,9);
	push(stack,18);
	push(stack,26);
	display(stack);
	pop(stack);
	display(stack);
	return 0;
}

