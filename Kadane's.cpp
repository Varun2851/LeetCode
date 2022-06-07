#include<iostream>
using namespace std;

int kadane(int *arr , int n){
	int currentsum = 0; //INT_MIN
	int largestsum = 0; //INT_MIN

	for(int i = 0; i<n; i++){
		currentsum = currentsum+arr[i];

		if(currentsum < 0){
			currentsum = 0;
		}
		largestsum = max(largestsum,currentsum);
	}
	return largestsum;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(int);

	int ans = kadane(arr , n);

	cout<<"Largest sum of subarray is:"<<ans<<endl;
	return 0;
}