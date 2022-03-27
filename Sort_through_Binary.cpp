class Solution {
int countbits(int x){
    int cnt = 0;
    while(x){
        if(x%2){
            cnt++;
        }
        x =x/2;
        
    }
    return cnt;
}
 public:
    static bool comp(int a , int b){
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if(c1 == c2)
            return a < b;
        return c1 < c2;
    }
    vector<int> sortByBits(vector<int>& nums) {
        int n = nums.size();
    unordered_map<int , vector<int> > mp;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i = 0; i<n; i++){
        int val = countbits(nums[i]);
        mp[val].push_back(nums[i]);
        mx = max(mx,val);
        mn = min(mn,val);
    }
    int idx = 0;
    for(int i = mn; i<=mx; i++){
        if(mp.count(i)){
            for(auto X: mp[i]){
               nums[idx] = X;
               idx++;
            }
        }
    }
    sort(nums.begin(),nums.end(),comp);
    return nums;
    }
};