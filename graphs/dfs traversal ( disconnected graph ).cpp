#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}

void dfs(vector <int> adj[],int i,vector <bool> &visited)
{
	cout<<i<<" ";
	visited[i]=true;
	
	vector <int> temp=adj[i];
	for(int j=0;j<temp.size();j++)
	{
		if(visited[temp[j]]==false)
		{
			dfs(adj,temp[j],visited);
		}
	}
}

void dfs_wrapper(vector <int> adj[],int v)
{
	vector <bool> visited = {false};
	visited.resize(v);
	
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,visited);
			cout<<endl;
		}
	}
}

int main()
{
	int v;
	cout<<"Enter the number of nodes :  ";
	cin>>v;
	
	vector <int> adj[v];
	
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);
	
	dfs_wrapper(adj,v);
}