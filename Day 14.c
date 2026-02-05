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

//Leaf node count
#include <stdio.h>
#include <stdlib.h>
int count=0;
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

void postorder(struct node* root)
{
    if(root==NULL) return;
    if(root->left==NULL&&root->right==NULL)count++;
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
    
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\nTotal No. of Leaves: %d",count);
    return 0;
}

//2 cities
#include <stdio.h>
int main() 
{
    int n;
    printf("Enter number of cities:\n");
    scanf("%d",&n);
    int mat[n][n];
    printf("Adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\nEnter 2 cities A and B:\n");
     int a,b;
    scanf("%d %d",&a,&b);
    if(mat[a-1][b-1]==1)printf("Connected");
    else printf("Not Connected");
    return 0;
}
