#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        int prty;
        struct node *link;
};

struct node *front = NULL,*rear = NULL;

void enqueue()
{
        struct node *temp= (struct node *)malloc(sizeof(struct node)),*temp2=front,*temp3;
        if(temp==NULL)
                printf("QUEUE OVERFLOW\n");
        else
        {
                printf("Enter data:");
                scanf("%d", &temp->data);
                printf("Enter priority:");
                int pr;
                scanf("%d",&pr);
                temp->prty=pr;
                temp->link=NULL;
                if(front==NULL)
                {
                        front=temp;
                        rear=front;
                }
                else
                {
                        while(temp2->prty<=pr)
                        {
                                temp3=temp2;
                                if(temp2->link==NULL)
                                {
                                        temp2->link=temp;
                                        return;
                                }
                                temp2=temp2->link;
                        }
                        temp->link=temp2;
                        temp3->link=temp;
                }
        }
}

void dequeue()
{
        if(front==NULL)
                printf("QUEUE UNDERFLOW\n");
        else
        {
                struct node *temp=(struct node *)malloc(sizeof(struct node));
                temp=front;
                front=front->link;
                printf("%d is DEQUEUED",temp->data);
                free(temp);
        }
}

void traverse()
{
    if (front == NULL)
        printf("\x1b[31m"
               "NO DATA TO TRAVERSE\n"
               "\x1b[0m");
    else
    {
       struct node *temp = front;
        do
        {
            printf("\x1b[33m"
                   "%d   %d\n"
                   "\x1b[0m",
                   temp->data,temp->prty);
            temp = temp->link;
        } while (temp != NULL);
    }
}


void main()
{
        int op;
        while(1)
        {
                printf("OPERATIONS ON PRIORITY-QUEUE\n");
                printf("1.ENQUEUE\n2.DEQUEUE\n3.TRAVERSE\n4.EXIT\n");
                printf("SELECT AN OPERATION:");
                scanf("%d",&op);

                switch(op)
                {
                        case 1:
                        enqueue();
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

