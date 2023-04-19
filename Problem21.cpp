#include<bits/stdc++.h>
using namespace std;


//bubble sort

int BubbleSort(int *arr, int n){

	int globalCount = 0;

	for(int i = 0; i<n-1; i++){
		int cnt = 0;
		for(int j = 0; j<=n-2-i; j++){
			if(arr[j]>arr[j+1]){
				cnt++;
				globalCount++;
				swap(arr[j],arr[j+1]);
			}
		}
		if(cnt == 0){
			break;
		}
	}
	return globalCount;
}

int main(){

	//int arr[] = {123, 21, 34, 45, 25, 675, 23, 44, 55, 900};
	int arr[] = {2};
	int n = sizeof(arr)/sizeof(int);

	cout<<BubbleSort(arr,n);
	return 0;
}