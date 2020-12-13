#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[max],front=0,rear=0;

void enqueue(int k)
{
        if(rear==max)
                printf("QUEUE OVERFLOW\n");
        else
        {
                queue[rear]=k;
                ++rear;
        }
}

void dequeue()
{
        if(rear==front)
        {
                printf("QUEUE UNDERFLOW\n");
        }
        else
        {
                printf("%d is DEQUEUED\n",queue[front]);
                ++front;
        }
}

void traverse()
{
        if(front==rear)
                printf("QUEUE IS EMPTY\n");
        else
        {
                for(int i=front;i<rear;i++)
                        printf("%d\n",queue[i]);
        }
}
void main()
{
        int op;
        while(1)
        {
                printf("OPERATIONS ON QUEUE\n");
                printf("1.ENQUEUE\n2.DEQUEUE\n3.TRAVERSE\n4.EXIT\n");
                printf("SELECT AN OPERATION:");
                scanf("%d",&op);

                switch(op)
                {
                        case 1:
                        printf("ENTER AN ELEMENT:");
                        int k;
                        scanf("%d",&k);
                        enqueue(k);
                        break;

                        case 2:
                        dequeue();
                        break;

                        case 3:
                        traverse();
                        break;

                        case 4:
                        exit(0);
                        break;

                        default:printf("INVALID INPUT\n");
                }
        }
}
