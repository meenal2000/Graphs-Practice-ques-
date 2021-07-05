vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    queue<int> q;
	    q.push(0);
	    vector<int> res;
	    map<int,int> mp;
	    mp[0] = 1;
	    while(!q.empty())
	    {
	        int u = q.front();
	        res.push_back(u);
	        q.pop();
	        for(int i=0; i<adj[u].size(); ++i)
	        {
	            if(mp[adj[u][i]]==0)
	            {
	                q.push(adj[u][i]);
	                mp[adj[u][i]]++;
	            }
	        }
	    }
	    return res;
	}

time - O(n+m)
space - O(v)
