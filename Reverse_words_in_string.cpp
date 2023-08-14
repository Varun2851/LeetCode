#include<bits/stdc++.h>
using namespace std;

string solve(string &s, int n){

	vector<string>v;
	string temp = "";
	string ans = "";

	for(int i = 0; i<n; i++){
		if(s[i] == '.'){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp += s[i];
		}
	}
	v.push_back(temp);

	for(int i = v.size()-1; i>=1; i--){
		ans += v[i]+'.';
	}
	ans += v[0];
	return ans;
}

int main(){
	string s = "i.like.this.program.very.much";
	int n = s.size();
	string ans = solve(s,n);
	cout<<ans;
	return 0;
}