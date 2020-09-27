/*
Problem -
https://leetcode.com/problems/next-permutation/submissions/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int length = nums.size() -1;
        int swapIndex = -1;
        for(int i = length ; i>0;i--){
            if(nums[i] > nums[i-1]){
                swapIndex = i-1;
                break;
            }
        }
        if(swapIndex != -1){
            int temp = nums[swapIndex];
            for(int i = length ; i >=0 ; i--){
                if(nums[i]> temp){
                    int t = nums[i];
                    nums[i] = nums[swapIndex];
                    nums[swapIndex] = t;
                    break;
                }
            }
            swap(nums, swapIndex+1, length);
        }else{
            swap(nums, 0, length);
        }
        
        return;
                                      
        
        
    }
    
    void swap(vector<int>& nums , int startIndex, int endIndex){
        while(startIndex < endIndex){
                int temp = nums[endIndex];
                nums[endIndex] = nums[startIndex];
                nums[startIndex] = temp;
            startIndex++;
            endIndex--;
            }
        return;
        
    }
};
