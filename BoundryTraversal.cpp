
#include <iostream>
using namespace std;

int cnt = 0;

class Node {
public:
	int data;
	Node*left;
	Node*right;

	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* newNode(int d)
{
	
	Node*n = new Node(d);
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

// A simple function to print leaf nodes of a binary tree
void printLeaves(Node* root)
{
	if (root == nullptr)
		return;

	printLeaves(root->left);

	// Print it if it is a leaf node
	if (!(root->left) && !(root->right))
		cout << root->data << " ";

	printLeaves(root->right);
}

// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root)
{
	if (root == nullptr)
		return;

	if (root->left) {
		
		// to ensure top down order, print the node
		// before calling itself for left subtree
		cout << root->data << " ";
		printBoundaryLeft(root->left);
	}
	else if (root->right) {
		cout << root->data << " ";
		printBoundaryLeft(root->right);
	}
	// do nothing if it is a leaf node, this way we avoid
	// duplicates in output
  	
}

// A function to print all right boundary nodes, except a
// leaf node Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root)
{
	if (root == nullptr)
		return;

	if (root->right) {
		// to ensure bottom up order, first call for right
		// subtree, then print this node
		printBoundaryRight(root->right);
		cout << root->data << " ";
	}
	else if (root->left) {
		printBoundaryRight(root->left);
		cout << root->data << " ";
	}
	
}


void printBoundary(Node* root)
{
	if (root == nullptr)
		return;

	cout << root->data << " ";

	// Print the left boundary in top-down manner.
	printBoundaryLeft(root->left);

	// Print all leaf nodes
	printLeaves(root->left);
	printLeaves(root->right);

	// Print the right boundary in bottom-up manner
	printBoundaryRight(root->right);
}


int main()
{
	
	Node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);
  
  
  

	printBoundary(root);

	return 0;
}


