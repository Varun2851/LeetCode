//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        if(target < nums[0]){
            return 0;
        }
        if(target > nums[n-1]){
            return n;
        }
        
        while(s<=e){
        	int mid = (s+e)/2;
        	if(target == nums[mid]){
        		return  mid;
        	}
        	else if(target < nums[mid]){
        		e = mid-1;
        	}
        	else{
        		s = mid+1;
        	}
        }
        if(s>e){
        	for(int i = 1; i<n; i++){
        		if(nums[i-1] < target and nums[i] > target){
        			return i;
        		}
        	}
        }
       
        return -1;
    }
};