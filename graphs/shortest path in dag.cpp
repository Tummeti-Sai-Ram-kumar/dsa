#include<bits/stdc++.h>
using namespace std;

class adj_node{
	int w,v;
	public:
		adj_node(int __v,int __w)
	    {
		    v=__v;
		    w=__w;
    	}
    	int GetVertex()
    	{
    		return v;
		}
		int GetWeight()
		{
			return w;
		}
};   

class Graph{ 
    int size;
	vector <adj_node> *adj;
	public:
		Graph(int __size)
		{
			size=__size;
			adj=new vector <adj_node> [size];
		}
		
		void addEdge(int u,int v,int w)
		{
			adj_node node(v,w);
			adj[u].push_back(node);
		}
		
		void shortest_path(int src)
		{
			stack <int> s;
			vector <int> dist(size,INT_MAX);
			dist[src]=0;
			vector <bool> visited (size,false);
			for(int i=0;i<size;i++)
			{
				if(visited[i]==false)
				{
					TS(i,visited,s);
				}
			}
			
			while(!s.empty())
			{
				int curr_node=s.top();
				s.pop();
				vector <adj_node> temp=adj[curr_node];
				for(int i=0;i<temp.size();i++)
				{
					adj_node node=temp[i];
					dist[node.GetVertex()]=min(dist[node.GetVertex()],dist[curr_node]+node.GetWeight());
				}
			}
			
			for(int i=0;i<size;i++)
			{
				if(dist[i]==INT_MAX)
				cout<<"0"<<" ";
				else
				cout<<dist[i]<<" ";
			}
		}
		
		void TS(int __i,vector <bool> &visited,stack <int> &s)
		{
			visited[__i]=true;
			vector <adj_node> temp=adj[__i];
			for(int i=0;i<temp.size();i++)
			{
				adj_node node =temp[i];
				if(visited[node.GetVertex()]==false)
				{
					TS(node.GetVertex(),visited,s);
				}
			}
			s.push(__i);
		}
};

int main()
{
	int size;
	cout<<"Enter the number of nodes : ";
	cin>>size; 
	
	int src;
	cout<<"Enter the source node : ";
	cin>>src;
	
	Graph g(size);
	g.addEdge(0, 1, 2); 
	g.addEdge(0, 4, 1); 
	g.addEdge(1, 2, 3); 
	g.addEdge(4, 2, 2); 
	g.addEdge(4, 5, 4); 
	g.addEdge(2, 3, 6); 
	g.addEdge(5, 3, 1);
	
	g.shortest_path(src);
}