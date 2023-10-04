#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string phoneNumber;
    Node* left;
    Node* right;
    Node(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }
    void insert(string name, string phoneNumber) {
        root = insertHelper(root, name, phoneNumber);
    }
    Node* insertHelper(Node* root, string name, string phoneNumber) {
        if (root == NULL) {
            return new Node(name, phoneNumber);
        }
        if (name < root->name) {
            root->left = insertHelper(root->left, name, phoneNumber);
        }
        else {
            root->right = insertHelper(root->right, name, phoneNumber);
        }
        return root;
    }
    void display() {
        displayHelper(root);
    }
    void displayHelper(Node* root) {
        if (root != NULL) {
            displayHelper(root->left);
            cout << root->name << " : " << root->phoneNumber << endl;
            displayHelper(root->right);
        }
    }
    Node* search(string name) {
        return searchHelper(root, name);
    }
    Node* searchHelper(Node* root, string name) {
        if (root == NULL || root->name == name) {
            return root;
        }
        if (name < root->name) {
            return searchHelper(root->left, name);
        }
        else {
            return searchHelper(root->right, name);
        }
    }
    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    Node* remove(Node* root, string name) {
        if (root == NULL) {
            return root;
        }
        if (name < root->name) {
            root->left = remove(root->left, name);
        }
        else if (name > root->name) {
            root->right = remove(root->right, name);
        }
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->name = temp->name;
            root->phoneNumber = temp->phoneNumber;
            root->right = remove(root->right, temp->name);
        }
        return root;
    }
};

int main() {
    BST phonebook;
    phonebook.insert("John Doe", "123-456-7890");
    phonebook.insert("Jane Doe", "456-789-0123");
    phonebook.insert("Bob Smith", "789-012-3456");
    phonebook.insert("Alice Johnson", "234-567-8901");

    cout << "Phonebook entries:" << endl;
    phonebook.display();

    Node* searchResult = phonebook.search("Bob Smith");
    if (searchResult != NULL) {
        cout << "Found " << searchResult->name << " with phone number " << searchResult->phoneNumber << endl;
    }
    else {
        cout << "Could not find Bob Smith in the phonebook" << endl;
    }
    
    return 0;
}