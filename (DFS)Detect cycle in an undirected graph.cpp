time = O(n+m)
space = O(V)
bool dfs(vector<int> adj[],int v,int par, vector<int> &vis)
    {
        vis[v]=1;
        for(int i=0; i<adj[v].size();++i)
        {
            if(adj[v][i] == par)
                continue;            
            
            if(vis[adj[v][i]])
            {
                return true;
            }
            else if(dfs(adj,adj[v][i],v,vis) )
            {
                return true;
            }
        }
        return false;
        
    }
	bool isCycle(int v, vector<int>adj[])
	{
	    vector<int> vis(v);
	    bool ans = 0;
	    for(int i=0; i<v; ++i)
	    {
	        if(!vis[i] && dfs(adj,i,-1,vis))
	        {
	            return true;
	        }
	    }
	    return false;
	}
