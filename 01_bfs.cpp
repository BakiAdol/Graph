// Complexity O(V+E); where V=Vertices, E=Edge

vector<int> adjList[100];
bool visited[100];

vector<int> bfs(int startNode, int numberOfNode)
{
    vector<int> visitedList;
    queue<int> q;
    q.push(startNode);
    visited[startNode]=1;
    visitedList.push_back(startNode);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adjList[u].size();i++)
        {
            if(visited[adjList[u][i]]==0)
            {
                int v = adjList[u][i];
                visited[v]=1;
                visitedList.push_back(v);
                q.push(v);
            }
        }
    }
    return visitedList;
}
