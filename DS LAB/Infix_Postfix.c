#include<stdio.h>
char stack[100];int top=-1;

void push(char k)
{
        ++top;
        stack[top]=k;
}

void pop()
{
        printf("%c",stack[top]);
        --top;
}

void main()
{
        char infix[100];
        printf("Enter the INFIX Expression:");
        scanf("%s",infix);
        printf("POSTFIX Expression:");
        for(int i=0;infix[i]!='\0';i++)
        switch(infix[i])
        {
                case '+':
                case '-':
                while(stack[top]!='(' && top!=-1)
                pop();
                push(infix[i]);
                break;

                case '*':
                case '/':
                while(stack[top]=='*' || stack[top]=='/' || stack[top]=='^')
                pop();
                push(infix[i]);
                break;

                case '(':
                case '^':
                push(infix[i]);
                break;

                case ')':
                while(stack[top]!='(')
                pop();
                --top;
                break;

                default:printf("%c",infix[i]);
        }
        while(top!=-1)
        pop();
        printf("\n");
}
