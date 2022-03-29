//https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> result;
    
    void subs(vector<int> &nums, int curr, vector<int> &res){
        result.push_back(res);
        for(int i = curr; i < nums.size(); i++){
            if(i!=curr && nums[i]==nums[i-1]){
                continue;
            }
            res.push_back(nums[i]);
            subs(nums, i+1, res);
            res.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0){
            return result;
        }
        vector<int> res;
        sort(nums.begin(), nums.end());
        subs(nums, 0, res);
        return result;
    }
};