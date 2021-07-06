time - O(n*m)
space - O(n*m)

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int i = KnightPos[0]-1;
	    int j = KnightPos[1]-1;
	    TargetPos[0]-=1;
	    TargetPos[1]-=1;
	    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
	    vector<vector<int> > dist(N,vector<int>(N,0));
	    vector<vector<int> > vis(N,vector<int>(N,0));
	    queue<pair<int,int> > q;
	    q.push({i,j});
	    vis[i][j]=1;
	    if(i==TargetPos[0] && j==TargetPos[1])
	        return 0;
	    while(!q.empty())
	    {
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(int i=0; i<8; ++i)
	        {
              int curr_x = x+dx[i];
              int curr_y = y+dy[i];
	            if(curr_x>=0 && curr_x<N && >=0 && curr_y<N && !vis[curr_x][curr_y])
	            {
	                dist[curr_x][curr_y] = dist[x][y]+1;
	                vis[curr_x][curr_y] = 1;
	                if(curr_x==TargetPos[0] && curr_y==TargetPos[1])
	                    break;
	                q.push({curr_x,curr_y});
	            }
	        }
	    }
	    return dist[TargetPos[0]][TargetPos[1]];
	}
