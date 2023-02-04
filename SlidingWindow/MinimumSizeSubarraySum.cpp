#include<bits/stdc++.h>
using namespace std;

int main(){

	int arr[] = {2,3,1,2,4,3};
	int target = 7;
	int n = sizeof(arr)/sizeof(int);
	int sum = 0;

	int i =0;
	int j =0;

	int minlength = INT_MAX;
	int ans = 0;

	while(j<n){
		sum += arr[j];

		if(sum<target){
			j++;
		}

		if(sum>=target){
			while(sum>=target){
				ans = j-i+1;
				if(ans<minlength){
					minlength = ans;
				}
				sum = sum-arr[i];
				i++;
			}
			j++;

		}
	}

	cout<<minlength<<" ";

	return 0;
}