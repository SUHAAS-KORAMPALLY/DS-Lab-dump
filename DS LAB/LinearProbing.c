#include <stdio.h>
#include <stdlib.h>

int max = 10;
int ht[10];

int hashcode(int key)
{
    return (key % max);
}
void insert(int x)
{
    int index = hashcode(x);
    int i = index, j = 1;

    while (ht[i] != -1)
    {
        i = (index + j) % max;
        if (i == index)
        {
            printf("\n Hash table is full, cannot insert any more item \n");
            return;
        }
        j++;
    }
    ht[i] = x;
    printf("\n Key (%d) has been inserted \n", x);
}

void delete (int x)
{
    int index = hashcode(x);
    int i = index, j = 1;

    while (ht[i] != x)
    {
        i = (index + j) % max;
        if (i == index)
        {
            printf("\n This key does not exist \n");
            return;
        }
        j++;
    }
    if (ht[i] == x)
    {
        printf("\n Element (%d) has been found and removed \n", x);
        ht[i] = -1;
    }
}
void display()
{
    int i;
    printf("Elements in hash table are");
    for (i = 0; i < max; i++)
    {
        printf("%d\n", ht[i]);
    }
}

void main()
{
    int choice, value, i;
    for (i = 0; i < 10; i++)
        ht[i] = -1;
    while (1)
    {
        printf("1.Insert\n2.Remove\n3.Display\n4.Exit\n");
        printf("Enter the Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            printf("Enter the element to be Removed:");
            scanf("%d", &value);
            delete (value);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }
}
