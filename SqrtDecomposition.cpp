#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

	int arr[n];

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int len = sqrt(n)+1;

	vector<int>blocksum(len);
    //1.Calculate Block Sum

    for(int i = 0; i<n; i++){
    	blocksum[i%len] += arr[i];
    }

    //2.Apply sqrtDecomposition
    int q;
    cin>>q;
    while(q--){
    	int l ,r;
    	int sum = 0;
    	cin>>l>>r;

    	for(int i = l; i<=r;){
    		//Two cases if our sum exist in one block or does not exist
    		if(i%len == 0 and i+len-1 <= r){
    			//sum exist in block
    			sum += blocksum[i%len];
    			i = i+len; // move to next block
    		}
    		else{
    			sum += arr[i];
    			i++;
    		}
    	}
    	cout<<sum<<endl;
    }
    
    return 0;
}