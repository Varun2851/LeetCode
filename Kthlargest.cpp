class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //vector<int>ans;
        int temp;
        priority_queue<int>pq;
        
        for(int i =0; i<n; i++){
            pq.push(nums[i]);
        }
        
        while(k>0){
             temp = pq.top();
            //ans.push_back(temp);
            pq.pop();
            k--;
        }
        return temp;
    }
};