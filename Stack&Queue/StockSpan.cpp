#include<bits/stdc++.h>
using namespace std;

void solve(int *prices,int *s,int n){

	s[0] = 1;

	for(int i = 1; i<n; i++){
		s[i] = 1;

		for(int j = i-1; (j>=0) and (prices[i]>=prices[j]); j--){
			s[i]++;
		}
	}

	for(int i = 0; i<n; i++){
		cout<<s[i]<<" ";
	}
}


//optimised approach using stack

void solveUsingStack(int*prices,int*s,int n){
	stack<int>st;
	s[0] = 1;
	st.push(0);

	for(int i = 1; i<n; i++){
		while(!st.empty() and prices[st.top()] < prices[i]){
			st.pop();
		}

		if(st.empty()){
			s[i] = i+1;
		}
		else{
			s[i] = i-st.top();
		}

		st.push(i);
	}

	for(int i = 0; i<n; i++){
		cout<<s[i]<<" ";
	}
}

int main(){
	int prices[] = {10,4,5,90,120,80};
	int n = sizeof(prices)/sizeof(int);

	int s[n];

	solveUsingStack(prices,s,n);

	return 0;
}