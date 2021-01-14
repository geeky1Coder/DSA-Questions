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

void bottomView_util(Node* root, int hd, std::map<int, std::pair<int, int>> &m, int height, int &minHD, int &maxHD) {
	if (root == nullptr) {
		return;
	}
	if (m.count(hd) > 0) {
		if (m[hd].second > height) {
			m[hd] = make_pair(root->data, height);
		}
	}
	else {
		m[hd] = make_pair(root->data, height);
	}
	if (hd < minHD) {
		minHD = hd;
	}
	if (hd > maxHD) {
		maxHD = hd;
	}
	bottomView_util(root->left, hd - 1, m, height + 1, minHD, maxHD);
	bottomView_util(root->right, hd + 1, m, height + 1, minHD, maxHD);
}
vector <int> bottomView(Node *root)
{
	std::map<int, std::pair<int, int>> m;
	int minHD = INT_MAX;
	int maxHD = INT_MIN;
	int hd = 0;
	vector<int> bottomView;
	int height = 0;
	bottomView_util(root, hd, m, height, minHD, maxHD);
	for (int i = minHD; i <= maxHD; ++i) {
		bottomView.push_back(m[i].first);
	}
	return bottomView;
}

int main() {
	Node* root = new Node(3);
	root->left = new Node(8);
	root->left->right = new Node(11);
	root->left->left = new Node(13);
	root->left->left->right = new Node(14);
	root->right = new Node(9);
	root->right->right = new Node(10);

	vector<int> order = bottomView(root);
	for (auto el : order) {
		cout << el << " ";
	}
	cout << endl;
	return 0;
}





// void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
// {
// 	if (root == nullptr) {
// 		return;
// 	}
// 	if (key == root->data) {

// 		if (root->right) {
// 			Node*x = root;
// 			while (x->left != nullptr) {
// 				x = x->left;
// 			}
// 			suc = x;
// 		}
// 		if (root->left) {
// 			Node*x = root;
// 			while (x->right != nullptr) {
// 				x = x->right;
// 			}
// 			pre = x;
// 		}
// 		return;
// 	}
// 	if (key < root->data) {
// 		suc = root;
// 		findPreSuc(root->left, pre, suc, key);
// 	}
// 	else {
// 		pre = root;
// 		findPreSuc(root->right, pre, suc, key);
// 	}
// }

// void populateNext_util(struct node*root, struct node*pre) {
// 	if (root == nullptr) {
// 		return;
// 	}
// 	populateNext_util(root->right, root);
// 	pre->next = root;
// 	populateNext_util(root->left, root);

// }
// void populateNext(struct node* p)
// {
// 	node* pre = nullptr;
// 	populateNext_util(root, pre);
// }

// bool isBst_util(Node* root, Node* &pre) {
// 	if (root) {

// 		if (!isBst_util(root->left, pre)) {
// 			return false;
// 		}
// 		if (pre != nullptr && pre->data > root->data) {
// 			return false;
// 		}
// 		pre = root;
// 		if (isBst_util(root->right, pre)) {
// 			return false;
// 		}
// 	}
// 	return true;
// }
// bool isBST(Node* root) {
// 	Node* pre = nullptr;
// 	return isBst_util(root, pre);
// }

Node* LCA(Node *root, int n1, int n2)
{
	if (root == nullptr) {
		return nullptr;
	}
	// if (n1 < root->data && n2 > root->data || n1 > root->data && n2 < root->data) {
	// 	return root;
	// }
	// if (n1 == root->data || n2 == root->data) {
	// 	return root;
	// }
	if (n1 < root->data && n2 < root->data) {
		return LCA(root->left, n1, n2);
	}
	if (n1 > root->data && n2 > root->data) {
		return LCA(root->right, n1, n2);
	}
	return root;
}
int main() {
	struct Node *root = new Node(7);
	root->left     = new Node(2);
	root->right     = new Node(9);
	root->left->left = new Node(1);
	root->left->right = new Node(6);
	int n1 = 1;
	int n2 = 6;
	Node* lca = LCA(root, n1, n2);
	if (lca) {
		cout << root->data;
	}
	// cout << isBST(root);
}