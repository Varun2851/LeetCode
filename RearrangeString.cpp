#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string Rearrange(string s,unordered_map<char,int>&mp){
	string res =  "";
	int n = s.size();
	for(int i = 0; i<n; i++){
		mp[s[i]]++;
	}
	priority_queue<pair<int,char>>pq;

	for(auto X : mp){
		pq.push({X.first,X.second});
	}

	while(pq.size()>1){

		auto top1 = pq.top();
		pq.pop();
		auto top2 = pq.top();
		pq.pop();

		res += top1.second;
		res += top2.second;

		top1.second = top1.second-1;
		top2.second = top2.second-1;

		if(top1.first>0){
			pq.push(top1);
		}
		if(top2.first>0){
			pq.push(top2);
		}
	}

	if(!pq.empty()){
		if(pq.top().first>1){
			return "";
		}
		else{
			res += pq.top().second;
		}
	}
	return res;
}

int main(){

	string s;
	cin>>s;
	unordered_map<char,int>mp;

	string ans = Rearrange(s,mp);
	cout<<ans;
	return 0;
}