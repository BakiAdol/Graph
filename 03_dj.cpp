/**
 * Dijkstra shortest path algorithm
 * Complexity:
 * extract min need O(V logV)
 * Relaxing time O(E logV)
 * so complexity O(E logV)
 */
#include <bits/stdc++.h>

using namespace std;
// graph.first = node, graph.second = edge value
vector<int> shortestPathUsingDijkstra(vector<pair<int,int>> graph[8], int root, int nodes)
{
    vector<int> shortestDistance(nodes,INT_MAX);
    vector<bool> visited(nodes,0);
    // edge value, node
    auto cmp = [](auto &a,  auto &b){
        return a.first>b.first;
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    pq.push({0,root});
    visited[root] = true;

    while(!pq.empty())
    {
        int parent = pq.top().second;
        int minDis = pq.top().first;

        if(visited[parent]) pq.pop();
        else visited[parent] = true;

        for(auto &child: graph[parent])
        {
            if(shortestDistance[child.first] > child.second+minDis)
            {
                shortestDistance[child.first] = child.second+minDis;
                pq.push({shortestDistance[child.first],child.first});
            }
        }
    }

    return shortestDistance;
}

int main()
{
    int node=7, parent=1;
    vector<pair<int,int>> graph[8];

    graph[1].push_back({2,1});
    graph[1].push_back({3,5});
    graph[2].push_back({3,2});
    graph[2].push_back({4,2});
    graph[2].push_back({5,1});
    graph[3].push_back({5,2});
    graph[4].push_back({5,3});
    graph[4].push_back({6,1});
    graph[5].push_back({6,2});


    vector<int> dist = shortestPathUsingDijkstra(graph,parent,node);

    cout << "Shortest path from: " << endl;
    for(int i=1;i<7;i++)
    {
        if(i==parent) continue;
        cout << parent << " to " << i << " = " << dist[i] << endl;
    }

    return 0;
}
