//Minimize the maximum difference between the heights

// Input  : arr[] = {1, 15, 10}, k = 6
// Output :  Maximum difference is 5.
// Explanation : We change 1 to 7, 15 to 
// 9 and 10 to 4. Maximum difference is 5
// (between 4 and 9). We can't get a lower
// difference.

#include<bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {7,4,8,8,8,9};
	int k = 6;
	int n = 6;
	sort(arr,arr+n); //by sorting our smallest comes to front & largest gies to last
	int ans = arr[n-1] - arr[0];
	int tempmin = arr[0];
	int tempmax = arr[n-1];

	for(int i = 1; i<n; i++){
		if(arr[i]-k < 0){
			continue;
		}

		tempmin = min(arr[0]+k,arr[i]-k);
		tempmax = max(arr[n-1]-k,arr[i-1]+k);

		ans = min(ans , tempmax-tempmin);
	}

	cout<<ans<<" "<<endl;
	return 0;
}