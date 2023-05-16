#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int>&s,int topElement){

	
	if(s.empty()){
		s.push(topElement);
		return;
	}
	//recursive case
	int top = s.top();
	s.pop();
	InsertAtBottom(s,topElement);
	s.push(top);
}


void Reverse(stack<int>&s){
	//base case
	if(s.empty()){
		return;
	}
	//recursive case
	int topElement = s.top();
	s.pop();
	Reverse(s);
	InsertAtBottom(s,topElement);

}

void Print(stack<int>s){ //dont send stack call by reference in print function

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){

	stack<int>s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	Print(s);
	Reverse(s);
	Print(s);

	return 0;

}