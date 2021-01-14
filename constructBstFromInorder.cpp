#include<bits/stdc++.h>
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
void getLeafNodes(Node* root, vector<int> &leaves) {
	if (root == nullptr) {
		return;
	}
	getLeafNodes(root->left, leaves);
	if (root->right == nullptr && root->left == nullptr) {
		leaves.push_back(root->data);
	}
	getLeafNodes(root->right, leaves);
}
void getLeftNodes(Node* root, vector<int> &left) {
	if (root == nullptr) {
		return;
	}

	if (root->left) {
		left.push_back(root->data);
		getLeftNodes(root->left, left);
	}
	else if (root->right) {
		left.push_back(root->data);
		getLeftNodes(root->right, left);
	}
}
void getRightNodes(Node* root, vector<int> &right) {
	if (root == nullptr) {
		return;
	}
	if (root->left) {
		getRightNodes(root->left, right);
		right.push_back(root->data);
	}
	else if (root->right) {
		getRightNodes(root->right, right);
		right.push_back(root->data);
	}

}

vector <int> printBoundary(Node *root)
{
	vector<int> order;
	order.push_back(root->data);
	getLeftNodes(root->left, order);
	getLeafNodes(root->left, order);
	getLeafNodes(root->right, order);
	getRightNodes(root->right, order);
	return order;
}

int main() {
	Node* root = new Node(5);
	root->left = new Node(4);
	root->right = new Node(3);
	root->left->left = new Node(2);
	root->right->right = new Node(7);
	vector<int> boundary = printBoundary(root);
	for (auto el : boundary) {
		cout << el << " ";
	}
	return 0;
}
// void getInorder(vector<int> &v, Node*root) {
// 	if (root == nullptr) {
// 		return;
// 	}
// 	getInorder(v, root->left);
// 	v.push_back(root->data);
// 	getInorder(v, root->right);
// }
// void setTree(Node* root, vector<int> inorder, int &index) {
// 	if (root == nullptr) {
// 		return;
// 	}
// 	setTree(root->left, inorder, index);
// 	root->data = inorder[index];
// 	index += 1;
// 	setTree(root->right, inorder, index);
// }
// Node *binaryTreeToBST (Node *root)
// {
// 	std::vector<int> inorder;
// 	getInorder(inorder, root);
// 	sort(inorder.begin(), inorder.end());
// 	int index = 0;
// 	setTree(root, inorder, index);
// 	return root;
// }
// void inorder(Node* root) {
// 	if (root == nullptr) {
// 		return;
// 	}
// 	inorder(root->left);
// 	cout << root->data << " ";
// 	inorder(root->right);
// }
