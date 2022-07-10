//https://leetcode.com/problems/minimum-absolute-difference/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    	int n = arr.size();
    	sort(arr.begin(),arr.end());
    	vector<vector<int>> ans;// to store the pair
        //1.First traverse the whole array to find the minimum diff
        int minDiff = INT_MAX;

        for(int i = 0; i<n-1; i++){
        	minDiff = min(mindiff, arr[i+1]-arr[i]);
        }

        //2.Now traverse the array to find pair which have minDiff

        for(int i = 0; i<n-1; i++){
        	if(arr[i+1]-arr[i] == mindiff){
        		ans.push_back({arr[i+1],arr[i]});
        	}
        }
        return ans;
    }
};