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

Node* search(Node *root, int val) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->left && root->left->data == val) {
		return root;
	}

	else if (root->right && root->right->data == val) {
		return root;
	}
	else if (root->data == val) {
		return root;
	}
	else if (val < root->data) {
		search(root->left, val);
	}
	else {
		search(root->right, val);
	}
}
Node* deleteNode(Node* root, int key) {
	Node* pre = search(root, key);
	Node* del = nullptr;

	if (pre->left && pre->left->data == key) {
		del = pre->left;
		if (del->left && del->right) {
			pre->left = del->left;
			Node* temp = del->left;
			while (temp->right != nullptr) {
				temp = temp->right;
			}
			temp->right = del->right;
			delete del;
		}
		else if (del->left) {
			pre->left = del->left;
			delete del;
		}
		else if (del->right) {
			pre->left = del->right;
			delete del;
		}
	}
	else if (pre->right && pre->right->data == key) {
		del = pre->right;
		if (del->left && del->right) {
			pre->right = del->right;
			Node* temp = del->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			temp->left = del->left;
			delete del;
		}
		else if (del->left) {
			pre->right = del->left;
			delete del;
		}
		else if (del->right) {
			pre->right = del->right;
			delete del;
		}
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
	insert(root, 7);

	inorder(root);
	cout << endl;
	deleteNode(root, 10);
	inorder(root);

	// cout << search(root, 21);

	return 0;
}


TreeNode* search(TreeNode *root, int val) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->left && root->left->val == val) {
		return root;
	}

	else if (root->right && root->right->val == val) {
		return root;
	}
	else if (root->val == val) {
		return root;
	}
	else if (val < root->val) {
		return search(root->left, val);
	}
	else {
		return search(root->right, val);
	}
}

TreeNode* deleteNode(TreeNode* root, int key) {
	TreeNode* pre = search(root, key);
	TreeNode* del = nullptr;
	if (root->data == pre->data) {
		TreeNode* l = root->left;
		while (l->right != nullptr) {
			l = l->right;
		}
		l->right = root->right;
		return root->left;
	}
	if (pre == nullptr) {
		return root;
	}
	if (pre->left && pre->left->val == key) {
		del = pre->left;
		if (del->left && del->right) {
			pre->left = del->left;
			TreeNode* temp = del->left;
			while (temp->right != nullptr) {
				temp = temp->right;
			}
			temp->right = del->right;
			delete del;
		}
		else if (del->left) {
			pre->left = del->left;
			delete del;
		}
		else if (del->right) {
			pre->left = del->right;
			delete del;
		}
	}
	else if (pre->right && pre->right->val == key) {
		del = pre->right;
		if (del->left && del->right) {
			pre->right = del->right;
			TreeNode* temp = del->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			temp->left = del->left;
			delete del;
		}
		else if (del->left) {
			pre->right = del->left;
			delete del;
		}
		else if (del->right) {
			pre->right = del->right;
			delete del;
		}
	}
	return root;
}

