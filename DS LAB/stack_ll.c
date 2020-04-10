#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *link;
};

struct node *root=NULL;

void push()
{

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
                printf("STACK-OVERFLOW\n");
        else
        {
                printf("ENTER THE ELEMENT:");
                scanf("%d", &temp->data);
                temp->link = root;
                root = temp;
        }
}

void pop()
{
        if(root==NULL)
                printf("STACK-UNDERFLOW\n");
        else
        {
                printf("%d is POPPED\n",root->data);
                struct node *p = root;
                root = root->link;
                free(p);
        }
}

void traverse()
{
        if (root == NULL)
        printf("\x1b[31m"
               "STACK IS EMPTY\n"
               "\x1b[0m");
        else
        {
                struct node *temp = root;
                do
                {
                        printf("\x1b[33m""%d\n""\x1b[0m",temp->data);
                        temp = temp->link;
                } while (temp != NULL);
        }

}

int main()
{
        int op;
        while(1)
        {
                printf("1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\n");
                printf("SELECT AN OPERATION:");
                scanf("%d",&op);
                switch(op)
                {
                        case 1:
                        push();
                        break;

                        case 2:
                        pop();
                        break;

                        case 3:
                        traverse();
                        break;

                        case 4:
                        exit(0);
                        break;

                        default :
                        printf("INVALID INPUT\n");
                }
        }
}
