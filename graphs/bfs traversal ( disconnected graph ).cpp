#include<bits/stdc++.h>
using namespace std;

void bfs(vector <int> adj[],int i,vector <bool> &visited)
{
	queue <int> q;
	q.push(i);
	visited[i]=true;
	while(!q.empty())
	{
		int curr_node=q.front();
		q.pop();
		cout<<curr_node<<" ";
		vector <int> temp=adj[curr_node];
		for(int j=0;j<temp.size();j++)
		{
			if(visited[temp[j]]==false)
			{
				visited[temp[j]]=true;
				q.push(temp[j]);
			}
		}
	}
	cout<<endl;
}

void bfs_wrapper(vector <int> adj[],int v)
{
	vector <bool> visited={false};
	visited.resize(v);
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			bfs(adj,i,visited);
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
	cout<<"Enter number of nodes : ";
	cin>>v;
	
	vector <int> adj[v];
	
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);
	
	cout<<"BFS traversal is : ";
	bfs_wrapper(adj,v);
}