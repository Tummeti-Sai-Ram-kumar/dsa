#include<bits/stdc++.h>
using namespace std;

void bfs(vector <int> adj[],int v)
{
	vector <bool> visited ={false}; // initally visited is set to false 
	visited.resize(v);
	queue <int> q;
	q.push(0);
	visited[0]=true;
	
	while(!q.empty())
	{
		int curr_node=q.front();
		q.pop();
		cout<<curr_node<<" ";
		vector <int> temp=adj[curr_node];
		for(int i=0;i<temp.size();i++)
		{
			if(visited[temp[i]]==false)
			{
				visited[temp[i]]=true;
				q.push(temp[i]);
			}
		}
	}
}

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int v;
    cout<<"Enter the number of nodes : ";
	cin>>v;
	
	vector <int> adj[v];  // adjacency  list
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);
	
	cout<<"The bfs traversal is : ";
	bfs(adj,v);	
}