//https://leetcode.com/problems/partition-labels/description/
#include<bits/stdc++.h>
using namespace std;

vector<int>solve(string s,unordered_map<char,int>&mp){
	int n = s.size();
	vector<int>ans;

	for(int i = 0; i<n; i++){
		mp[s[i]]  = i; //save the last index of the char
	}

	int maxi = 0;
	int prev = -1;

	for(int i = 0; i<n; i++){
		maxi = max(maxi,mp[s[i]]);

		if(i == maxi){
			ans.push_back(i-prev);
			prev = maxi;
		}
	}
	return ans;
}

int main(){

	string s;
	cin>>s;
	unordered_map<char,int>mp;
	//function calling

	vector<int>res = solve(s,mp);
	for(auto X:res){
		cout<<X<<" ";
	}
	
	return 0;
}