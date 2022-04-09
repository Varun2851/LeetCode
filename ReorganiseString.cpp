#include<bits/stdc++.h>
using namespace std;

string solve(string s, int n){
	unordered_map<char,int>mp;
	priority_queue<pair<int , char>pq;
	string res = "";

	for(int i = 0; i<n; i++){
		mp[s[i]]++;
	}
	//insert freq nd char to pq;
	for(auto X : mp){
		pq.push({X.second , X.first});
	}

	while(pq.size()>1){
		auto top1 = pq.top();
		pq.pop();

		auto top2 = pq.top();
		pq.pop();

		// Now add char to our string res

		res += top1.second;
		res += top2.second;

		top1.first = top1.first-1;
		top2.first = top2.first-1;

		//Now push back to pq
		if(top1.first > 0){
			pq.push(top1);
		}
		if(top2.first > 0){
			pq.push(top2);
		}
	}
	if(pq.size() == 1){
		if(pq.top().first > 1){
			return "";
		}
		else{
			res += pq.top().second;
		}
	}
	return res;
}

int main(){

	string s = "aab";
	int n  = s.size();

	cout<<solve(s,n)<<endl;
	return 0;
}