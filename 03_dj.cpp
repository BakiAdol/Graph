/**
 * Dijkstra single source sortest path algorithm
 * */

#include <bits/stdc++.h>

using namespace std;

int n=10;

int graph[10][10] = {{0, 14, 0, 7, 0, 0, 0, 8, 0, 10},
                   {14, 0, 8, 0, 0, 0, 0, 11, 0, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
                   {7, 0, 7, 0, 9, 12, 0, 0, 0, 5},
                   {0, 0, 0, 9, 0, 0, 0, 0, 0, 0},
                   {0, 0, 4, 0, 0, 0, 2, 0, 0, 11},
                   {0, 0, 0, 12, 0, 2, 0, 1, 6, 15},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0, 0},
                   {10, 0, 0, 5, 0, 11, 15, 0, 0, 0}};
                   
bool visited[15];
int dis_tance[15];

class cmp{
	// pair<nodeNumber,distanceFromSource>
	public:
	bool operator () (const pair<int,int> a, const pair<int,int> b)
	{
		return a.second>b.second;
	}
};

void dj(int source)
{
	int node;
	
	for(int i=0;i<n;i++) dis_tance[i]=100000000;
	
	dis_tance[source]=0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	pq.push({source,0});
	
	while(!pq.empty())
	{
		node=pq.top().first;
		
		pq.pop();
		
		if(visited[node]) continue;
		visited[node]=true;
		
		for(int i=0;i<n;i++)
		{
			if(graph[node][i])
			{
				if(dis_tance[i]>dis_tance[node]+graph[node][i])
				{
					dis_tance[i]=dis_tance[node]+graph[node][i];
					pq.push({i,dis_tance[i]});
				}
			}
		}
	}
}


int main() 
{ 
	dj(0);
	
	for(int i=0;i<n;i++) cout << dis_tance[i] << " ";
	
	return 0;
} 
