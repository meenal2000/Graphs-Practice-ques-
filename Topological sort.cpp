//Through BFS
// time - O(n+m)
// space - O(n) + O(n)
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> topo(V);
	   vector<int> indeg(V);
	   for(int i=0; i<V; ++i)
	   {
	       for(int j=0; j<adj[i].size();++j)
	       {
	           indeg[adj[i][j]]++;
	       }
	   }
	   queue<int> q;
	   for(int i=0; i<V; ++i)
	   {
	       if(indeg[i]==0)
	            q.push(i);
	   }
	   int ind=0;
	   while(!q.empty())
	   {
	       int v = q.front();
	       topo[ind++] = v;
	       q.pop();
	       for(int j=0; j<adj[v].size();++j)
	       {
	           indeg[adj[v][j]]--;
	           if(indeg[adj[v][j]]==0)
	           {
	               q.push(adj[v][j]);
	           }
	       }
	   }
	   
	   return topo;
	}

//Through DFS
space - o(n)+O(n)
  time - O(n+m)
void solve(int V,vector<int> &vis,vector<int> adj[],vector<int> &ans)
	{
	    vis[V]=1;
	    for(int i=0; i<adj[V].size(); ++i)
	    {
	       if(!vis[adj[V][i]])
	       {
	           solve(adj[V][i],vis,adj,ans);
	       }
	    }
	    ans.push_back(V);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> ans(V);
	   vector<int> vis(V);
	   for(int i=0; i<V; ++i)
	   {
	       if(!vis[i])
	       {
	           solve(i,vis,adj,ans);
	       }
	   }
	   reverse(ans.begin(),ans.end());
	   return ans;
	}
