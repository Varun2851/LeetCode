#include<iostream>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		int N;
		cin>>N;
		string s;
		cin>>s;

		int cnt1 = 0;
		int cnt2 = 0;

		for(int i = 0 ; i<N; i++){
			if(s[i] == '1'){
				cnt1++;
			}
			else if(s[i] == '0'){
				cnt2++;
			}
		}

		cout<<2*min(cnt1,cnt2) + (cnt1 != cnt2)<<endl;
	}
	return 0;
}