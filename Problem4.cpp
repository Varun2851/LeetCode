#include<bits/stdc++.h>
using namespace std;

bool solve(string &s1,string &s2){

	string S_1 = s1;
	string S_2 = s2;

	sort(S_1.begin(),S_1.end());
	sort(S_2.begin(),S_2.end());

	return S_1 == S_2;
}

//to lower and toupper does not work on whole string they work on single char

int main(){
	string s1 = "Listen";
	string s2 = "Silent";
	for(auto &x:s1){
		x = tolower(x);
	}
	for(auto &x1:s2){
		x1 = tolower(x1);
	}
	cout<<solve(s1,s2);
	return 0;
}