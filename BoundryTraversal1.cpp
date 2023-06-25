#include <bits/stdc++.h>
using namespace std;

class node {
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

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}

void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}


void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}



vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}



int main() {

  node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}