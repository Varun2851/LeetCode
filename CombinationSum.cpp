#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>ans;
void solve(vector<int>&arr , int target , int sum , int i , int n){
	vector<int>temp;
	//base case
	if(sum == target){
		ans.push_back(temp);
		return;
	}

	if(sum > target || i >= n){
		return;
	}

	//recursive case
	//Include the ith char
	if(sum+arr[i] <= target){
		temp.push_back(arr[i]);
		solve(arr, target , sum+arr[i] , i ,  n);
		temp.pop_back();
	}
	//Exclude the ith char
	solve(arr,target, sum , i+1, n);
}

vector<vector<int>>combinationSum(vector<int>&arr,int target , int n){
	solve(arr,target , 0 , 0 , n);
	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int>arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int target;
	cin>>target;

	vector<vector<int>>output = combinationSum(arr, target , n);

	int rows = output.size();
	int col = output[0].size();

	for(int i = 0; i<rows; i++){
		for(int j = 0; j<col; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;

}