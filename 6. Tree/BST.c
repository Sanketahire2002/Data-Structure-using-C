#include<stdio.h>
#include<stdlib.h>

struct BST
{
    struct BST* left;
    int data;
    struct BST* right;
};

struct queue
{
    struct BST** arr;
    int front,rear;
};

struct stack
{
    struct BST** arr;
    int top;   
};

struct BST* craetenode();
void createBST(struct BST**);
void preorder(struct BST*);
void inorder(struct BST*);
void postorder(struct BST*);
void levelorder(struct BST*,int);
void search(struct BST*,int);

void main()
{
    struct BST* root = NULL;
    int ch,n,i;
    char z;
    printf("***************** Binary Search Tree ****************\n");

    printf("How many nodes you want to insert : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        createBST(&root);
    if(root == NULL)
        printf("BST is Empty.\n");
    else
    {
        printf("Preorder :\t");
        preorder(root);
        printf("\n");

        printf("Inorder :\t");
        inorder(root);
        printf("\n");

        printf("Postorder :\t");
        postorder(root);
        printf("\n");

        printf("BFS/Level Order :");
        levelorder(root,n);
        printf("\n");

    }
    
    do{
        printf("1. Add element in BST.\n");
        printf("2. Display BST\n");
        printf("3. Search element in BST\n");
        printf("0. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: createBST(&root);
                    n++;
                    break;
            
            case 2: if(root == NULL)
                        printf("BST is Empty.\n");
                    else
                    {
                        printf("DFS Preorder :\t");
                        preorder(root);
                        printf("\n");

                        printf("DFS Inorder :\t");
                        inorder(root);
                        printf("\n");

                        printf("DFS Postorder :\t");
                        postorder(root);
                        printf("\n");

                        printf("BFS/Level Order :");
                        levelorder(root,n);
                        printf("\n");

                    }
                    break;
            
            case 3: if(root == NULL)
                        printf("BST is Empty.\n");
                    else
                        search(root,n);
                    break;

            case 0: exit(0);

            default:printf("Enter correct choice : ");
                    break;

        }

        printf("Do you want to continue(y or n) : ");
        scanf(" %c",&z);
    }while(z=='y' || z=='Y');
}

struct BST* craetenode()
{
    struct BST* newnode = NULL;
    newnode = (struct BST*) malloc (sizeof(struct BST));
    if(newnode == NULL)
        printf("Memory not Alloacated.\n");
    else
    {
        newnode->left = newnode->right = NULL;
        printf("Enter data : ");
        scanf("%d",&(newnode->data));
        return newnode;
    }
}

void createBST(struct BST** root)
{
    struct BST* newnode = NULL;
    struct BST* tempnode = *root;
    newnode = craetenode();

    if(*root == NULL)
        *root = newnode;
    else
    {
        while(1)
        {
            if(newnode->data < tempnode->data)
                if(tempnode->left == NULL)
                {   tempnode->left = newnode;
                    break;
                }
                else
                    tempnode = tempnode->left;
            else
                if(tempnode->right == NULL)
                {   tempnode->right = newnode;
                    break;
                }
                else
                    tempnode = tempnode->right;
        }
    }
}

void preorder(struct BST* root)
{
    if(root != NULL)
    {
        printf("  %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct BST* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
		printf("  %d",root->data);
    }
}

void inorder(struct BST* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("  %d",root->data);
        inorder(root->right);
    }
}

void levelorder(struct BST* root,int n)
{
    struct queue* que = NULL;
    struct BST* tempfront = NULL;
    que = (struct queue*) malloc(sizeof(struct queue));
    que->front = -1;
    que->arr = (struct BST**) malloc (n * sizeof(struct BST*));

    que->arr[0] = root;
    que->rear = 0;

    while(que->front != que->rear)
    {
        tempfront = que->arr[(que->front)+1];
        if(tempfront->left != NULL)
            que->arr[++(que->rear)] = tempfront->left;
        if(tempfront->right != NULL)
            que->arr[++(que->rear)] = tempfront->right;

        printf("   %d",tempfront->data);
        (que->front)++;
    }
}

void search(struct BST* root,int n)
{
    int element,flag;
    struct BST* temptop = NULL;
    printf("Which element you want to search : ");
    scanf("%d",&element);
    struct stack* stk = NULL;
    stk = (struct stack*) malloc (sizeof(struct stack));
    stk->arr = (struct BST**) malloc (n * sizeof(struct BST*));
    stk->top = 0;
    stk->arr[stk->top] = root;
    flag = 0;
    while(stk->top >= 0)
    {
        
    }
    if(flag == 0)
        printf("Element is NOT Present in BST.\n");
}
