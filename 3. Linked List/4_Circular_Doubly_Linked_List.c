#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* previous;
    int data;
    struct node* next;
};

struct node* createnode();
struct node* createCircularDoublyLinkedList(struct node**);
void displayLinkedList(struct node*);
void insertAtFirst(struct node**);
void insertAtLast(struct node**);
void deleteAtFirst(struct node**);
void deleteAtLast(struct node**);

void main()
{
    int choice,n,i;
    struct node* lastnode=NULL;
    printf("******************** Circular Doubly Linked List **************************\n");
    do
    {
        printf("1. Create Circular Doubly Linked List.\n");
        printf("2. Display Circular Doubly Linked List.\n");
        printf("3. Insert at First in Circular Doubly Linked List.\n");
        printf("4. Insert at Last in Circular Doubly Linked List.\n");
        printf("5. Delete at First in Circular Doubly Linked List.\n");
        printf("6. Delete at Last in Circular Doubly Linked List.\n");
        printf("0. Exit.\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: printf("How many nodes you want to insert : ");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++)
                        createCircularDoublyLinkedList(&lastnode);
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

struct node* createCircularDoublyLinkedList(struct node** tail)
{
    struct node* tempnode = NULL;
    tempnode = createnode();
    if(*tail == NULL)
    {
        *tail = tempnode;
        (*tail)->next = tempnode;
        (*tail)->previous = tempnode;
    }
    else
    {
        tempnode->next = (*tail)->next;
        tempnode->previous = *tail;
        tempnode->next->previous = tempnode;
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
        newnode->previous = NULL;
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
        printf("\n");

        printf("Linked List : ");
        do
        {
            printf("%d    ",travnode->data);
            travnode = travnode->previous;
        }while(travnode != tail);
        printf("\n");
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
        (*tail)->previous = *tail;
    }
    else
    {
        tempnode->next = (*tail)->next;
        tempnode->previous = *tail;
        tempnode->next->previous = tempnode;
        (*tail)->next = tempnode;
    }
    displayLinkedList(*tail);
}

void insertAtLast(struct node** tail)
{
    createCircularDoublyLinkedList(tail);
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
        {
            (*tail)->next = tempnode->next;
            tempnode->next->previous = *tail;
        }
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
            *tail = (*tail)->previous; 
            (*tail)->next = tempnode->next;
            tempnode->next->previous = *tail;
        }
        free (tempnode);
    }
    displayLinkedList(*tail);
}