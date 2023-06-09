#include<stdio.h>
#include<stdlib.h>

// int count(struct node* head); 

struct node
{
    int data;
    struct node* next;
};

int count(struct node* head); 

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

// struct node* createLinkedList()
// void createLinkedList(struct node* head)
struct node* createLinkedList(struct node** head)
{
    struct node* tempnode = NULL;
    struct node* travnode = *head;
    tempnode = createnode();
    // return tempnode;
    // head = tempnode;
    if(*head == NULL)
        *head = tempnode;
    else
    {
        while(travnode->next != NULL)
            travnode = travnode->next;
        
        travnode->next = tempnode;
    }
}

void displayLinkedList(struct node* temp)
{
    if(temp == NULL)
        printf("Linked List is Empty.");
    else
    {
        printf("Linked List : ");
        while(temp != NULL)     // Or use do while loop
        {
            int data = temp->data;
            printf("%d    ",data);
            temp = temp->next;
        }
    }
    printf("\n");
}

// void insertAtFirst(struct node* head)
void insertAtFirst(struct node** head)
{
    struct node* tempnode = NULL;
    tempnode = createnode();
    tempnode->next = *head;
    *head = tempnode;
    displayLinkedList(*head);
}

void insertAtLast(struct node** head)
{
    createLinkedList(head);
    displayLinkedList(*head);
}

void insertAtPosition(struct node** head)
{
    int n,pos,i;
    struct node* tempnode = NULL;
    struct node* travnode = *head;
    printf("Enter Position to add new node : ");
    scanf("%d",&pos);
    n = count(*head);

    if(pos<1 || pos>n+1)
    {
        printf("Invalid Position.\n");
        insertAtPosition(head);
    }
    else if(pos == 1)
        insertAtFirst(head);
    else if(pos == n+1)
        insertAtLast(head);
    else
    {
        tempnode = createnode();
    
        for(i=1; i < pos-1 ;i++)
            travnode = travnode->next;
        
        tempnode->next = travnode->next;
        travnode->next = tempnode;
        displayLinkedList(*head);
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

void deleteAtFirst(struct node** head)
{
    if(*head == NULL)
        printf("Linked List is Empty.\n");
    else
    {
        struct node* tempnode = NULL;
        tempnode = (*head)->next;
        free (*head);
        *head = tempnode;
        displayLinkedList(*head);
    }
}

void deleteAtLast(struct node** head)
{
    if(*head == NULL)
        printf("Linked List is Empty.\n");
    else if((*head)->next == NULL)
    {
        free (*head);
        displayLinkedList(*head);
    }
    else
    {
        struct node* travnode = NULL;
        travnode = *head;
        while(travnode->next->next != NULL)
            travnode = travnode->next;
        
        free (travnode->next);
        travnode->next = NULL;
        displayLinkedList(*head);
    }
}

void deleteAtPosition(struct node** head)
{
    int n,pos,i;
    if(*head == NULL)
        printf("Linked List is Empty.\n");
    else
    {
        printf("Enter Position to delete node : ");
        scanf("%d",&pos);
        n = count(*head);

        if(pos<1 || pos>n)
        {
            printf("Invalid Position.\n");
            deleteAtPosition(head);
        }
        else if(pos == 1)
            deleteAtFirst(head);
        else if(pos == n)
            deleteAtLast(head);
        else
        {
            struct node* tempnode = NULL;
            struct node* travnode = NULL;
            travnode = *head;
            for(i=1; i < pos-1 ;i++)
                travnode = travnode->next;
        
            tempnode = travnode->next->next;
            free (travnode->next);
            travnode->next = tempnode;
            displayLinkedList(*head);
        }
    }
}

void searchElement(struct node* head)
{
    int search,flag,i;
    printf("Enter Element to Search : ");
    scanf("%d",&search);
    i=0;
    flag=0;
    while(head != NULL)
    {
        i++;
        if(head->data == search)
        {
            printf("Element is found at node %d.\n",i);
            flag=1;
            break;
        }
        head = head->next;
    }
    if(flag == 0)
        printf("Element is NOT found.\n");
}

void sortLinkedList(struct node** head)
{
    struct node* travnode1 = NULL;
    struct node* travnode2 = NULL;
    int temp;
    for(travnode1=*head; travnode1->next != NULL;travnode1=travnode1->next)
    {
        for(travnode2=travnode1->next;travnode2 != NULL;travnode2=travnode2->next)
        {
            if((travnode1->data) > (travnode2->data))
            {
                temp = travnode1->data;
                travnode1->data = travnode2->data;
                travnode2->data = temp;
            }
        }
    }
    displayLinkedList(*head);
}

struct node* displayReverse(struct node* head)
{
    if(head != NULL)
    {    
        displayReverse(head->next);
        printf("%d   ",head->data);
    }
}

void deleteList(struct node** head)
{
    if(*head == NULL)
        printf("Linked List is Empty.\n");
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
    }
}

void main()
{
    int choice,n,i;
    struct node* firstnode=NULL;
    printf("******************** Linked List **************************\n");
    do
    {
        printf("1. Create Linked List.\n");
        printf("2. Display Linked List.\n");
        printf("3. Insert at First in Linked List.\n");
        printf("4. Insert at Last in Linked List.\n");
        printf("5. Insert at Position in Linked List.\n");
        printf("6. Delete at First in Linked List.\n");
        printf("7. Delete at Last in Linked List.\n");
        printf("8. Delete at Position in Linked List.\n");
        printf("9. Search Element.\n");
        printf("10.Sort Linked List.\n");
        printf("11.Display Reverse Linked List.\n");
        printf("12.Delete Whole Linked List.\n");
        printf("0. Exit.\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: // firstnode = createLinkedList();
                    // createLinkedList(firstnode);
                    printf("How many nodes you want to insert : ");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++)
                        createLinkedList(&firstnode);
                    displayLinkedList(firstnode);
                    break;

            case 2: displayLinkedList(firstnode);
                    break;

            case 3: // insertAtFirst(firstnode);
                    insertAtFirst(&firstnode);
                    break;

            case 4: // insertAtLast(firstnode);
                    insertAtLast(&firstnode);
                    break;

            case 5: insertAtPosition(&firstnode);
                    break;

            case 6: deleteAtFirst(&firstnode);
                    break;
            
            case 7: deleteAtLast(&firstnode);
                    break;

            case 8: deleteAtPosition(&firstnode);
                    break;

            case 9: searchElement(firstnode);
                    break;

            case 10:sortLinkedList(&firstnode);
                    break;

            case 11:printf("Reverse Linked List : ");
                    displayReverse(firstnode);
                    printf("\n");
                    break;    

            case 12:deleteList(&firstnode);
                    break;          
            default:if(choice != 0)
                        printf("Please Enter correct choice.\n");
                    break;
        }
        printf("\n");
    }while(choice != 0);
}