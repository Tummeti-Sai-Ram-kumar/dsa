#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

bool dfs(vector <int> adj[],int i,vector <bool> &visited,vector <bool> &rec_stack)
{
	visited[i]=true;
	rec_stack[i]=true;
	
	vector <int> temp=adj[i];
	
	for(int j=0;j<temp.size();j++)
	{
		if(visited[temp[j]]==false)
		{
			if(dfs(adj,temp[j],visited,rec_stack)==true)
			{
				return true;
			}
		}
		else if(rec_stack[temp[j]]==true)
		return true;
	}
	rec_stack[i]=false;
	return false;
}

bool dfs_wrapper(vector <int> adj[],int v)
{
	vector <bool> visited = {false};
	visited.resize(v);
	vector <bool> rec_stack = {false};
	rec_stack.resize(v);
	
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
	    {
	    	if(dfs(adj,i,visited,rec_stack)==true)
	    	return true;
		}
	}
	return false;
}


int main()
{
	int v;
    cout<<"Enter the number of nodes :  ";
	cin>>v;
	
	vector<int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);
	
	if(dfs_wrapper(adj,v))
	cout<<"Cycle found "<<endl;
	else
	cout<<"Cycle not found";
}