/*
*/

class Solution {
private:
    vector<vector<int>> direction;
    
    int rows, cols;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        direction.push_back({1,0});
        direction.push_back({0,1});
        direction.push_back({-1,0});
        direction.push_back({0,-1});
        rows = grid.size();
        int output =0;
        if(rows < 1) return 0;
        cols = grid[0].size();
        
        for(int r = 0 ; r < rows ; r ++){
            for(int c = 0 ; c < cols ; c++){
                if(grid[r][c] == '1'){
                    bfs(grid,r,c);
                    output++;
                }
            }
        }
        return output;
        
    }
    
    void bfs(vector<vector<char>>& grid , int r,int c){
        queue<pair<int,int>> q;
        int row = r, col=c;
        q.push({row,col});
        grid[row][col] ='0';
        while(!q.empty()){
            for(vector<int>dir : direction){
            row = q.front().first + dir[0];
            col = q.front().second + dir[1];
                
            if(row < 0 || col < 0 || row >= rows || col >= cols){
                continue;
            }else if(grid[row][col] == '1'){
                // cout<<"row "<<row<<"col "<< col<<grid[row][col]<<endl;
                q.push({row,col});
                grid[row][col] = '0';
                // cout<<"grid[row][col] "<<grid[row][col]<<endl;
            } else{
                
            }
        }
            q.pop();
        }
        return;
    }
};
