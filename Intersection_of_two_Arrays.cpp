// General Idea:
// The general idea is to first sort both arrays in a non-decreasing order. Then, create one pointer for each array. If the array values at the current pointers are equal, we add it to the result. Otherwise, we increment the array pointer that is pointing to the lower value.

// We also need to consider dupliates. Since the array is sorted, if two elements are the same, they will be adjacent. Therefore, we always check if the previous element of any array equals the current element.

// Example Walkthrough:
// Consider the following example:
// nums1 = [1,2,2,1], nums2 = [2,3,4]. After sorting, we have nums1 = [1,1,2,2], nums2 = [2,3,4]. Initialize, i = 0, j = 0 where i will point to nums1 and j will point to nums2.

// First i = 0, j = 0 and nums1[i] = 1 and nums2[j] = 2. Since 1 < 2, we increment i.
// Then, i = 1, j = 0 and nums[i] = 1 and nums2[j] = 2. However, we realize that nums1[i] == nums1[i-1], which means there is a dupliate value in nums1 and so we increment i.
// Then, i = 2, j = 0 and nums[i] = 2 and nums2[j] = 2. Since nums[i] == nums[j], we can add 2 to the result and increment i and j.
// Then, i = 3, j = 1 and nums[i] = 2 and nums2[j] = 2. Since nums[i - 1] == nums[i], we realize there is a duplicate and increment i.
// Then, i = 4, j = 1 and so the loop terminates.

// The final result is {2}.

// Analysis:

// Time complexity is O(n log n) where n is the size of the largest array -- n = max(nums1.size(), nums2.size()). We sort which takes O(n log n), and then we traverse both arrays and increment at least once per iteration. Therefore, at most we will go through 2n iterations and so the final time complexity is O(n log n + 2n) = O(n log n).
// Space complexity is O(1) since we don't use extra space. The space required for the result is not counted in the space complexity.
Code:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end()); // sort nums1 (non-decreasing order)
        sort(nums2.begin(), nums2.end()); // sort nums2 (non-decreasing order)
        
        int i = 0, j = 0;
        vector<int> res;
        
        while(i < nums1.size() && j < nums2.size()){
            if(i > 0 && nums1[i - 1] == nums1[i]){
                i++; // dealing with duplicates in nums1
            }
            else if(j > 0 && nums2[j - 1] == nums2[j]){
                j++; // dealing with duplicates in nums2
            }
            else if(nums1[i] < nums2[j]){
                i++; // if nums1 < nums2, we increment nums1
            }
            else if(nums1[i] > nums2[j]){
                j++; // if nums1 > nums2, we increment nums2
            }
            else{
                res.push_back(nums1[i]); // if none of the above, nums1==nums2 so we add to result
                i++; j++;
            }
        }
        
        return res;
        
    }
};

//////////////////////////////////////2nd Approach//////////////////////////////////////////

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr[10001] = {0};
        vector<int>ans;
        int n =  nums1.size();
        int m = nums2.size();
        // first iterate over 1st array
        
        for(int i = 0; i<n; i++){
            if(arr[nums1[i]] == 0){
                arr[nums1[i]]++;
            }
        }
        
        for(int i = 0; i<m; i++){
            if(arr[nums2[i]] == 1){
                arr[nums2[i]]++;
            }
        }
        
        for(int i = 0; i<1001; i++){
            if(arr[i] > 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};