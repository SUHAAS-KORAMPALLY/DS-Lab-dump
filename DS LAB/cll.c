#include<stdio.h>
#include<stdlib.h>

int l=0;

struct node
{
        int data;
        struct node *link;
};

struct node *root;

struct node* pos(int p)
{
        struct node *temp=root;
        while(p>1)
        {
                temp=temp->link;
                --p;
        }
        return temp;
}

void ins(int k,int p)
{
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->data=k;
        if(p<1 || p>l+1)
                printf("INVALID POSITION\n");
        else
        {
                if(p==1)
                {
                        temp->link=root;
                        root=temp;
                }
                else
                {
                        struct node *p1=pos(p-1);
                        temp->link=p1->link;
                        p1->link=temp;
                }
                ++l;
        }
}

void del(int p)
{
        if(p<1 || p>l)
                printf("INVALID POSITION\n");
        else
        {
                if(p==1)
                {
                        struct node *temp=root;
                        root=root->link;
                        free(temp);
                }
                else
                {
                        struct node *temp1=pos(p-1),*temp2=temp1->link;
                        temp1->link=temp2->link;
                        free(temp2);
                }
                --l;
        }
}

void traverse()
{
        if(root==NULL)
                printf("NO DATA\n");
        else
        {
                struct node *temp=root;int c=0;
                do
                {
                        printf("%d\n",temp->data);
                        temp=temp->link;
                        ++c;
                }while(c<l);
        }
}

void main()
{
        int op;
        while(1)
        {
                printf("OPERATIONS ON CIRCULAR LINKED-LIST\n");
                printf("1.INSERT\n2.DELETE\n3.TRAVERSE\n4.LENGTH\n5.EXIT\n");
                printf("SELECT AN OPERATION:");
                scanf("%d",&op);
                switch(op)
                {
                        case 1:
                        printf("ENTER POSITION:");
                        int p;
                        scanf("%d",&p);
                        printf("ENTER DATA:");
                        int k;
                        scanf("%d",&k);
                        ins(k,p);
                        break;

                        case 2:
                        printf("ENTER THE POSITION:");
                        int q;
                        scanf("%d",&q);
                        del(q);
                        break;

                        case 3:
                        traverse();
                        break;

                        case 4:
                        printf("LENGTH=%d\n",l);
                        break;

                        default:printf("INVALID INPUT\n");
                }
        }
}
