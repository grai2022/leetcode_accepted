/*
https://leetcode.com/problems/rotting-oranges/
*/

class Solution {
private:
    int rows, cols;
    vector<vector<int>> direction{{0,1},{1,0},{0,-1},{-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        
        rows = grid.size();
        cols = grid[0].size();
        int count =0;
        
        for(int r = 0 ; r<rows;r++)
        {
            for(int c =0 ; c < cols;c++){
                if(grid[r][c] == 2){
                    q.push({r,c});
                    grid[r][c]=0;
                }
                if(grid[r][c] == 1){
                    count++;
                }
            }
        }
        
        if(count <=0){
            return 0;
        }
        int output =bfs(grid,q);
        for(int r = 0 ; r<rows;r++)
        {
            for(int c =0 ; c < cols;c++){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }
        
        return output;
    }
    
    int bfs(vector<vector<int>>& grid ,queue<pair<int,int>>& q){
        int r,c , out =-1;
        while(!q.empty()){
            
           
            
            int qsize = q.size();
            for(int j = 0; j < qsize; j++){
                
                
                for(vector<int> dir : direction){
                r = q.front().first ;
                c = q.front().second;
                r = r+dir[0];
                c = c+dir[1];
                if(r <0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)                 {
                    
                } else{
                    q.push({r,c});
                    grid[r][c] =0;
                }
             }
            q.pop();
            }
             out++;
            
        }
        
        return out;
    }
};
