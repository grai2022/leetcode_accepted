/*
https://leetcode.com/problems/top-k-frequent-words/
*/

struct compare {
    bool operator()(const pair<string, int>a, const pair<string, int>b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
using heap = priority_queue<pair<string, int>, vector<pair<string, int>>, compare>;
using hashmap = unordered_map<string, int>;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(k<=0) return {};
        hashmap umap;
        for(string word : words) umap[word]++;
        heap pq(umap.begin(),umap.end());
        vector<string> output;
        while(k && !pq.empty()){
            output.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return output;
    }
};
