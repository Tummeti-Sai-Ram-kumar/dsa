#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(vector <int> adj[],int index,vector <bool> &visited)
{
	cout<<index<<" ";
	visited[index]=true;
	vector <int> temp=adj[index];
	for(int i=0;i<temp.size();i++)
	{
		if(visited[temp[i]]==false)
		{
			dfs(adj,temp[i],visited);
		}
	}
}

void dfs_wrapper(vector<int> adj[],int v)
{
	vector <bool> visited={false};
	visited.resize(v);
	
	int start_index=0;
	dfs(adj,start_index,visited);
}

int main()
{
	int v;
	cout<<"Enter the number of nodes :  ";
	cin>>v;
	
	vector <int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);
	
	dfs_wrapper(adj,v);
}