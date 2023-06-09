#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int* arr;
    int capacity,front,rear;
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
    printf("****************** queue ****************\n");
    printf("1. Push Element into queue.\n");
    printf("2. Pop Element into queue.\n");
    printf("3. Peak Element into queue.\n");
    printf("4. Display queue.\n");

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
		queue->arr = (int*)malloc((queue->capacity) * sizeof(int));
		return queue;
	}
}

void enqueue(struct queue* queue)
{
	if(queue->rear == (queue->capacity)-1)
		printf("Queue is Full.\n");
	else
	{
		printf("Enter Element : ");
		scanf("%d",&(queue->arr[++(queue->rear)]));
	}
}

void displayqueue(struct queue* queue)
{
	int i;
	if(queue->front == queue->rear)
		printf("Queue is Empty.\n");
	else
	{
		printf("Queue : ");
		for(i=queue->front+1;i<=queue->rear;i++)
			printf("   %d",queue->arr[i]);
		printf("\n");
	}
}

void dequeue(struct queue* queue)
{
	if(queue->front == queue->rear)
		;
	else
		printf("%d is deleted.\n",queue->arr[++(queue->front)]);

}

void peak(struct queue* queue)
{
	if(queue->front != queue->rear)
		printf("Front = %d.\n",queue->arr[queue->front+1]);
	else
		printf("Queue is Empty.\n");
}