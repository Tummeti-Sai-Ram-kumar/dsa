#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool dfs(vector <int> adj[],int i,vector <bool> &visited,int parent)
{
	int curr_node=i;
	visited[i]=true;
	vector <int> temp=adj[curr_node];
	
	for(int j=0;j<temp.size();j++)
	{
		if(visited[temp[j]]==false)
		{
			if(dfs(adj,temp[j],visited,curr_node)==true)
			return true;
		}
		else if(temp[j]!=parent)
		{
			return true;
		}
	}
	return false;
}

bool dfs_wrapper(vector <int> adj[],int v)
{
	vector <bool> visited={false};
	visited.resize(v);
	for(int i=0;i<v;i++)
	{
		if(dfs(adj,i,visited,-1)==true)   // initially parent is set tto -1 for the root node 
		return true;
	}
	return false;
}

int main()
{
	int v;
	cout<<"Enter the number of nodes :";
	cin>>v;
	
	vector <int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	
	if(dfs_wrapper(adj,v))
	cout<<"Cycle found "<<endl;
	else
	cout<<"Cycle not found";
}