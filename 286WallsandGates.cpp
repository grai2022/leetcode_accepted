/*
https://leetcode.com/problems/walls-and-gates/
*/

class Solution {
private : 
    int cols;
    int rows;
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        rows = rooms.size();
        if(rows == 0) return;
        cols = rooms[0].size();
        if(cols == 0) return;
        queue<pair <int , int>> q;
        for(int r = 0 ; r < rows ; r++ ){
            for(int c = 0; c < cols ; c++){
                if(rooms[r][c] == 0){
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
                 int r = q.front().first;
                 int c = q.front().second;
            
                if(isvalid(r-1 ,c, rooms)){
                    rooms[r-1][c]  = rooms[r][c] +1;
                    q.push({r-1 ,c});
                    
                }
                if(isvalid(r+1 ,c, rooms)){
                    q.push({r+1 ,c});
                    rooms[r+1][c]  = rooms[r][c] +1;
                     
                }
                if(isvalid(r ,c-1, rooms)){
                    q.push({r ,c-1});
                    rooms[r][c-1] = rooms[r][c]+1;
                }
                if(isvalid(r ,c+1, rooms)){
                    q.push({r ,c+1});
                    rooms[r][c+1]  = rooms[r][c] +1 ;
                }
                
            q.pop();
            
        }
        
        return;
    }
    bool isvalid(int r, int c, vector<vector<int>>& rooms){
        
        bool ot =  r < rows && c < cols && r >=0 && c >= 0  ;
        if(ot) return rooms[r][c] == INT_MAX;
        return false;
    }
        
    };
    
