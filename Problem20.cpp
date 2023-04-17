#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n){
	unordered_map<int,int>mp;

	for(int i = 0; i<n; i++){
		mp[arr[i]]++;
	}

	int maxFReq = INT_MIN;

	int element = INT_MAX;

	for(auto X:mp){
		if(X.second>=maxFReq and X.first < element){
			element = X.second;
		}
	}
	return element;
}

int main(){

	int arr[] = {1,1,3,4,5,3,3,5,2,2,2};
	int n = sizeof(arr)/sizeof(int);

	cout<<solve(arr,n);
	return 0;
}