#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin>>s;
	unordered_map<char,int>mp;
	string ans = "";

	int n = s.size();

	for(int i = 0; i<n; i++){
		mp[s[i]]++;
	}

	for(auto X : mp){
		if(X.second == 2){
			while(X.second!=0){
				ans += X.first;
				X.second--;
			}
		}
		if(X.second > 2){
			int cnt = 2;
			while(cnt){
				ans += X.first;
				cnt--;
			}
		}
		if(X.second == 1){
			continue;
		}
	}

	sort(ans.begin(),ans.end());

	cout<<ans;

	return 0;
}