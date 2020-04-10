#include<stdio.h>
#include<stdlib.h>
#define max 10
int top=0;
int stack[max];

void push(int k)
{
        if(top==max)
                printf("STACK-OVERFLOW\n");
        else
        {
                stack[top]=k;
                ++top;
        }
}

void pop()
{
        if(top==0)
                printf("STACK-UNDERFLOW\n");
        else
        {
                printf("%d is POPPED\n",stack[top-1]);
                --top;
        }
}

void traverse()
{
        if(top==0)
                printf("STACK IS EMPTY\n");
        else
        for(int i=top-1;i>=0;i--)
                printf("%d\n",stack[i]);
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
                        printf("ENTER AN ELEMENT:");
                        int k;
                        scanf("%d",&k);
                        push(k);
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

                        default:
                        printf("INVALID INPUT\n");
                }
        }
}
