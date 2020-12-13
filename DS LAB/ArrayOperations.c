#include<stdio.h>
#include<stdlib.h>
//_________________________________________________________
void insert(int *n,int a[])
{
int k,ind;
printf("Enter the key");
scanf("%d",&k);
printf("Enter the index");
scanf("%d",&ind);
for(int i=*n-1;i>=ind;i--)
a[i+1]=a[i];
a[ind]=k;
*n=*n+1;
}
//____________________________________________________________
void rev(int n,int a[])
{int t;
for(int i=0,j=n-1;i+1<=j;i++,j--)
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
//___________________________________________________________

void traverse(int n,int a[])
{
printf("In traverse=%d\n",n);
for(int i=0;i<n;i++)
printf("%d\n",a[i]);
}
//__________________________________________________________

void del(int *n,int a[])
{
int ind=-1,k;
printf("Enter the key");
scanf("%d",&k);
for(int i=0;i<*n;i++)
if(a[i]==k)
        {
        ind=i;
        break;
        }
if(ind==-1)
{printf("No such element found.\n");
exit(0);}
for(int i=ind;i<*n;i++)
a[i]=a[i+1];
*n=*n-1;
}
//__________________________________________________________


void main()
{
int n,k,ind,op;
printf("Enter the number of elements:\n");
scanf("%d",&n);
int a[n];
printf("Enter the elements:\n");
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
while(1){
printf("Select an operation:\n");
printf("1.Reverse\n2.Insert\n3.Delete\n4.Traverse\n5.Exit");
scanf("%d",&op);
switch (op)
{
case 1:
rev(n,a);
break;
case 2:
insert(&n,a);
break;
case 3:
del(&n,a);
break;
case 4:
traverse(n,a);
break;
default: exit(0);
}
}
}
