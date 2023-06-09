#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int* arr;
    int top;
    int capacity;
};

struct stack* createStack();
void push(struct stack*);
int isFull(struct stack*);
void displayStack(struct stack*);
void pop(struct stack*);
int isEmpty(struct stack*);
void peak(struct stack*);

void main()
{
    struct stack* stack1 = NULL;
    int ch;
    printf("****************** Stack ****************\n");
    printf("1. Push Element into Stack.\n");
    printf("2. Pop Element into Stack.\n");
    printf("3. Peak Element into Stack.\n");
    printf("4. Display Stack.\n");

    stack1 = createStack();
    while(1)
    {   
        printf("Enter choice to Select : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(stack1);
                    break;

            case 2: pop(stack1);
                    break;

            case 3: peak(stack1);
                    break;

            case 4: displayStack(stack1);
                    break;
        }
        if(ch<1 || ch>4)
            break;
    }
}

struct stack* createStack()
{
    struct stack* tempStack = NULL;
    tempStack = (struct stack*)malloc(sizeof(struct stack));
    if(tempStack == NULL)
        printf("Memory Not allocated.\n");
    else
    {
        printf("Enter capacity of Stack : ");
        scanf("%d",&(tempStack->capacity));
        tempStack->arr = (int*)malloc( (tempStack->capacity) * sizeof(int) );
        tempStack->top = -1;
        return tempStack;
    }
}

void push(struct stack* stack)
{
    if(isFull(stack))  
        printf("Stack is Full.\n");
    else
    {
        printf("Enter data to push in stack : ");
        scanf("%d",&(stack->arr[++(stack->top)]));
        displayStack(stack);
    }
}

int isFull(struct stack* stack)
{
    return (stack->top == stack->capacity-1);
}

void  displayStack(struct stack* stack)
{
    if(stack->top == -1)
        printf("Stack is Empty.\n");
    else
    {
        int i;
        printf("Stack = ");
        for(i=0;i<=stack->top;i++)
            printf("   %d",stack->arr[i]);
        printf("\n");
    }
}

void pop(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Stack is Empty.\n");
    else
    {
        printf("Top element %d is deleted.\n",stack->arr[stack->top]);
        (stack->top)--;
        displayStack(stack);
    }
}

int isEmpty(struct stack* stack)
{
    return stack->top < 0; 
}

void peak(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Stack is Empty.\n");
    else
        printf("Top element is %d.\n",stack->arr[stack->top]);
}