#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b, int na, int nb){
	
	vector<int>f1(256,0);
	vecror<int>f2(256,0);

	for(auto x : a){
		f1[x]++;
	}

	for(auto y : b){
		f2[y]++;
	}

	for(int i = 0; i<256; i++){
		if(f1[i] != f2[i]){
			return -1;
		}
	}

	int cnt = 0;
	int i = na-1;
	int j = nb-1;

	while(i>=0 and j>=0){
		while(i>=0 and a[i] != b[j]){
			i--;
			cnt++;
		}
		i--;
		j--;
	}
	return cnt;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string a = "abd";
	string b = "bad";

	int na = a.size();
	int nb = b.size();

	int ans = solve(a,b,na,nb);
	cout<<"Minimum operation to make both string equal is"<<ans<<endl;
	return 0;
}