#include<stdio.h>
#include<stdlib.h>

struct Element
{
    int data,priority;
};

struct PriorityQ
{
    struct Element** arr;
    int capacity,rear;
};

struct PriorityQ* createPriorityqueue();
void enqueue(struct PriorityQ*);
void dequeue(struct PriorityQ*);
void displayqueue(struct PriorityQ*);

void main()
{
    struct PriorityQ* queue = NULL;
    int ch;
    printf("****************** Priority Queue ****************\n");
    printf("1. Push Element into Priority queue.\n");
    printf("2. Pop Element into Priority queue.\n");
    printf("3. Display Priority queue.\n");

    queue = createPriorityqueue();
    while(1)
    {   
        printf("Enter choice to Select : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(queue);
					displayqueue(queue);
                    break;

            case 2: dequeue(queue);
					displayqueue(queue);
                    break;

            case 3: displayqueue(queue);
                    break;
        }
        if(ch<1 || ch>3)
            break;
    }
}

struct PriorityQ* createPriorityqueue()
{
    struct PriorityQ* queue = NULL;
    queue = (struct PriorityQ*) malloc(sizeof(struct PriorityQ));
    if(queue == NULL)
        printf("Memory Not Allocated.\n");
    else
    {
        printf("Enter capacity of Priority Queue : ");
        scanf("%d",&(queue->capacity));
        queue->rear = -1;
        queue->arr = (struct Element**) malloc((queue->capacity) * sizeof(struct Element*));
        return queue;
    }
}

void enqueue(struct PriorityQ* queue)
{
    if(queue->rear != (queue->capacity) - 1)
    {
        (queue->rear)++;
        queue->arr[(queue->rear)] = (struct Element*)malloc(sizeof(struct Element));
        printf("Enter data : ");
        scanf("%d",&((queue->arr[queue->rear])->data));
        printf("Enter priority : ");
        scanf("%d",&((queue->arr[queue->rear])->priority));
    }
    else
        printf("Queue is Full.\n");
}

void displayqueue(struct PriorityQ* queue)
{
    if(queue->rear == -1)
        printf("Queue is Empty.\n");
    else
    {
        int i;
        printf("Queue data : \t");
        for(i=0;i<=queue->rear;i++)
            printf("\t%d",(queue->arr[i])->data);
        printf("\n");
        printf("Queue Priority : ");
        for(i=0;i<=queue->rear;i++)
            printf("\t%d",(queue->arr[i])->priority);
        printf("\n");
    }
}

void dequeue(struct PriorityQ* queue)
{
    if(queue->rear != -1)
    {
        int i,index,maxPriority;
        index = queue->rear;
        maxPriority = (queue->arr[queue->rear])->priority;
        for(i=0;i<=queue->rear;i++)
            if(maxPriority < (queue->arr[i])->priority)
            {    
                maxPriority = (queue->arr[i])->priority;
                index = i;
            }
        free (queue->arr[index]);
        for(i=index;i<(queue->rear);i++)
            queue->arr[i] = queue->arr[i+1];
        (queue->rear)--;
    }
}