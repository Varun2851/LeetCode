#include<bits/stdc++.h>
using namespace std;

int solve1(int *arr,int n, int k){
	int count = 0;
	queue<int>q;
	int sum = 0;
	for(int right = 0; right<n; right++){
		sum += arr[right];
		q.push(arr[right]);

		while(sum<=k){
			int x = q.front();
			q.pop();
			k = k -x;
			count += q.size();
		}
		
	}
	return count;
}

int main(){
	int arr[] = {2,5,6};
	int n = 3;
	int k = 10;
	cout<<solve1(arr,n,k);
	return 0;
}