#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
	vector<int>v;
public:
	void push(int data){
		v.push_back(data);
	}
	void pop(){
		return v.pop_back();
	}

	int size(){
		return v.size();
	}

	int top(){
		return v[v.size()-1];
	}
	bool empty(){
		return v.size() == 0;
	}
};

int main(){

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);


	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
}