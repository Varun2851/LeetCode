//https://leetcode.com/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int previousDiff = nums[1]-nums[0];
        int currentdiff;
        int count = 2;

        if(n<2){
        	return n;
        }

        for(int i = 2; i<n; i++){
        	currentdiff = nums[i]-nums[i-1];

        	if((previousDiff > 0 and currentdiff <= 0) or (previousDiff < 0 and currentdiff => 0)){
        		count++;
        		previousDiff = currentdiff;
        	}
        }
        return count;

    }
};