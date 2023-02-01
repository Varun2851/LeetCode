#include<iostream>
using namespace std;
class node{
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left =  NULL;
		right =  NULL;
	}
};

node* CreateBt(){
	int data;
	cin>>data;

	if(data == -1){
		return NULL;
	}
	else{
		node*root = new node(data);
		root->left = CreateBt();
		root->right = CreateBt();
		return root;
	}
}
int height(node*root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	int left_height = height(root->left);
	int right_height = height(root->right);

	return max(left_height,right_height)+1;
}
void PrintSpiral(node*root){
	int h = height(root);
	bool flag = false;

	for(int i = 1; i<=h; i++){
		Printlevel(root,i,flag);

		flag = !flag;
	}
}
void Printlevel(node*root,int  level, bool flag){
	//base case
	if(root == NULL){
		return;
	}

	if(level == 1){
		cout<<root->data<<" "; //print the root node
	}

	else if(level>1){
		if(flag){
			Printlevel(root->left,level-1,flag);
			Printlevel(root->right,level-1,flag);
		}
		else{
			Printlevel(root->right,level-1,flag);
			Printlevel(root->left,level-1,flag);
		}
	}
}
int main(){

	node*root = CreateBt();
	PrintSpiral(root);
	return 0;
}