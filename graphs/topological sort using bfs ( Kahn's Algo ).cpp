#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

void topological_sort(vector <int> adj[],int v)
{
	vector <int> indegree (v,0);
	for(int i=0;i<v;i++)
	{
		vector <int> temp=adj[i];
		for(int j=0;j<temp.size();j++)
		{
			indegree[temp[j]]++;
		}
	}
	
	queue <int> q;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0)
		q.push(i);
	}
	
	while(!q.empty())
	{
		int  curr_node = q.front();
		cout<<curr_node<<" ";
		q.pop();
		vector <int> temp=adj[curr_node];
		for(int i=0;i<temp.size();i++)
		{
			indegree[temp[i]]--;
			if(indegree[temp[i]]==0)
			q.push(temp[i]);
		}
	}
}

int main()
{
	int v;
	cout<<"Enter the number of vertices : ";
	cin>>v;
	vector <int> adj[v];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3); 
    
    topological_sort(adj,v);
}