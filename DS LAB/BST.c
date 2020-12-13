#include<stdio.h>
#include<stdlib.h>

struct bst
{
        struct bst *lc,*rc;
        int data;
};

struct bst *root=NULL;

struct bst* getnode(int k)
{
        struct bst *temp=(struct bst*)malloc(sizeof(struct bst));
        temp->data=k;
        temp->lc=temp->rc=NULL;
        return temp;

}

struct bst* minval(struct bst *node)
{
        while(node->lc!=NULL)
                node=node->lc;
        return node;
}

struct bst* insert(struct bst *root,int data)
{
        if (root==NULL)
                return getnode(data);
        else if(data < root->data)
                root->lc=insert(root->lc,data);
        else
                root->rc=insert(root->rc,data);
        return root;
}


int search(struct bst *temp,int key)
{
        if(temp==NULL)
                return 0;
        if(temp->data==key)
                return 1;
        else if(temp->data < key)
                search(temp->rc,key);
        else
                search(temp->lc,key);
}

void inorder(struct bst *root)
{
        if(root==NULL)
                return;
        else
        {
                inorder(root->lc);
                printf("%d  ",root->data);
                inorder(root->rc);
        }
}

void preorder(struct bst *root)
{
        if(root==NULL)
                return;
        else
        {
                printf("%d  ",root->data);
                preorder(root->lc);
                preorder(root->rc);
        }
}

void postorder(struct bst *root)
{
        if(root==NULL)
                return;
        else
        {
                postorder(root->lc);
                postorder(root->rc);
                printf("%d  ",root->data);
        }
}

struct bst* del(struct bst *root,int key)
{
        if(root==NULL)
                return root;
        if(key > root->data)
                root->rc=del(root->rc,key);
        else if(key < root->data)
                root->lc=del(root->lc,key);
        else
        {
                if(root->lc==NULL)
                {
                        struct bst *temp=root->rc;
                        free(root);
                        return temp;
                }
                else if(root->rc==NULL)
                {
                        struct bst *temp=root->lc;
                        free(root);
                        return temp;
                }
                else
                {
                        struct bst *temp=minval(root->rc);
                        root->data=temp->data;
                        root->rc=del(root->rc,temp->data);
                }

        }
        return root;
}

void main()
{
while(1){
        int op;
        printf("1.INSERT\n2.DELETE\n3.TRAVERSE\n4.SEARCH\n5.EXIT\n");
        printf("SELECT AN OPERATION:");
        scanf("%d",&op);
        switch(op)
        {
                case 1:
                printf("Enter Data:");
                int data;
                scanf("%d",&data);
                root=insert(root,data);
                break;

                case 2:
                printf("Enter key:");
                int dl;
                scanf("%d",&dl);
                root=del(root,dl);
                break;

                case 3:
                printf("1.PREORDER\n2.INORDER\n3.POSTORDER\n");
                int opt;
                printf("Select an Option:");
                scanf("%d",&opt);
                if(opt==1)
                {
                        printf("PREORDER:");
                        preorder(root);
                }
                else if(opt==2)
                {
                        printf("INORDER:");
                        inorder(root);
                }
                else if(opt==3)
                {
                        printf("POSTORDER:");
                        postorder(root);
                }
                printf("\n");
                break;

                case 4:
                printf("Enter key");
                int key,result;
                scanf("%d",&key);
                result=search(root,key);
                if(result==0)
                        printf("No ");
                printf("Key Found\n");
                break;

                case 5:
                exit(0);
                break;
                default:printf("INVALID INPUT\n");
        }
}
}
