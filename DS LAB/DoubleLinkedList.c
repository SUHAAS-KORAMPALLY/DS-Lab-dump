#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
};

int l=0;
struct node *root=NULL;
struct node* pos(int p)
{
    int c;
    struct node *temp=root;
    for(c=1;c<p;c++)
    temp=temp->rlink;
    return temp;
}
void ins(int p,int k)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=k;
    if(p<1 || p>l+1)
        printf("INVALID POSITION:\n");
    else
    {
        if(p==1)
        {
            temp->rlink=root;
            temp->llink=NULL;
            root=temp;
        }
        else
        {
            struct node *posi=pos(p-1);
            temp->rlink=posi->rlink;
            temp->llink=posi;
            posi->rlink=temp;
            if(p!=l+1)
            {
                posi=temp->rlink;
                posi->llink=temp;
            }
        }
        ++l;
    }
}
void del(int p)
{
    if(p<1 || p>l)
        printf("INVALID POSITION");
    else
    {
        struct node *posi=pos(p);
        if(p==1)
        {
            root=root->rlink;
            free(posi);
        }
        else
        {
            struct node *posi1=pos(p-1);
            if(p==l)
                posi1->rlink=NULL;
            else
            {
                struct node *posi2=pos(p+1);
                posi2->llink=posi1;
                posi1->rlink=posi->rlink;
            }free(posi);

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
        struct node * temp=root;
        do
        {
            printf("%d\n",temp->data);
            temp=temp->rlink;
        }while(temp!=NULL);
    }
}
int main()
{
    while(1)
    {
        int op,p1,p;
        printf("OPERATIONS ON DOUBLE LINKED LIST\n");
        printf("1.INSERT\n2.DELETE\n3.TRAVERSE\n4.Length\n");
        printf("SELECT AN OPERATION:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter Position:");
            int p,k;
            scanf("%d",&p);
            printf("Enter Data:");
            scanf("%d",&k);
            ins(p,k);
            break;
        case 2:
            printf("Enter Position");
            scanf("%d",&p1);
            del(p1);
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("Length=%d\n",l);
            break;
        case 5:
            exit(0);
            break;
        default:printf("INVALID INPUT\n");

        }
}
}
