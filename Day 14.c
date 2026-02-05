//Tree traversal
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
//creating node
struct node* createnode(int value)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
}
void preorder(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main() {
    //adding data
    struct node* root=createnode(10);
    //adding child data for root
    root->left=createnode(20);
    root->right=createnode(30);
    //adding child for 1st parents
    root->left->left=createnode(40);
    root->left->right=createnode(50);
    
    root->right->left=createnode(60);
    root->right->right=createnode(70);
    
    printf("Preorder Traversal: ");
    preorder(root);
    printf("Inorder Traversal: ");
    Inorder(root);
    printf("Postorder Traversal: ");
    postorder(root);
    return 0;
}
