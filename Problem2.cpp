#include<iostream>
using namespace std;
void solve(int *arr,int n){
	int smallest = INT_MAX;

	for(int i = 0; i<n; i++){
		if(arr[i]<smallest){
			smallest = arr[i];
		}
	}
	cout<<"First smallest element is"<<smallest<<endl;

	int second_Smallest = INT_MAX;

	for(int i  = 0; i<n; i++){
		if(arr[i]<second_Smallest and arr[i]>smallest){
			second_Smallest = arr[i];
		}
	}
	cout<<"second smallest element is"<<second_Smallest<<endl;
}
int main(){

	int arr[] = {12, 13, 1, 10, 34, 1};
	int n = sizeof(arr)/sizeof(int);

	solve(arr,n);
	return 0;
}