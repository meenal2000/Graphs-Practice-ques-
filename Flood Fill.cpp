time - O(m*n)
space - O(n*m)
void solve(vector<vector<int>>&image, int sr, int sc, int r, int c, int newColor, int oldColor)
    {
        
        if(sr < 0 || sr >= r || sc < 0 || sc >= c || image)
            return;
        if(image[sr][sc] == oldColor)
        {
            //cout << sr << " " << sc << " " << r << " " << c << endl;
            image[sr][sc] = newColor;
            solve(image,sr+1,sc,r,c,newColor,oldColor);
            solve(image,sr-1,sc,r,c,newColor,oldColor);
            solve(image,sr,sc+1,r,c,newColor,oldColor);
            solve(image,sr,sc-1,r,c,newColor,oldColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if (image[sr][sc] == newColor) 
            return image;
        int rows = image.size();
        int cols = image[0].size();
        solve(image,sr,sc,rows,cols,newColor,image[sr][sc]);
        return image;
    }
