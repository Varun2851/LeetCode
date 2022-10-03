#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2){
	map<char,int>mp1;

	for(int i = 0; i<s1.size(); i++){
		mp1.insert({s1[i],i}); // in this way we can store the index corresponding to char
	}
	int last = 0;
	int total = 0;

	for(int i = 0; i<s2.size(); i++){
		total += abs(mp[s2[i]] - last);
		last = mp1[s2[i]]; //this will give the index of the character 
	}

	return total;
}

int main(){

	string s1 = "abcdefghijklmnopurstuvwxyz";
	string s2 = "cba";

	int ans = solve(s1,s2);
	cout<<ans<<endl;
	return 0;
}