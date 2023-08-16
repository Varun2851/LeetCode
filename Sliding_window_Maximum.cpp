class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q(k); // make a deque of size k
        int i; // Global varibale 
        int n = nums.size();
        vector<int>ans;
        
        for(i = 0; i<k; i++){
            while(!q.empty() and nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(i = k; i<n; i++){
            ans.push_back(nums[q.front()]);
            while(!q.empty() and q.front() <= i-k){
                q.pop_front();
            }
             while(!q.empty() and nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};