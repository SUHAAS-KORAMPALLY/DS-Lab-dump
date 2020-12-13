#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc, *rc;
};
int height(struct node *root)
{
    int h_left, h_right;
    if (root == NULL)
        return 0;
    h_left = height(root->lc);
    h_right = height(root->rc);
    if (h_left > h_right)
        return 1 + h_left;
    else
        return 1 + h_right;
}
int isAVL(struct node *root)
{
    int h_l, h_r, diff;
    if (root == NULL)
        return 1;
    h_l = height(root->lc);
    h_r = height(root->rc);
    diff = h_l > h_r ? h_l - h_r : h_r - h_l;
    if (diff <= 1 && isAVL(root->lc) && isAVL(root->rc))
        return 1;
    else
        return 0;
}
unsigned int getLeafCount(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->lc == NULL && root->rc == NULL)
        return 1;
    else
        return getLeafCount(root->lc) + getLeafCount(root->rc);
}
struct node *getnode(int k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->lc = temp->rc = NULL;
    return temp;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return getnode(data);
    else if (data < root->data)
        root->lc = insert(root->lc, data);
    else if (data > root->data)
        root->rc = insert(root->rc, data);
    else
        printf("Dublicate Value");
    return root;
}
void main()
{
    struct node *root = NULL;
    int n, i, data;
    printf("Enter the number of Nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data:");
        scanf("%d", &data);
        root = insert(root, data);
    }
    if (isAVL(root))
        printf("\nTree is AVL\n");
    else
        printf("\nTree is not AVL\n");
    printf("Height:%d\n", height(root));
    printf("Number of Leaf Nodes:%d\n", getLeafCount(root));
}
