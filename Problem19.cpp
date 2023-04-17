#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n, int k){
	//priority_queue<int>pq;
	priority_queue<int,vector<int>,greater<int>>pq;

	for(int i = 0; i<n; i++){
		pq.push(arr[i]);
	}

	while(k != 1){
		pq.pop();
		k--;
	}

	return pq.top();
}

int main(){

	int arr[] = {6,7,8,9,6,1,5,0};
	int n = sizeof(arr)/sizeof(int);

	int k = 3;

	cout<<solve(arr,n,k);
	return 0;
}