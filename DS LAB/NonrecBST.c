#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct node
{
    int data;
    struct node *left, *right;
} bst;
bst *stack1[MAX], *stack2[MAX];
int top1 = -1, top2 = -1;
void push1(bst *root) //Pushes into stack1[MAX]
{
    ++top1;
    stack1[top1] = root;
}
bst *pop1() //Pops out From stack1[MAX]
{
    bst *t;
    t = stack1[top1];
    --top1;
    return t;
}
void push2(bst *root) //Pushes into stack2[MAX]
{
    ++top2;
    stack2[top2] = root;
}
bst *pop2() //Pops out From stack2[MAX]
{
    bst *t;
    t = stack2[top2];
    --top2;
    return t;
}

bst *insertNode(bst *root, int data)
{
    if (root == NULL)
    {
        root = (bst *)malloc(sizeof(bst));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
}
void NonRecPreOrder(bst *root)
{
    bst *temp = root;
    push1(NULL);
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        if (temp->right != NULL)
            push1(temp->right);
        if (temp->left != NULL)
            temp = temp->left;
        else
            temp = pop1();
    }
}
void NonRecInOrder(bst *root)
{
    bst *temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            push1(temp);
            temp = temp->left;
        }
        if (top1 == -1)
            break;
        temp = pop1();
        printf(" %d ", temp->data);
        temp = temp->right;
    }
}
void NonRecPostOrder(bst *root)
{
    bst *temp = root;
    push1(temp);
    while (top1 != -1)
    {
        temp = pop1();
        push2(temp);
        if (temp->left != NULL)
            push1(temp->left);
        if (temp->right != NULL)
            push1(temp->right);
    }
    while (top2 != -1)
    {
        temp = pop2();
        printf(" %d ", temp->data);
    }
}
void main()
{
    bst *root = NULL;
    int n, i, data;
    printf("Enter No.Of Elements in Tree: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter Element to Insert in BST:");
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    printf("\nNon Recursive Traverse: ");
    printf("\nPreOrder: ");
    NonRecPreOrder(root);

    printf("\nInOrder: ");
    NonRecInOrder(root);

    printf("\nPostOrder: ");
    NonRecPostOrder(root);
}
