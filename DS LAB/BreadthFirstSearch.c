#include <stdio.h>
#include <stdlib.h>
int a[20][20], visited[20], n, i, j, f = 0, r = -1, q[20], v;
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
        {
            visited[i] = 1;
            printf("%d\t", i);
            q[++r] = i;
        }
    if (f <= r)
        bfs(q[f++]);
}
void main()
{
    printf("Enter the number of Vertices:");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Starting Vertex:");
    scanf("%d", &v);
    visited[v] = 1;
    printf("BFS:\t%d\t", v);
    bfs(v);
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        else
        {
            printf("\nGraph is Not Connected\n");
            exit(0);
        }
    }
    printf("\nGraph is Connected\n");
}
