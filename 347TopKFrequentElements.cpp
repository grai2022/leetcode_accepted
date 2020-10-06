using intpair = pair<int, int>;
using hashmap = unordered_map<int,int>;

struct comp{
       bool operator()(const intpair a, const intpair b){
        return a.second< b.second;
    }
    };

using maxheap = priority_queue<intpair,vector<intpair>, comp>;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        hashmap umap;
        vector<int> output;
        for(int num :nums) umap[num]++;
        maxheap freq(umap.begin(),umap.end()); 
        while(k--){
            output.push_back(freq.top().first);
            freq.pop();
        }
        return output;
    }
};
