//Largest subarray sum which is divisible by k

#include<iostream>
using namespace std;

int solve(int *arr , int n, int k){
	int currentsum = 0;
	int largestsum = 0;

	for(int i = 0; i<n; i++){
		currentsum = currentsum+arr[i];
		if(currentsum < 0){
			currentsum = 0;
		}
		if(currentsum%k == 0){
			largestsum = max(largestsum,currentsum);
		}
	}
	return largestsum;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {1,2,3,9};
	int k = 3;
	int n = sizeof(arr)/sizeof(int);

	int ans = solve(arr , n , k);

	cout<<ans<<endl;
	return 0;
}