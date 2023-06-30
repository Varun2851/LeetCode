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

node*newNode(int d){
	node*n = new node(d);
	n->left = NULL;
	n->right = NULL;
	return n;
}

bool isleaf(node*root){
	return (!root->left) and (!root->right);
}

void leaf(node*root,vector<int>&res){

	if(isleaf(root)){
		res.push_back(root->data);
		return;
	}

	if(root->left){
		leaf(root->left,res);
	}

	if(root->right){
		leaf(root->right,res);
	}

}

void rightTraversal(node* root, vector<int>& res) {
    vector<int> temp;

    node* curr = root->right;

    while (curr) {
        if (!isleaf(curr)) {
            temp.push_back(curr->data);
        }

        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    for (int i = temp.size()-1; i>=0; i--) {
        res.push_back(temp[i]);
    }
}


void leftTraversal(node*root,vector<int>&res){
	node*curr = root->left;
	while(curr){
		if(!isleaf(curr)){
			res.push_back(curr->data);
		}
		if(curr->left){
			curr = curr->left;
		}
		else{
			curr =  curr->right;
		}
	}
}

vector<int>BoundryTraversal(node*root){

	vector<int>res;

	if(root == NULL){
		return res;
	}

	if(!isleaf(root)){
		res.push_back(root->data);
	}

	leftTraversal(root,res);

	leaf(root,res);

	rightTraversal(root,res);

	return res;
}

int main(){

  node * root = newNode(1); 
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  //root -> left -> left -> right -> left = newNode(5);
 // root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  //root -> right -> right -> left -> left = newNode(10);
  //root -> right -> right -> left -> right = newNode(11);

	vector<int>res1 = BoundryTraversal(root);

	for(int i = 0; i<res1.size(); i++){
		cout<<res1[i]<<" ";
	}

	return 0;

}