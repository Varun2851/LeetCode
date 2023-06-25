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

bool isleaf(node*root){

	return (!root->right) and (!root->left);
}

void addLeaf(node*root,vector<int>&res){

	if(isleaf(root)){
		res.push_back(root->data);
		return;
	}

	if(root->left){
		addLeaf(root->left,res);
	}

	if(root->right){
		addLeaf(root->right,res);
	}

}

void addRight(node*root,vector<int>&res){

	vector<int>temp;

	node*curr = root->right;

	while(curr){
		if(!isleaf(curr)){
			temp.push_back(curr->data);
		}

		if(curr->right){
			curr = curr->right;
		}

		else{
			curr = curr->left;
		}
	}

	for(int i = temp.size()-1; i>=0; i--){
		res.push_back(temp[i]);
	}

}

void addLeft(node*root,vector<int>&res){
	node*curr = root->left;

	while(curr){
		if(!isleaf(curr)){
			res.push_back(curr->data);
		}

		if(curr->left){
			curr = curr->left;
		}
		else{
			curr = curr->right;
		}
	}
}

node*CreateTree(int d){
	node*n = new node(d);
	n->left = NULL;
	n->right = NULL;

	return n;
}

vector<int>BoundryTraversal(node*root,vector<int>&res){
	if(!root){
		return res;
	}

	if(!isleaf(root)){
		res.push_back(root->data);
	}

	addLeft(root,res);

	addLeaf(root,res);

	addRight(root,res);

	return res;
}

int main(){

	node*root = CreateTree(1);
	root->left = CreateTree(2);
	root->left->left = CreateTree(4);
	root->left->right = CreateTree(5);

	root->right = CreateTree(3);
	root->right->right = CreateTree(7);

	vector<int>res;
	BoundryTraversal(root,res); 

	for(int i = 0; i<res.size(); i++){
		cout<<res[i]<<" ";
	}

	return 0;
}