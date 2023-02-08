#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(vector <int> adj[],vector <int> &dist,int v)
{
	vector <bool> visited={false};
	visited.resize(v);
	queue <int> q;
	q.push(0);
	visited[0]=true;
	dist[0]=0;
	while(!q.empty())
	{
		int curr_node=q.front();
		q.pop();
		vector <int> temp=adj[curr_node];
		for(int i=0;i<temp.size();i++)
		{
			if(visited[temp[i]]==false)
			{
				visited[temp[i]]=true;
				dist[temp[i]]=dist[curr_node]+1;
				q.push(temp[i]);
			}
		}
	}
}



int main()
{
	int v;
	cout<<"Enter the number of nodes :";
	cin>>v;
	
	vector <int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,0,2); 
	addEdge(adj,1,3);
	
	vector <int> dist={INT_MAX};
	dist.resize(v);
	
	bfs(adj,dist,v);
	
	for(int i=0;i<v;i++)
	{
		cout<<dist[i]<<" ";
	}
}