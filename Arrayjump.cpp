//ArrayJump.cpp
#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&arr,vector<int>&dp,int n, int i){
	//base case
	if(i == n-1){
		return 0;
	}
	if(i >= n){
		return INT_MAX;
	}

	//Recursive case
	int maxstep = arr[i];
	int step = INT_MAX;

	for(int jump = 1; jump<=maxstep; jump++){
		int next_jump = i+jump;
		int Sub_problem = solve(arr,dp,n,next_jump);
		if(Sub_problem != INT_MAX){
			step = min(step,Sub_problem+1);
		}
	}
	return step;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int>arr{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
	int n = arr.size();

	vector<int>dp(n+1,0);

	cout<<solve(arr,dp,n,0);

	return 0;
}
