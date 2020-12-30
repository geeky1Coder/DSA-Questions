//Trie Data structure
//Time Complexity Analysis:
//Insert and search costs O(key_length),
//However the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie
#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

class TrieNode {
public:
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};
TrieNode* getNode() {
	TrieNode *pNode =  new TrieNode;

	pNode->isEndOfWord = false;

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
		pcrawl = pcrawl->children[index];
	}
	pcrawl->isEndOfWord = true;
}
bool search(TrieNode *root, string key) {
	TrieNode*pcrawl = root;
	for (int i = 0; i < key.length(); ++i) {
		int index = key[i] - 'a';
		if (pcrawl->children[index] == NULL) {
			return false;
		}
		pcrawl = pcrawl->children[index];
	}
	return (pcrawl != NULL && pcrawl->isEndOfWord);
}

int main() {
	string keys[] = {"the", "a", "there",
	                 "answer", "any", "by",
	                 "bye", "their"
	                };
	int n = sizeof(keys) / sizeof(keys[0]);

	struct TrieNode *root = getNode();

	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	search(root, "the") ? cout << "Yes\n" :
	                           cout << "No\n";
	search(root, "these") ? cout << "Yes\n" :
	                             cout << "No\n";
	return 0;
}