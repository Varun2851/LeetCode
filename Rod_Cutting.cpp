//Rod-Cutting
// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. 
// Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
// For example, if the length of the rod is 8 and the values of different pieces are given as the following, 
// then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 
//Sample Input = 
//Lenght : 1   2   3   4   5   6   7   8 
//Price :  1   5   8   9  10  17  17  20

#include<iostream>
#include<vector>
using namespace std;

int max_profit(vector<int>&prices, int n){
	//base case

	if(n <= 0){
		return 0;
	}

	//recursive case
	int ans = INT_MIN;
	for(int i = 0; i<n; i++){
		int cut = i+1;
		int current_ans = prices[i] + max_profit(prices,n-cut);
		ans = max(ans,current_ans);
	}
	return ans;
}

/////////////////////////////////////////Bottom Up Dp ////////////////////////////////////

int BottomUp(vector<int>&prices , int n){

	vector<int>dp(n+1);
	dp[0] = 0;
	for(int len = 1; len<=n; len++){
		int ans = INT_MIN;
		for(int i = 0; i<len; i++){
			int cut = i+1;
          	int current_ans = prices[i] + dp[len-cut];
          	ans = max(ans,current_ans);
		}
		dp[len] = ans;
	}
	for(int i = 0; i<n+1; i++){
		cout<<dp[i]<<" ";
	}
	return dp[n];
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int>prices{1,5,8,9,10,17,17,20};
	vector<int>length{1,2,3,4,5,6,7,8};
	int n = prices.size();

	cout<<max_profit(prices,n);
	cout<<endl;
	cout<<BottomUp(prices,n);

	return 0;

}