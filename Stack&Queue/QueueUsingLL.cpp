#include<bits/stdc++.h>
using namespace std;
template <typename T>
class node{
public:
	T data;
	node<T>*next;

	node(T d){
		data = d;
		next = NULL;
	}
};
template<typename T>
class Queue{
private:
	node<T>*head,*tail;
	T len;
public:
	Queue(){
		head = tail = NULL;
		len = 0;
	}

	void push(T d){
		if(head == NULL and tail == NULL){
			node<T>*n = new node<T>(d);
			head = tail = n;
			len++;
		}
		else{
			node<T>*n = new node<T>(d);
			tail->next = n;
			tail = n;
			len++;
		}
	}

	void pop(){
		if(head == NULL){
			return;
		}

		else if(head->next == NULL){
			delete head;
			head = tail = NULL;
			len--;
		}
		else{
			node<T>*n = head;
			head = head->next;
			delete n;
			len--;
		}
	}
	T front(){
		return head->data;
	}

	bool empty(){
		return len == 0;
	}

	int size(){
		return len;
	}
};

int main(){

	//Queue<int>q;
	Queue<char>q;

	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);
	// q.push(5);

	q.push('a');
	q.push('b');
	q.push('c');
	q.push('d');
	q.push('e');

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}