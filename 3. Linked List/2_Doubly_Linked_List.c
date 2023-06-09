#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* previous;
    int data;
    struct node* next;
};

void createDoublyLinkedList(struct node**,struct node**);
struct node* createNode();
void displayDoublyLinkedList(struct node*,struct node*);
void insertAtFirst(struct node**,struct node**);
void insertAtLast(struct node**,struct node**);
void insertAtPosition(struct node**,struct node**);
int count(struct node*);
void deleteAtFirst(struct node**,struct node**);
void deleteAtLast(struct node**,struct node**);
void deleteAtPosition(struct node**,struct node**);
void deleteList(struct node**,struct node**);

void main()
{
    int choice,n,i;
    struct node* firstnode = NULL;
    struct node* lastnode = NULL;
    printf("******************** Doubly Linked List **************************\n");
    do
    {
        printf("1. Create Doubly Linked List.\n");
        printf("2. Display Doubly Linked List.\n");
        printf("3. Insert at First in Doubly Linked List.\n");
        printf("4. Insert at Last in Doubly Linked List.\n");
        printf("5. Insert at Position in Doubly Linked List.\n");
        printf("6. Delete at First in Doubly Linked List.\n");
        printf("7. Delete at Last in Doubly Linked List.\n");
        printf("8. Delete at Position in Doubly Linked List.\n");
        printf("9. Delete Doubly Linked List.\n");
        printf("0. Exit.\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: printf("How many nodes you want to insert : ");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++)
                        createDoublyLinkedList(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 2: displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 3: insertAtFirst(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 4: insertAtLast(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 5: insertAtPosition(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 6: deleteAtFirst(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;
            
            case 7: deleteAtLast(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 8: deleteAtPosition(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            case 9: deleteList(&firstnode,&lastnode);
                    displayDoublyLinkedList(firstnode,lastnode);
                    break;

            default : if(choice != 0)
                        printf("Please Enter correct choice.\n");
                      break;
        }
        printf("\n");
    }while(choice != 0);
}

void createDoublyLinkedList(struct node** head,struct node** tail)
{
    struct node* tempnode = NULL;
    tempnode = createNode();
    if(*head == NULL)
    {
        *head = tempnode;
        *tail = tempnode;
    }
    else
    {
        (*tail)->next = tempnode;
        tempnode->previous = *tail;
        *tail = tempnode;
    }
}

struct node* createNode()
{
    int data;
    struct node* newnode = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
        printf("Memory Not Allocated.\n");
    else
    {
        printf("Enter data : ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->previous = NULL;
        newnode->next = NULL;
        return newnode;
    }
}

void displayDoublyLinkedList(struct node* head,struct node* tail)
{
    if(head == NULL)
        printf("Doubly Linked List is Empty.\n");
    else
    {
        printf("Doubly Linked List : ");
        while(head != NULL)
        {
            printf("%d    ",head->data);
            head = head->next;
        }
        printf("\n");

        printf("Doubly Linked List : ");
        while(tail != NULL)
        {
            printf("%d    ",tail->data);
            tail = tail->previous;
        }
        printf("\n");
    }
}

void insertAtFirst(struct node** head,struct node** tail)
{
    struct node* tempnode = NULL;
    tempnode = createNode();
    if(*head == NULL)
    {
        *head = tempnode;
        *tail = tempnode;
    }
    else
    {
        tempnode->next = *head;
        (*head)->previous = tempnode;
        *head = tempnode;
    }
}

void insertAtLast(struct node** head,struct node** tail)
{
    createDoublyLinkedList(head,tail);
}

void insertAtPosition(struct node** head,struct node** tail)
{
    int pos,n,i;
    printf("Enter Position to Insert Node : ");
    scanf("%d",&pos);
    n = count(*head);

    if(pos<1 || pos>n+1)
    {
        printf("Invalid Position.\n");
        insertAtPosition(head,tail);
    }
    else if(pos == 1)
        insertAtFirst(head,tail);
    else if(pos == n+1)
        createDoublyLinkedList(head,tail);
    else if(pos <= n/2)
    {
        struct node* tempnode = NULL;
        tempnode = createNode();
        struct node* travnode = *head;
        for(i=1;i<pos-1;i++)
            travnode = travnode->next;
        tempnode->previous = travnode;
        tempnode->next = travnode->next;
        travnode->next->previous = tempnode;
        travnode->next = tempnode;
    }
    else
    {
        struct node* tempnode = NULL;
        tempnode = createNode();
        struct node* travnode = *tail;
        for(i=1;i <= n-pos;i++)
            travnode = travnode->previous;
        tempnode->next = travnode;
        tempnode->previous = travnode->previous;        
        travnode->previous->next = tempnode;
        travnode->previous = tempnode;
    }
}

int count(struct node* head)
{
    int count=0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void deleteAtFirst(struct node** head,struct node** tail)
{
    if(*head == NULL)
        printf("List is Empty.\n");
    else if(*head == *tail)
    {
        free (*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        free ((*head)->previous);
        (*head)->previous = NULL;
    }
}

void deleteAtLast(struct node** head,struct node** tail)
{
    if(*head == NULL)
        printf("List is Empty.\n");
    else if(*head == *tail)
    {
        free (*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = (*tail)->previous;
        free ((*tail)->next);
        (*tail)->next = NULL;
    }
}

void deleteAtPosition(struct node** head,struct node** tail)
{
    int pos,n,i;
    printf("Enter Position to Delete Node : ");
    scanf("%d",&pos);
    n = count(*head);

    if(pos<1 || pos>n+1)
    {
        printf("Invalid Position.\n");
        insertAtPosition(head,tail);
    }
    else if(pos == 1)
        deleteAtFirst(head,tail);
    else if(pos == n)
        deleteAtLast(head,tail);
    else
    {
        struct node* travnode = *head;
        for(i=1;i<pos;i++)
            travnode = travnode->next;
        
        travnode->previous->next = travnode->next;
        travnode->next->previous = travnode->previous;
        free (travnode);
    }
}

void deleteList(struct node** head,struct node** tail)
{
    if(*head == NULL)
        printf("List is Empty.\n");
    else
    {
        struct node* tempnode = NULL;
        while(*head != NULL)
        {
            tempnode = *head;
            *head = (*head)->next;
            free (tempnode);
        }
        printf("Linked List is Deleted.\n");
        *tail = NULL;
    }
}