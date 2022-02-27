//https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1/

//Approach 1

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        vector<int>sum(N+1 , 0);
        int ans = 0;
        for(int i = 1; i<=N; i++){
            sum[i] = sum[i-1]+Arr[i-1];
        }
        for(int i = 0; i<N; i++){
            for(int j = i+1; j<=N; j++){
                if(sum[j]-sum[i] == k){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//Approach 2

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int count = 0;
        for(int i = 0; i<N; i++){
            int sum = 0;
            for(int j = i; j<N; j++){
                sum = sum+Arr[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};

//Approach 3

int ThirdWay(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        hash_map[0] = 1;
        int sum = 0, ans = 0;
        
        for(int i = 0;i < nums.size(); ++i) {
            sum += nums[i];
            if(hash_map.find(sum - k) != hash_map.end()) {
                ans += hash_map[sum - k];
            }
            if(hash_map.find(sum) == hash_map.end()) {
                hash_map[sum] = 1;
            } else
                hash_map[sum]++;
        }
        
        return ans;
    }