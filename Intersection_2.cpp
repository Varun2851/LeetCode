// Approach 1 :- Using sorting 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        //Using sorting
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        int i  = 0;
        int j =  0;
        
        while(i < n and j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};

// 2nd Approach using Hashmap

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mp;
        vector<int>ans;
        
        for(auto x :nums1){
            mp[x]++;
        }
        
        for(auto x : nums2){
            if(mp[x] > 0){
                ans.push_back(x);
            }
            mp[x]--;
        }
        return ans;
    }
};

