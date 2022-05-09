// Given an unsorted array of integers nums, 
// return the length of the longest continuous increasing subsequence (i.e. subarray). 
// The subsequence must be strictly increasing.

// Input: nums = [1,3,5,4,7]
// Output: 3

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int anchor = 0;
        int ans = 0;
        
        for( int i = 0; i<n; i++){
            if(  i> 0 and nums[i-1] >= nums[i])
                anchor = i;
            ans = max(ans , i-anchor+1);
        }
        
        return ans;
    }
};