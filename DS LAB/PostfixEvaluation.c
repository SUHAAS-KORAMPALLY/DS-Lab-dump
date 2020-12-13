//POSTFIX EVALUTION
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//using ++top  and  --top in main instead of push and pop functions
void main()
{
        char postfix[100],*token;int stack[100],top=-1;
        printf("(\"Give SPACE between OPERATORS and OPERANDS\")\nEnter the POSTFIX Expression:");
        gets(postfix);
        for(token=strtok(postfix," ");token!=NULL;token=strtok(NULL," "))
        {
                if(!strcmp(token,"+"))  //  !strcmp(token,"+") is similar to  strcmp(token,"+")==0
                {
                        stack[top-1]+=stack[top];
                        --top;
                }

                else if(!strcmp(token,"-"))
                {
                        stack[top-1]-=stack[top];
                        --top;
                }

                else if(!strcmp(token,"*"))
                {
                        stack[top-1]*=stack[top];
                         --top;
                }

                else if(!strcmp(token,"/"))
                {
                        stack[top-1]/=stack[top];
                        --top;
                }

                else if(!strcmp(token,"^"))
                {
                        stack[top-1]=pow(stack[top-1],stack[top]);
                        --top;
                }

                else
                {
                        ++top;
                        stack[top]=atoi(token);
                }
        }

                printf("RESULT=%d",stack[top]);
}


