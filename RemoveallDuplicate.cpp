#include<bits/stdc++.h>
using namespace std;

//You must make sure your result is
//the smallest in lexicographical order
 //among all possible results.

//Due to this statement we cant use this approach 

int main(){

	string s;
	cin>>s;
	string ans = "";

	unordered_map<char,int>mp;
	int n = s.size();

	for(int i = 0; i<n; i++){
		mp[s[i]]++;
	}

	for(auto X:mp){
		if(X.second > 1){
			ans += X.first;
		}
		if(X.second == 1){
			ans += X.first;
		}
	}
	cout<<ans;

	return 0;
}