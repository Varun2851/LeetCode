#include<iostream>
using namespace std;

int largestSum(int *arr , int n , int k){
	int prefixsum[100] = {0};
	prefixsum[0] = arr[0];
	int cnt = 0;
	for(int i = 1; i<n; i++){
		prefixsum[i] = prefixsum[i-1]+arr[i];
	}
	// main logic
	//run two loops
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			int subarraysum = i > 0 ? prefixsum[j]-prefixsum[i-1] : prefixsum[j];
			if(subarraysum%k == 0){
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {5};
	int n = sizeof(arr)/sizeof(int);
	int k = 9;
	int ans = largestSum(arr,n, k);
	cout<<"total no of subarraysum which is devisible by k :"<<ans<<endl;
	return 0;
} 