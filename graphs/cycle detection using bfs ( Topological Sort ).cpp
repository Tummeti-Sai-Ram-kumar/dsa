#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

bool cycle_using_TS(vector <int> adj[],int v)
{
	vector <int> indegree(v,0);
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
	int c=0;
	while(!q.empty())
	{
		int curr_node=q.front();
		q.pop();
		vector <int> temp=adj[curr_node];
		for(int i=0;i<temp.size();i++)
		{
			indegree[temp[i]]--;
			if(indegree[temp[i]]==0)
		    q.push(temp[i]);
		}
		c++;
	}
	if(c!=v)  // if number of nodes == c , then there is no cycle as it traverses threough all the nodes 
	return true;  // when there is a cycle then while loop structs without traversing all the nodes bcoz indegree of a particular node may not be 0
	else
	return false;
	
}

int main()
{
	int v;
	cout<<"Enter the number of vertices : ";
	cin>>v;
	vector <int> adj[v];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);
    
    
	if(cycle_using_TS(adj,v))
	cout<<"Found cycle";
	else
	cout<<"Cycle not found";
}