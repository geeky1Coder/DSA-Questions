// Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

// Examples:

// Input: arr[] = {"zebra", "dog", "duck", "dove"}
// Output: dog, dov, du, z
// Explanation: dog => dog
//              dove = dov
//              duck = du
//              z   => zebra

// Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
// Output: geeksf, geeksg, geeksq}

#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

class TrieNode {
public:
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
	int frequency;
};

TrieNode* getNode() {
	TrieNode *pNode =  new TrieNode;

	pNode->isEndOfWord = false;
	pNode->frequency = 1;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(TrieNode *root, string key) {
	TrieNode *pcrawl = root;

	for (int i = 0; i < key.length(); ++i) {
		int index = key[i] - 'a';
		if (pcrawl->children[index] == NULL) {
			pcrawl->children[index] = getNode();
		}
		else {
			pcrawl->children[index]->frequency += 1;
		}
		pcrawl = pcrawl->children[index];
	}
	pcrawl->isEndOfWord = true;
}
//Simple dfs

void findPrefix_util(TrieNode* root, int str[], int index) {
	if (root == NULL) {
		return;
	}
	if (root->frequency == 1) {
		str[index] = -1;
		int i = 0;
		while (str[i] != -1) {
			cout << str[i] << " ";
			i++;
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		if (root->children[i] != NULL) {

			str[index] = i;
			findPrefix_util(root->children[i], str, index + 1);
		}
	}
}
void findPrefixes(string arr[], int n) {
	TrieNode* root = getNode();
	//Insert
	root->frequency = 0;
	for (int i = 0; i < n; ++i) {
		insert(root, arr[i]);
	}

	int prefixes[500];
	findPrefix_util(root, prefixes, 0);

}

int main() {
	string arr[] = {"zebra", "dog", "duck", "dove"};
	int n = sizeof(arr) / sizeof(arr[0]);
	findPrefixes(arr, n);
	return 0;
}
