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

node*CreateTree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	else{
		node*root = new node(data);
		root->left = CreateTree();
		root->right = CreateTree();
		return root;
	}
}

// int height(node*root){
// 	//base case
// 	if(root == NULL){
// 		return 0;
// 	}

// 	//recursive case
// 	int left_height = height(root->left);
// 	int right_height = height(root->right);
// 	return max(left_height,right_height)+1;
// }

// int Diameter(node*root){
// 	//base case
// 	if(root == NULL){
// 		return 0;
// 	}
// 	//recursive case
// 	//1.Diameter is via the left subtree
// 	int op1 = Diameter(root->left);
// 	//2.Diameter is via left subtree
// 	int op2 = Diameter(root->right);
// 	//3.Diameter is via root  node
// 	int op3 = height(root->left)+height(root->right);

// 	return max(op1,max(op2,op3));

// }

class Pair {
public:
	int height;
	int diameter;
};

Pair FastDiameter(node*root){
	Pair p; //make object of class
	//base case
	if(root == NULL){
		p.height = p.diameter  = 0;
		return p;
	}
	//recursive case
	Pair left = FastDiameter(root->left);
	Pair right = FastDiameter(root->right);

	p.height = max(left.height,right.height)+1;
	int op1 = left.height+right.height; //dia via root
	int op2 = left.diameter;
	int op3 = right.diameter;

	p.diameter = max(op1,max(op2,op3));
	return p;
}

int SumOfBt(node*root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	return SumOfBt(root->left)+SumOfBt(root->right)+root->data;
}

int main(){

	node*root = CreateTree();
	//cout<<Diameter(root);
	Pair ans = FastDiameter(root);
	cout<<"fast diameter :"<<ans.diameter<<endl;
	cout<<SumOfBt(root);
	return 0;
} 