#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *llink,*rlink;
};

struct node *newnode(int item)
{
 struct node *temp = (struct node *)malloc(sizeof(struct node *));
 temp-> data = item;
 temp->llink = temp->rlink = NULL;
 return temp;
}
	
struct node *insert(struct node * node, int item)
{
 if(node == NULL)
  {
   return newnode(item);
  }
 if(item < node -> data)
  {
   node->llink = insert(node->llink,item);
  }
 else if(item > node->data)
  {
   node->rlink = insert(node->rlink,item);
  }
 return node;
}

void preorder(struct node *root)
{
 if(root != NULL)
  { 
   printf("%d\n",root->data);
   preorder(root->llink);
   preorder(root->rlink);
  }
}

void inorder(struct node *root)
{
 if(root != NULL)
  {
   inorder(root->llink);
   printf("%d\n",root->data);
   inorder(root->rlink);
  }
}

void postorder(struct node *root)
{
 if(root != NULL)
  {
   postorder(root->llink);
   postorder(root->rlink);
   printf("%d\n",root->data);
  }
}

void main()
{
 int a[10],total;
 struct node *root = NULL,*temp;
 printf("Enter the total no. of elements you want to enter : \n");
 scanf("%d",&total);
 printf("Enter the elements : \n");
 for(int i = 0;i<total;i++)
  {
   scanf("%d",&a[i]);
   root = insert(root,a[i]);
  }
 printf("In-Order Traversal \n");
 inorder(root);
 printf("Pre-Order Traversal \n");
 preorder(root);
 printf("Post-Order Traversal \n");
 postorder(root);
}
