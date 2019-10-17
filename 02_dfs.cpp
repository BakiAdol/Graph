
vector<int> adjList[100];

bool visited[100];

void dfs(int source)
{
    visited[source]=1;
    cout << " " << source;
    for(int i=0;i<(int)adjList[source].size();i++)
    {
        if(!visited[adjList[source][i]])
        {
            dfs(adjList[source][i]);
        }
    }
}
