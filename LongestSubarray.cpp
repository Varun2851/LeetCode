#include<iostream>
using namespace std;

int main(){

	int arr[] = {9, -3, 3, -1, 6, -5};
	int n = sizeof(arr)/sizeof(int);

	int maxi =  0;
	for(int i = 0; i<n; i++){
		int sum = 0;
		for(int j = i; j<n; j++){
			sum = sum+arr[j];

			if(sum == 0){
				maxi = max(maxi , j-i+1);
			}
		}
	}
	cout<<maxi<<endl;
	return 0;
}