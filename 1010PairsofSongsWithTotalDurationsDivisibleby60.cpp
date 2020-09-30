/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> umap;
        int size = time.size();
        int output = 0;
        for(int i = 0;i < size;i++ ){
            int t = time[i]%60;
            if(umap.find(60-t == 60 ? 0 :60-t) != umap.end()){
                output += umap[60-t == 60 ? 0:60-t];
            }
            umap[t] += 1;
        }
        return output;
    }
};
