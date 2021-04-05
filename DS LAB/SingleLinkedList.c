#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;
int l = 0;

struct node *posi(int i)
{
    struct node *p = root;
    for (int c = 1; c < i; c++)
        p = p->link;
    return p;
}

void insert(int pos)
{
    if (pos > l + 1 || pos < 1)
        printf("INVALID POSITION\n");
    else
    {
        int c = 1;
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &temp->data);
        if (pos == 1)
        {
            temp->link = root;
            root = temp;
        }
        else
        {
            struct node *p = posi(pos - 1);
            temp->link = p->link;
            p->link = temp;
        }
        ++l;
    }
}

void traverse()
{
    if (root == NULL)
        printf("NO DATA TO TRAVERSE\n");
    else
    {
        struct node *temp = root;
        do
        {
            printf("%d --> ", temp->data);
            temp = temp->link;
        } while (temp != NULL);
    }
    printf("NULL\n");
}

void del()
{
    int pos;
    printf("Enter position to be Deleted:");
    scanf("%d", &pos);
    if (pos > l || pos < 1)
        printf("INVALID POSITION\n");
    else
    {
        struct node *p;

        if (pos == 1)
        {
            p = root;
            root = root->link;
            free(p);
        }
        else
        {
            int c = 1;
            struct node *temp;
            p = posi(pos - 1);
            temp = p;
            p = p->link;
            temp->link = p->link;
            free(p);
        }
        --l;
    }
}

void swap(int x, int y)
{
    if (x > l || y > l || x < 1 || y < 1)
        printf("INVALID POSITIONS\n");
    else
    {
        int t;
        struct node *p1, *p2;
        p1 = posi(x);
        p2 = posi(y);
        t = p1->data;
        p1->data = p2->data;
        p2->data = t;
    }
}

void rev()
{
    struct node *prev = NULL, *current = root, *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    root = prev;
}
void sort()
{
    int i, j;
    for (i = 1; i <= l; i++)
        for (j = 1; j <= l; j++)
            if (posi(i)->data < posi(j)->data)
                swap(i, j);
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        int op;
        printf(
            "OPERTIONS ON LIST"
            "\n"
            "1.APPEND\n"
            "2.INSERT\n"
            "3.LENGTH\n"
            "4.TRAVERSE\n"
            "5.DELETE\n"
            "6.REVERSE\n"
            "7.SWAP\n"
            "8.SORT\n"
            "9.EXIT\n");
        printf("SELECT AN OPERATION:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert(l + 1);
            break;
        case 2:
            printf("Enter the position:");
            int pos;
            scanf("%d", &pos);
            insert(pos);
            break;
        case 3:
            printf("Length of list = %d\n", l);
            break;
        case 4:
            traverse();
            break;
        case 5:
            del();
            break;
        case 6:
            rev();
            break;
        case 7:
            printf("Enter any two positions:");
            int a, b;
            scanf("%d%d", &a, &b);
            swap(a, b);
            break;
        case 8:
            sort();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("INVALID INPUT\n");
        }
    }
    return 0;
}
