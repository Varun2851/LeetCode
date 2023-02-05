class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int>candies(n,1); //give 1 candy to all children
        //traverse from left
        for(int i  = 1; i<n; i++){
            if(nums[i-1] < nums[i] and candies[i-1] <= candies[i]){
                candies[i] = candies[i-1]+1;
            }
        }
        //traverse from right
        for(int i = n-2; i>=0; i--){
            if(nums[i+1]<nums[i] and candies[i+1]<=candies[i]){
                candies[i] = candies[i+1]+1;
            }
        }

        int total = 0;
        for(int i = 0; i<n; i++){
            total += candies[i];
        }
        return total;
    }
};