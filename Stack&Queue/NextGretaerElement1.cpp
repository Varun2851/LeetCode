
#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int>&nums1,vector<int>&nums2,int n, int m){
	vector<int>ans;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(nums1[i] == nums2[j]){
				if(j == m-1){
					ans.push_back(-1);
				}
				for(int k = j+1; k<m; k++){
					if(nums2[k]>nums2[j]){
						ans.push_back(nums2[k]);
						break;
					}
					else{
						ans.push_back(-1);
					}
				}
			}
		}
	}

	return ans;
}

int main(){

	vector<int>nums1 = {2,4};
	vector<int>nums2 = {1,2,3,4};
	int n = nums1.size();
	int m = nums2.size();

	vector<int>result = solve(nums1,nums2,n,m);

	for(int i = 0; i<result.size(); i++){
		cout<<result[i];
	}

	return 0;
}
