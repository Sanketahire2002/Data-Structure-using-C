#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int* arr;
    int capacity,size,front,rear;
};

struct queue* createqueue();
void enqueue(struct queue*);
void displayqueue(struct queue*);
void dequeue(struct queue*);
void peak(struct queue*);

void main()
{
    struct queue* queue = NULL;
    int ch;
    printf("****************** Circular Queue ****************\n");
    printf("1. Push Element into circular queue.\n");
    printf("2. Pop Element into circular queue.\n");
    printf("3. Peak Element into circular queue.\n");
    printf("4. Display circular queue.\n");

    queue = createqueue();
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

            case 3: peak(queue);
                    break;

            case 4: displayqueue(queue);
                    break;
        }
        if(ch<1 || ch>4)
            break;
    }
}

struct queue* createqueue()
{
	struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
	if(queue == NULL)
		printf("Memory Not Allocated\n");
	else
	{
		printf("Enter capacity of Queue : ");
		scanf("%d",&(queue->capacity));
		queue->front = queue->rear = -1;
		queue->size = 0;
		queue->arr = (int*)malloc((queue->capacity) * sizeof(int));
		return queue;
	}
}

void enqueue(struct queue* queue)
{
	if(queue->size == queue->capacity)
		printf("Queue is Full.\n");
	else
	{
		printf("Enter Element : ");
		queue->rear = (queue->rear + 1) % (queue->capacity);
		scanf("%d",&(queue->arr[queue->rear]));
		(queue->size)++;
	}
}

void displayqueue(struct queue* queue)
{
	int i,x;
	if(queue->size == 0)
		printf("Queue is Empty.\n");
	else
	{
		x = queue->front;
		printf("Queue : ");
		for(i=0;i<(queue->size);i++)
		{
			x = (x + 1) % (queue->capacity);
			printf("   %d",queue->arr[x]);
		}
		printf("\n");
	}
}

void dequeue(struct queue* queue)
{
	if(queue->size != 0)
	{	
		printf("%d is deleted.\n",queue->arr[(queue->front + 1) % (queue->capacity)]);
		queue->front = (queue->front + 1) % (queue->capacity);
		(queue->size)--;
	}
}

void peak(struct queue* queue)
{
	if(queue->front == queue->size-1)
		queue->front = -1;
	if(queue->size != 0)
		printf("Front = %d\tRear = %d\n",queue->arr[queue->front+1],queue->arr[queue->rear]);
	else
		printf("Queue is Empty.\n");
}