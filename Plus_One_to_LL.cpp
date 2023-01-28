#include<iostream>
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

void Insertend(node*&head,node*&tail,int data){
	node*n = new node(data);
	//first check ll exist previously or not 
	if(head == NULL){
		//it means there is no ll
		head = tail = n;
	}
	else{
		//we have a ll
		tail->next = n;
		tail = n;
	}
}

node* addOne(node*head){

	//set pointers
	node*t = head;
	node*not9 = head;

	while(t){
		if(t->data != 9){
			not9 = t;
		}
		t = t->next;
	}
	not9->data = not9->data+1;
	not9 = not9->next;

	while(not9){
		not9->data = 0;
		not9 = not9->next;
	}

	if(head == 0){
		return head->next;
	}
	else{
		return head;
	}
}


int main(){

	node*head = NULL;
	node*tail = NULL;
	Insertend(head,tail,5);
	Insertend(head,tail,6);
	Insertend(head,tail,6);
	Insertend(head,tail,9);

	node*ans = addOne(head);

	while(ans){
		cout<<ans->data<<"->";
		ans = ans->next;
	}
    cout<<"NULL";
	return 0;
}