#include<iostream>
#include<vector>
using namespace std;
//Bottom Up Approach
int solve(vector<int>stones , int n){
	vector<int>dp(n+1,0);
	dp[1] = abs(stones[1]-stones[0]);

	for(int i = 2; i<n; i++){
		int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
		int op2 = abs(stones[i]-stones[i-2]) + dp[i-2];
		dp[i] = min(op1,op2);
	}

	return dp[n-1];

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int>stones{10,30,40,20};
	int n = stones.size();
	cout<<solve(stones,n)<<endl;
	return 0;
}
