#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createnode();
struct node* createCircularSinglyLinkedList(struct node**);
void displayLinkedList(struct node*);
void insertAtFirst(struct node**);
void insertAtLast(struct node**);
void deleteAtFirst(struct node**);
void deleteAtLast(struct node**);

void main()
{
    int choice,n,i;
    struct node* lastnode=NULL;
    printf("******************** Circular Singly Linked List **************************\n");
    do
    {
        printf("1. Create Circular Singly Linked List.\n");
        printf("2. Display Circular Singly Linked List.\n");
        printf("3. Insert at First in Circular Singly Linked List.\n");
        printf("4. Insert at Last in Circular Singly Linked List.\n");
        printf("5. Delete at First in Circular Singly Linked List.\n");
        printf("6. Delete at Last in Circular Singly Linked List.\n");
        printf("0. Exit.\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: printf("How many nodes you want to insert : ");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++)
                        createCircularSinglyLinkedList(&lastnode);
                    displayLinkedList(lastnode);
                    break;

            case 2: displayLinkedList(lastnode);
                    break;

            case 3: insertAtFirst(&lastnode);
                    break;

            case 4: insertAtLast(&lastnode);
                    break;

            case 5: deleteAtFirst(&lastnode);
                    break;

            case 6: deleteAtLast(&lastnode);
                    break;

            default:if(choice != 0)
                        printf("Please Enter correct choice.\n");
                    break;
        }
        printf("\n");
    }while(choice != 0);
}

struct node* createCircularSinglyLinkedList(struct node** tail)
{
    struct node* tempnode = NULL;
    tempnode = createnode();
    if(*tail == NULL)
    {
        *tail = tempnode;
        (*tail)->next = tempnode;
    }
    else
    {
        tempnode->next = (*tail)->next;
        (*tail)->next = tempnode;
        *tail = tempnode;
    }
}

struct node* createnode()
{
    int data;
    struct node* newnode = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory NOT allocated. Node not created.\n");
    }
    else
    {
        printf("Enter data : ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }
}

void displayLinkedList(struct node* tail)
{
    struct node* travnode = tail;
    if(tail == NULL)
        printf("Linked List is Empty.");
    else
    {
        printf("Linked List : ");
        do
        {
            travnode = travnode->next;
            printf("%d    ",travnode->data);
            // travnode = travnode->next;
        }while(travnode != tail);
    }
    printf("\n");
}

void insertAtFirst(struct node** tail)
{
    struct node* tempnode = NULL;
    tempnode = createnode();
    if(*tail == NULL)
    {
        *tail = tempnode;
        (*tail)->next = *tail;
    }
    else
    {
        tempnode->next = (*tail)->next;
        (*tail)->next = tempnode;
    }
    displayLinkedList(*tail);
}

void insertAtLast(struct node** tail)
{
    createCircularSinglyLinkedList(tail);
    displayLinkedList(*tail);
}

void deleteAtFirst(struct node** tail)
{
    if(*tail != NULL)
    {
        struct node* tempnode = (*tail)->next;
        if((*tail)->next == *tail)
            *tail = NULL;
        else
            (*tail)->next = (*tail)->next->next;
        free (tempnode);
    }
    displayLinkedList(*tail);
}

void deleteAtLast(struct node** tail)
{
    if(*tail != NULL)
    {
        struct node* tempnode = *tail;
        
        if((*tail)->next == *tail)
            *tail = NULL;
        else
        {
            while((*tail)->next != tempnode)
                *tail = (*tail)->next;
                
            (*tail)->next = tempnode->next;
        }
        free (tempnode);
    }
    displayLinkedList(*tail);
}