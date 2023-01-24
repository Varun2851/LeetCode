class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxpq; //max heap
        int m = INT_MAX, diff = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]%2 != 0) nums[i]= 2*nums[i];
            m = min(m, nums[i]);
            maxpq.push(nums[i]);
        }
        
        while(maxpq.top()%2 == 0) {
            int mx = maxpq.top();
            maxpq.pop();
            diff = min(diff, mx - m);
            m = min(m, mx/2);
            maxpq.push(mx/2);
        }
    
        return min(diff, maxpq.top() - m);
    }
};