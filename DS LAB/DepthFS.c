#include <stdio.h>
#include <stdlib.h>
int a[20][20], reach[20], n, i, j, v;
void dfs(int v)
{
    int i;
    for (i = 1; i <= n; i++)
        if (a[v][i] && !reach[i])
        {
            reach[i] = 1;
            printf("%d\t", i);
            dfs(i);
        }
}
void main()
{
    printf("Enter number of vertices:");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the starting vertex:");
    scanf("%d", &v);
    reach[v] = 1;
    printf("DFS:\t%d\t", v);
    dfs(v);
    for (i = 1; i <= n; i++)
    {
        if (reach[i])
            continue;
        else
        {
            printf("\nGraph is Not Connected\n");
            exit(0);
        }
    }
    printf("\nGraph is Connected\n");
}