
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int> > pq;
        long long ans = 1 , mod = 1e9+7;
        for(auto x : nums)pq.push(x);
        while(k--)
        {
            int a = pq.top();
            pq.pop();
            pq.push(a+1);
        }
        while(!pq.empty())
        {
            ans  = (ans*pq.top())%mod;
            pq.pop();
        }
        return (int)ans;
    }
};