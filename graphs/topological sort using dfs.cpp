#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

void Topological_sort(vector <int> adj[],int i,vector <bool> &visited,stack <int> &s)
{
	visited[i]=true;
	vector <int> temp=adj[i];
	for(int j=0;j<temp.size();j++)
	{
		if(visited[temp[j]]==false)
		{
			Topological_sort(adj,temp[j],visited,s);
		}
	}
	s.push(i);
}

void Topological_sort_wrapper(vector <int> adj[],int v)
{
	vector <bool> visited (v,false);
	stack <int> s;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			Topological_sort(adj,i,visited,s);
		}
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main()
{
	int v;
	cout<<"Enter the number of nodes : ";
	cin>>v;
	vector <int> adj[v];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
    
    Topological_sort_wrapper(adj,v);
}