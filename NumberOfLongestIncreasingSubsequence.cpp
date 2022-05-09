class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] +1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j]+1){
                        cnt[i] = cnt[i]+cnt[j];
                    }
                }
            }
        }
        int LIS = 0;
        for(int i = 0; i<n; i++){
            LIS = max(LIS,dp[i]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(dp[i] == LIS){
                ans += cnt[i];
            }
        }
          return ans;  
    }
};