#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&v,int k){

	map<int,int>mp;

	for(auto X : v){
		mp[X]++;
	}

	for(auto X:mp){
		int key = X.first;
		while(key){
			for(int i = key; i<key+k; i++){
				mp[i]--;
				if(mp[i] < 0){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){

	vector<int>v = {1,2,3,3,4,4,5,6};
	int k;
	cin>>k;
	bool ans = solve(v,k);
	cout<<ans;
	return 0;
}