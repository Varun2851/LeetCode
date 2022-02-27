// We can solve it using brute force and dfs both . Like striver vhaiya says "Pahle brute force dedo fir optimal do".
// BRUTE FORCE
// First take the row and col thn traverse through that .
// you have to check it is 1 or 0 . if 1 then take that it has all 4 sides (ans =4) then check for its 4 directions just if up do (i-1), 
// if down do (i+1) ,same with left right using j . if any of the side have 1 thn decrese ans by 1

////////////////////////////////////////////Approach-1///////////////////////////////////////////////////////

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=4;
                    if(i-1>=0 && grid[i-1][j]==1)// check for the upward
                    {
                        ans--;
                    }
                    if(i+1<row && grid[i+1][j]==1)//check for the downward
                    {
                        ans--;
                    }
                    if(j-1>=0 && grid[i][j-1]==1)//check for the left
                    {
                        ans--;
                    }
                    if(j+1<col && grid[i][j+1]==1)// check for the right 
                    {
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};


/////////////////////////////////////////////////////OptimisedApproach////////////////////////////////////////////////////

class Solution {
public:
    int dfs(vector<vector<int>> & grid,int i, int j)
    {
        // if we are out of the grid, or we have already been at this cell, or the value is zero return,
        if( i < 0 || j < 0 || i > grid.size()-1 
       || j > grid[0].size()-1 || !grid[i][j] || grid[i][j] == -1) return 0 ; 
       
        grid[i][j] = -1; 
        int ans = 4; 
        
        if(i < grid.size() - 1 && grid[i+1][j]) // check for the upward
            ans--; 
        if(j < grid[0].size() -1 && grid[i][j+1])// check for the rightward
            ans--; 
        
        if(j > 0 && grid[i][j-1])// check for the leftward
            ans--; 
        if(i > 0 && grid[i-1][j])// check for the downward
            ans--;
        
        // call there dfs up,down ,left ,right.
        return ans + (dfs(grid, i + 1 ,j) + dfs(grid,i-1,j) + dfs(grid,i,j-1) + dfs(grid,i,j+1)); 
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0 , row = grid.size(), col = grid[0].size();    
        for(int i = 0 ; i < row ; i++)
        {
           for(int j = 0 ; j < col ; j++)
           {
               if( grid[i][j])
               {
                 return dfs(grid,i,j);  
               }
           } 
        }
        return ans;
    }
};