#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};

class Stack{
private:
	node*head;
	int len;
public:
	Stack(){
		head = NULL;
		len = 0;
	}

	void push(int d){
		node*n = new node(d);
		n->next = head;
		head = n;
		len++;
	}

	void pop(){
		//delete at front
		if(head == NULL){
			return;
		}
		else if(head->next == NULL){
			delete head;
			head = NULL;
			len--;
		}
		else{
			node*n = head;
			head = head->next;
			delete n;
			len--;
		}
	}
	bool empty(){
		return len == 0;
	}
	int size(){
		return len;
	}
	int top(){
		return head->data;
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