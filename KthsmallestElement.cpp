#include<bits/stdc++.h>
using namespace std;

int Solve(int *arr,int n, int k){
	int low = arr[0];
	int high = arr[n-1];

	while(low<high){
		int count =  0;
		int mid = low+(high-low)/2;

		count = upper_bound(arr,arr+n,mid)-arr;
		
		if(count<k){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	return low;
}

int main(){
	int arr[] = {1,2,3,10,12,15,18};
	int n = sizeof(arr)/sizeof(int);
	int k = 4;

	cout<<Solve(arr,n,k);

	return 0;
}