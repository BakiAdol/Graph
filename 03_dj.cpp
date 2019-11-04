#include <bits/stdc++.h>

using namespace std;

const int numberOfVertex=10;

int minimumDistance( int distance[], bool visited[])
{
    int minimum=INT_MAX;
    int minimumPos=0;

    for(int v=0;v<numberOfVertex;v++)
    {
        if(!visited[v] && distance[v]<=minimum)
        {
            minimum=distance[v];
            minimumPos=v;
        }
    }

    return minimumPos;
}

void dj(int mat[numberOfVertex][numberOfVertex], int source)
{
    int distance[numberOfVertex];
    bool visited[numberOfVertex];

    for(int i=0;i<numberOfVertex;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    }

    distance[source]=0;

    for(int i=0;i<numberOfVertex-1;i++)
    {
        int u=minimumDistance(distance,visited);
        visited[u]=true;
        for(int v=0;v<numberOfVertex;v++)
        {
            if(!visited[v] && mat[u][v] !=0 && distance[u]!=INT_MAX && distance[u]+mat[u][v]<distance[v])
            {
                distance[v]=distance[u]+mat[u][v];
            }
        }
    }

    cout << "Distance from source " << source << " to each vertex:" << endl;
    cout << "Vertex\tDistance" << endl;
    for(int i=0;i<numberOfVertex;i++)
    {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main()
{

    int graph[numberOfVertex][numberOfVertex] = {{0, 14, 0, 7, 0, 0, 0, 8, 0, 10},
                                             {14, 0, 8, 0, 0, 0, 0, 11, 0, 0},
                                             {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
                                             {7, 0, 7, 0, 9, 12, 0, 0, 0, 5},
                                             {0, 0, 0, 9, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 4, 0, 0, 0, 2, 0, 0, 11},
                                             {0, 0, 0, 12, 0, 2, 0, 1, 6, 15},
                                             {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
                                             {0, 0, 2, 0, 0, 0, 6, 7, 0, 0},
                                             {10, 0, 0, 5, 0, 11, 15, 0, 0, 0}};

    dj(graph, 9);

    return 0;
}

