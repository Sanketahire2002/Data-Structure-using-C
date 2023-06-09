#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack* createstack();
void displayLinkedList(struct stack*);
void push(struct stack**);
void pop(struct stack**);
void peak(struct stack*);

void main()
{
    struct stack* top = NULL;
    int ch;
    printf("****************** Stack ****************\n");
    printf("1. Push Element into Stack.\n");
    printf("2. Pop Element into Stack.\n");
    printf("3. Peak Element into Stack.\n");
    printf("4. Display Stack.\n");

    while(1)
    {   
        printf("Enter choice to Select : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(&top);
                    break;

            case 2: pop(&top);
                    break;

            case 3: peak(top);
                    break;

            case 4: displayLinkedList(top);
                    break;
        }
        if(ch<1 || ch>4)
            break;
    }
}

struct stack* createstack()
{
    int data;
    struct stack* newstack = NULL;
    newstack = (struct stack*)malloc(sizeof(struct stack));
    if(newstack == NULL)
    {
        printf("Memory NOT allocated. Stack not Full.\n");
    }
    else
    {
        printf("Enter element to insert in stack : ");
        scanf("%d",&data);
        newstack->data = data;
        newstack->next = NULL;
        return newstack;
    }
}

void displayLinkedList(struct stack* temp)
{
    if(temp == NULL)
        printf("Stack is Empty.");
    else
    {
        printf("Stack : ");
        while(temp != NULL)     // Or use do while loop
        {
            int data = temp->data;
            printf("%d    ",data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void push(struct stack** top)
{
    struct stack* tempstack = NULL;
    tempstack = createstack();
    if(*top == NULL)
        *top = tempstack;
    else
    {
        tempstack->next = *top;
        *top = tempstack;
    }     
    displayLinkedList(*top);
}

void pop(struct stack** top)
{
    if(*top == NULL)
        printf("Stack is Empty.\n");
    else
    {
        struct stack* temptop = NULL;
        temptop = *top;
        *top = (*top)->next;
        printf("Poped element is %d.\n",temptop->data);
        free (temptop);
        displayLinkedList(*top);
    }
}

void peak(struct stack* top)
{
    if(top == NULL)
        printf("Stack is Empty.\n");
    else
        printf("Top element is %d.\n",top->data);
}