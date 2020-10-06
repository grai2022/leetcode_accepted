/*https://leetcode.com/problems/kth-largest-element-in-an-array*/

using maxheap = priority_queue<int>;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // set<int> unique(nums.begin(), nums.end());
        maxheap pq(nums.begin(), nums.end());
        while(k>1){
            pq.pop();
            k--;
        } 
        return pq.top();
    }
};
