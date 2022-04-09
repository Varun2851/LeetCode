#include<iostream>
using namespace std;

void subset(int arr[] , int i, int output[] , int j, int n){
	//base case
	if( i == n){
		//print the subset array
		int idx = 0;
		while(idx < j){
			cout<<output[idx];
			idx++;
		}
		cout<<endl;
		return;
	}
	//recursive case
	//exclude ith digit 
	subset(arr,i+1,output,j,n);

	//include ith digit
	output[j] = arr[i];
	subset(arr, i+1, output, j+1, n);
}

int main(){

	int arr[] = {1,2,3};
	int n = 3;
	int output[1000];

	subset(arr, 0,output, 0 , n);

}