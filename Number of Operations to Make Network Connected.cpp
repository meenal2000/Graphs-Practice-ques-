time - O(n+m)
  space - O(edges)/O(height)

void dfs(vector<int> &vis,int v,vector<vector<int>>& connections)
    {
        vis[v]=1;
        for(int i=0; i<connections[v].size();++i)
        {
            if(!vis[connections[v][i]])
            {
                dfs(vis,connections[v][i],connections);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        vector<vector<int> > mat(n);
        for(int i=0; i<connections.size();++i)
        {
            mat[connections[i][0]].push_back(connections[i][1]);
            mat[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n);
        int num_connected_components=0;
        for(int i=0; i<n; ++i)
        {
            if(!vis[i])
            {
                dfs(vis,i,mat);
                ++num_connected_components;
            }
        }
        return num_connected_components-1;
    }
