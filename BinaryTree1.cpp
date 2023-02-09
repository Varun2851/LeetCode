#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		left = NULL;
		right = NULL;
		data = d;
	}
};

/////////////////////////// taking input of binary tree////////////////////////
node*BuildTree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	else{
		node*root = new node(data);
		root->left = BuildTree();
		root->right = BuildTree();
		return root;
	}
}
/////////////////////////// taking input of binary tree////////////////////////


void Inorder(node*root){
	//base case
	if(root==NULL){
		return;
	}
	//recursive case
	Inorder(root->left);
	cout<<root->data<<",";
	Inorder(root->right);
}

void PrintLevel(node*root){
	queue<node*>q;
	q.push(root); 
	q.push(NULL);

	while(!q.empty()){
		node*X = q.front();
		q.pop();
		if(X==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<X->data<<" ";
			if(X->left){
				q.push(X->left);
			}
			if(X->right){
				q.push(X->right);
			}
		}
	}
}

node*BuildTreeLevelWise(){

	node*root = NULL;
	int data;
	cout<<"Enter root data";
	cin>>data;
	if(data == -1){
		return NULL;
	}
	root = new node(data);
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node*X = q.front();
		q.pop();

		cout<<"Enter the children of root "<<X->data<<endl;
		int left_child;
		cin>>left_child;
		int right_child;
		cin>>right_child;

		if(left_child != -1){
			X->left = new node(left_child);
			q.push(X->left);
		}
		if(right_child != -1){
			X->right = new node(right_child);
			q.push(X->right);
		}
	}
	return root;
}
///////////////////////Tree from In and Pre ///////////////////////
int pre[] = {8,3,1,6,4,7,10,14,13};
int i = 0;
int in[] = {1,3,4,6,7,8,10,13,14};

node*CreateTree(int s, int e){
	//base case
	if(s>e){
		return NULL;
	}
	//recursive case
	int d = pre[i++];
	node*root = new node(d);
	int k = -1;

	for(int j = s; j<=e; j++){
		if(in[j] == d){
			k = j;
			break;
		}
	}
	root->left = CreateTree(s,k-1);
	root->right = CreateTree(k+1,e);

	return root;
}
///////////////////////Tree from In and Pre ///////////////////////
///////////////////////Count Nodes/////////////////////////////////

int CountNodes(node*root){
	//base case
	if(root == NULL){
		return 0;
	}

	//recursive case
	return CountNodes(root->left)+CountNodes(root->right)+1;
}

///////////////////////Count Nodes/////////////////////////////////
int main(){

	//node*root = BuildTree();
	//node*root = BuildTreeLevelWise();
	int n = sizeof(in)/sizeof(int);
	node*root = CreateTree(0,n-1);
	Inorder(root);
	cout<<endl;
	PrintLevel(root);
	cout<<CountNodes(root);
	return 0;
}
