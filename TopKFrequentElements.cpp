class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq; //maxheap
        
    //    for(int i = 0; i<n; i++){
    //        pq.push({mp[nums[i]]++,nums[i]});
    //    }

       for(auto X : mp){
           pq.push({X.second,X.first});
       }
        
        while(k>0){
            int a = pq.top().second;
            ans.push_back(a);
            pq.pop();
            k--;
        }
        return ans;
    }
};