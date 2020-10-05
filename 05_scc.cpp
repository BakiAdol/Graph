/**
 * SCC(Strongly Connected Component)
 * Step 1: visit all node
 * Step 2 : reverse all edges
 * Step 3: visi all node
 * 
 * Algorithm idea : if some node are scc and then if you reverse all edges of those nodes 
 *                  then they are still scc.
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> adj[100],rev[100];

bool visited[100];

stack<int> stk;

void makeGraph()
{
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(1);
	adj[3].push_back(5);
	adj[5].push_back(6);
	adj[6].push_back(7);
	adj[7].push_back(5);
	adj[7].push_back(8);
}

void reverseGraph()
{
	///reverse all edge of this graph
	rev[2].push_back(1);
	rev[3].push_back(2);
	rev[4].push_back(3);
	rev[1].push_back(4);
	rev[5].push_back(3);
	rev[6].push_back(5);
	rev[7].push_back(6);
	rev[5].push_back(7);
	rev[8].push_back(7);
}

void dfs(int node)
{
	visited[node]=true;
	
	for(int x : adj[node])
	{
		if(visited[x]==0) dfs(x);
	}
	
	stk.push(node);
}

void dfsRev(int node)
{
	visited[node]=true;
	
	for(int x : rev[node])
	{
		if(visited[x]==0) dfsRev(x);
	}
	cout <<  " " << node;
}

int main()
{
	makeGraph();
	n=8;
	int x,cou=0;
	
	/// visite all node of this graph
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0) dfs(i);
	}
	
	reverseGraph();
	
	memset(visited,0,sizeof(visited));
	
	while(!stk.empty())
	{
		x=stk.top();
		stk.pop();
		
		if(visited[x]==0)
		{
			cout << "SCC " << ++cou << ":";
			dfsRev(x);
			cout << endl;
		}
	}
	
	return 0;
}

