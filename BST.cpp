#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

Node* insert(Node* root, int val) {
	if (root == nullptr) {
		return new Node(val);
	}
	if (val >= root->data) {
		root->right = insert(root->right, val);
	}
	else if (val < root->data) {
		root->left = insert(root->left, val);
	}
	return root;
}

bool search(Node *root, int val) {
	if (root == nullptr) {
		return false;
	}
	if (root->data == val) {
		return true;
	}
	else if (val < root->data) {
		search(root->left, val);
	}
	else {
		search(root->right, val);
	}
}

void inorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int main() {
	Node* root = nullptr;
	root = insert(root, 13);
	insert(root, 10);
	insert(root, 12);
	insert(root, 33);
	insert(root, 22);
	insert(root, 11);
	inorder(root);
	// cout << search(root, 22) << endl;
	// cout << search(root, 21);

	return 0;
}