#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *left; 
	struct node *right;
};
typedef struct node tree;

tree *createnode(int num){
	tree *temp=(tree*)malloc(sizeof(tree));
	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;
}
tree *insertBST(tree *root, int num){
	if(root==NULL)
	    root= createnode(num); 
		  	else{
		if(num<(root->data))
		 root->left =  insertBST(root->left,num);
		if(num>(root->data))
		   root->right=insertBST(root->right,num);
	}
	return root;
}
void inorder(tree *root){
	
	if(root!=NULL)
	{
	    inorder(root->left);
	    printf("%d\n",root->data);
	    inorder(root->right);	
	}
}
int main()
{
	tree *rooot=NULL;
	
	rooot = insertBST(rooot,30);
	insertBST(rooot,40);
	insertBST(rooot,10);
    insertBST(rooot,15);
	inorder(rooot);
}
