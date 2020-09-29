/*
https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        
        int size = T.size();
        for(int i = 0; i<size; i++){
            if(s.empty()){
                // vector<int> a={T[i], i};
                s.push(i);
            }else{
                while(!s.empty() && T[i] > T[s.top()]){
                    // cout<<s.top()<<"pppp"<< T[s.top()]<<"  "<<T[i]<<endl;
                    T[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            T[s.top()] = 0;
            s.pop();
        }
        return T;
        
    }
};
