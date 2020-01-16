/*
*
* Topological Sort
*
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
stack<int> res;
bool visited[101];

void dfs(int a)
{
    visited[a]=1;
    for(int i=0;i<(int)adj[a].size();i++)
    {
        if(visited[adj[a][i]]==0) dfs(adj[a][i]);
    }
    res.push(a); // pus child node/last node in this branch, that execute in last
}

int main()
{
    int n,m,u,v;
    cin >> n >> m; // n=number of nodes, m=connect node
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v); // one directional
    }

    for(int i=1;i<=n;i++) if(!visited[i]) dfs(i); // call dfs for each unvisited node

    while(!res.empty())
    {
        u=res.top();
        cout << u;
        res.pop();
        if(!res.empty()) cout << " ";
    }
    cout << endl;

    return 0;
}

