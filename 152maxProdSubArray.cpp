/*
https://leetcode.com/problems/maximum-product-subarray
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProdSoFar = nums[0];
        int maxProdCurr = nums[0];
        int minProdCurr =  nums[0];
        int length = nums.size()-1;
        for(int i = 1 ; i <= length; i++){
            int prevProdMax = maxProdCurr;//To check if min could go further min;
            maxProdCurr = max(nums[i], max(nums[i]*maxProdCurr , nums[i]*minProdCurr));
            minProdCurr = min(nums[i], min(nums[i]*minProdCurr, prevProdMax*nums[i]));
            maxProdSoFar = max(maxProdSoFar,maxProdCurr);
        }
        return maxProdSoFar;
        
    }
};
