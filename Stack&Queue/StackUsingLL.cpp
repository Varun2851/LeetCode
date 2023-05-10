#include<bits/stdc++.h>
using namespace std;

class node{
public:
	node*next;
	int data;

	node(int d){
		data = d;
		next = NULL;
	}
};

class Stack{
private:
	node* head;
	int len;
	int min1;
public:
	
	Stack(){
		head = NULL;
		len = 0;
		min1 = INT_MAX;
	}

	void push(int d){
//		node*n = new node(d);
//		n->next = head;
//		head = n;
//		len++;
		if(d<=min1){
			node*n = new node(d);
			n->next = head;
			head = n;
			len++;
			min1 = d;
		}
		else{
			node*n = new node(d);
			n->next = head;
			head = n;
			len++;
		}
	}

	void pop(){
		if(head == NULL){
			return;
		}
		else if(head->next == NULL){
			delete head;
			head = NULL;
			len--;
			min1 = INT_MAX;
		
		}
		else{
			
			if(head->data == min1){
				min1 = INT_MAX;
				node*temp = head->next;
				while(temp){
					min1 = min(min1,temp->data);
					temp = temp->next;	
				}
			}
			
			node*n = head;
			head = head->next;
			delete n;
			len--;
		}
	}
	int top(){
		return head->data;
	}

	bool empty(){
		return head == NULL;
	}
	int size(){
		return len;
	}
	int getmin(){
		return min1;
	}
};

int main(){

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(-1);

//	while(!s.empty()){
//		cout<<s.top();
//		s.pop();
//	}
	s.pop();
	cout<<s.getmin();

	return 0;
}