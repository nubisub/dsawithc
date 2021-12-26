// include
#include <stdio.h>

// depth first traversal graph
void dfs(int graph[][10], int n, int s, int visited[])
{
    visited[s] = 1;
    printf("%d ", s);
    for (int i = 0; i < n; i++)
    {
        if (graph[s][i] && !visited[i])
        {
            dfs(graph, n, i, visited);
        }
    }
}
// breadth first traversal graph
void bfs(int graph[][10], int n, int s)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int queue[n];
    int front = -1;
    int rear = -1;
    queue[++rear] = s;
    visited[s] = 1;
    while (front != rear)
    {
        s = queue[++front];
        printf("%d ", s);
        for (int i = 0; i < n; i++)
        {
            if (graph[s][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// main
int main()
{
    int graph[10][10] = {
        
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}

    };
    int visited[10] = {0};
    printf("Depth First     : ");
    dfs(graph, 10, 0, visited);
    printf("\nBreadth First   : ");
    bfs(graph, 10, 0);
    return 0;
}
