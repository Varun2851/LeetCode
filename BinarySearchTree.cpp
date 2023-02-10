#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
///////////////////////InsertInBST//////////////////////////////////
node*InsertInBST(node*root,int data){
	//base case
	if(root == NULL){
		root = new node(data);
		return root; 
	}

	//recursive case
	if(data <= root->data){
		root->left = InsertInBST(root->left,data);
	}
	else{
		root->right = InsertInBST(root->right,data);
	}
	return root;
}
///////////////////////InsertInBST//////////////////////////////////
///////////////////////Build Tree//////////////////////////////////
node*BuildTree(){
	node*root = NULL;
	int data;
	cin>>data;
	while(data != -1){
		root = InsertInBST(root,data);
		cin>>data;
	}
	return root;
}
///////////////////////Build Tree//////////////////////////////////
//////////////////////Print Level//////////////////////////////////
void PrintLevel(node*root){
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node*x = q.front();
		q.pop();
		if(x == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<x->data<<" ";
			if(x->left){
				q.push(x->left);
			}
			if(x->right){
				q.push(x->right);
			}
		}
	}
}
//////////////////////Print Level//////////////////////////////////
///////////////////////Find an element in BST//////////////////////
node*SearchBST(node*root,int key){
	//base case
	if(!root){
		return NULL;
	}

	//recursive case
	if(root->data = key){
		return root;
	}
	else if(key<=root->data){
		return SearchBST(root->left,key);
	}
	else{
		return SearchBST(root->right,key);
	}

}
///////////////////////Find an element in BST//////////////////////
int main(){

	node*root = BuildTree();
	PrintLevel(root);
	node*ans = SearchBST(root , 6);
	if(ans == NULL){
		cout<<"key does not exist in the tree"<<endl;
	}
	else{
		cout<<"Key Exist in the tree"<<endl;
	}

	return 0;
}