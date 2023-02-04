#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin>>s;
	unordered_map<char,int>mp;
	int n = s.size();
	int maxLen = INT_MIN;
	int i = 0;
	int j = 0;

	int high = 0;
	int low = 0;

	while(j<n){
		//first insert the char into the map
		mp[s[i]]++;

		//1.check the size of map

		if(mp.size() == j-i+1){
			maxLen = max(maxLen,j-i+1);
			low = i;
			high = j;
			j++;
		}
		else if(mp.size() < j-i+1){
			while(mp.size()<j-i+1){
				mp[s[i]]--;

				if(mp[s[i]] == 0){
					mp.erase(s[i]);
				}
				i++;
			}
			j++;
		}
	}

	for(int i =  low; low<=high; low++){
		cout<<s[low];
	}

	return 0;
}