#include<iostream>
using namespace std;

int largestSum(int *arr , int n){
	int prefixsum[100] = {0};
	prefixsum[0] = arr[0];
	for(int i = 1; i<n; i++){
		prefixsum[i] = prefixsum[i-1]+arr[i];
	}
	// main logic
	int largestSum = 0;
	//run two loops
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			int subarraysum = i > 0 ? prefixsum[j]-prefixsum[i-1] : prefixsum[j];
			largestSum = max(largestSum , subarraysum);
		}
	}
	return largestSum;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(int);
	int ans = largestSum(arr,n);
	cout<<"largest sum of subarray is :"<<ans<<endl;
	return 0;
} 