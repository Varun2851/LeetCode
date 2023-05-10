#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int>&st, int topElement){
	//base case
	if(st.empty()){
		st.push(topElement);
		return;
	}
	//recursive case
	int top = st.top();
	st.pop();
	InsertAtBottom(st,topElement);
	st.push(top);
}

void Reverse(stack<int>&st){
	//base case
	if(st.empty()){
		return;
	}

	//recursive case
	int topElement = st.top();
	st.pop();
	Reverse(st);
	InsertAtBottom(st,topElement);

}

void Print(stack<int>st){
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}

int main(){

	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	Print(st);
	Reverse(st);
	cout<<endl;
	Print(st);
	
	return 0;
}