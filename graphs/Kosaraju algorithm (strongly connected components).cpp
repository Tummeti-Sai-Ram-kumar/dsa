#include<bits/stdc++.h>
using namespace std;

class Graph{
	int size;
	vector <int> *adj;

	public:
		Graph(int __size)
		{
			size=__size;
			adj=new vector <int> [size];
		}
		
		void addEdge(int u,int v)
		{
			adj[u].push_back(v);
		}
		
	    void Print_stack_using_dfs(int curr_node,vector <bool> &visited)
		{
			cout<<curr_node<<" ";
			visited[curr_node]=true;
			vector <int> temp=adj[curr_node];
			for(int i=0;i<temp.size();i++)
			{
				if(visited[temp[i]]==false)
				{
					Print_stack_using_dfs(temp[i],visited);
				}
			}
		}
				
		Graph transpose()
		{
			Graph gd(size);
			for(int i=0;i<size;i++)
			{
				vector <int> temp=adj[i];
				for(int j=0;j<temp.size();j++)
				{
					
					gd.adj[temp[j]].push_back(i);   // reverse fill the nodes into new Graph 
				}
			}
			return gd;
		}
		
		void fill_1(int i,vector <bool> &visited,stack <int> &s)
		{
			visited[i]=true;
			vector <int> temp=adj[i];
			
			for(int j=0;j<temp.size();j++)
		    {
		    	if(visited[temp[j]]==false)
		    	{
		    		fill_1(temp[j],visited,s);
				}
			}
			s.push(i);
		}
		
		
		
		void Kosaraju_algo()
		{
			stack <int> s;
			vector <bool> visited (size,false);
			
			// Get the sequence of nodes in decreasing time format (dfs topological)
			
			for(int i=0;i<size;i++)
			{
				if(visited[i]==false)
				{
					fill_1(i,visited,s);
				}
			}
			
			// reverse the dir of nodes , and strong components on reversing too remains strong wheras the rest is not strong 
			
			Graph gd  =  transpose();
			
			
			// now to dfs traversal int the stacked sequence 
			for(int i=0;i<size;i++)
			{
				visited[i]=false;
			}
			while(!s.empty())
			{
				int curr_node=s.top();
				s.pop();
				
				if(visited[curr_node]==false)
				{
					gd.Print_stack_using_dfs(curr_node,visited);
					cout<<endl;
				}
			}
		}
		
		
		
};

int main()
{
	int size;
	cout<<"Enter the number of vertices ; ";
	cin>>size;
	
	Graph g(size);
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4);
	
	cout<<"The strongly connected components are : ";
	g.Kosaraju_algo();
}