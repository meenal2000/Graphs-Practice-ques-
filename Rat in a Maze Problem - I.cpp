time - O(4^(N^2))
space - O(4^(N^2))

void solve(vector<vector<int>> &m,int n, int i,int j,string s,vector<vector<int>> vis)
    {
        if(i<0 || i>=n || j<0 || j>=n )
            return;
        if(m[i][j]==0 || vis[i][j])
            return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        //string tmp="";
        solve(m,n,i+1,j,s+"D",vis);
        solve(m,n,i,j-1,s+"L",vis);
        solve(m,n,i,j+1,s+"R",vis);
        solve(m,n,i-1,j,s+"U",vis);
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
        vector<vector<int> > vis(n,vector<int>(n));
        solve(m,n,0,0,"",vis);
        //sort(ans.begin(),ans.end());
        return ans;
    }
