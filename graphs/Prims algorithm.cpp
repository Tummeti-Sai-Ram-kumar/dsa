#include<bits/stdc++.h>
using namespace std;


class Graph{
	int size;
	vector <pair<int,int>> *adj;
	public:
		Graph(int __size)
		{
			size = __size;
			adj = new vector <pair<int,int>> [size];
		}
		void addEdge(int u,int v,int w)
		{
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back({u,w});
		}
		int res=0;
		int Prim(int src)
		{
			priority_queue <pair<int,int>,vector <pair<int,int>> ,greater<pair<int,int>>> pq;
			vector <int> key(size,INT_MAX);
			vector <bool> visited(size,false);
			key[src]=0;
			pq.push({key[src],src});
			
			while(!pq.empty())
			{
				pair <int,int> curr_node = pq.top();
				pq.pop();
				if(visited[curr_node.second]==true) 
				continue;
				visited[curr_node.second]=true;
				cout<<curr_node.first<<" ";
				res=res+(curr_node.first);
				
				vector <pair<int,int>> temp=adj[curr_node.second];
				
				for(int i=0;i<temp.size();i++)
				{
					pair <int,int> p=temp[i];
					if(visited[p.first]==false)
					{
					    key[p.first]=min(p.second,key[p.first]);
					    pq.push({key[p.first],p.first});	
					}
				}
			}
			return res;
		}
};

int main()
{
	int size;
	cout<<"Enter the number of nodes : ";
	cin>>size; 
	
	int src=0;
	
	Graph g(size);
	
	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    cout<<g.Prim(src);
    
}