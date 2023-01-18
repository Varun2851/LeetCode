class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, 
        maxSum = INT_MIN, 
        curMax = 0, 
        minSum = INT_MAX, 
        curMin = 0;
    for (int it : nums) {
        //basic kadane's algo for min and max subarray
        totalSum += it;
        curMax += it;
        curMin += it;
        // for max subarray
        maxSum = max(maxSum, curMax);
        if(curMax < 0)
            curMax = 0;
        // for min subarray
        minSum = min(minSum, curMin);
        if(curMin > 0)
            curMin = 0;
        
    }
    //if corner case, return maxSum else max(maxSum, totalsum - minSum)
    return (totalSum == minSum) ? maxSum : max(maxSum, totalSum - minSum);
    }
};
