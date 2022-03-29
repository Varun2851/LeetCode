//https://leetcode.com/problems/permutations/
class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<int> swap(vector<int> &nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return nums;
    }
    
    void perm(vector<int> &nums, int l, int r){
        if(l==r){
            result.push_back(nums);
            return;
        }
        for(int i = l; i <= r; i++){
            nums = swap(nums, l, i);
            perm(nums, l+1, r);
            nums = swap(nums, l, i);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0, nums.size()-1);
        return result;
    } 
};