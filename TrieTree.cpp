#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

const int alphabetSize = 26;
class Node {
public:
	Node() {
		count = 0;
		child = new Node* [alphabetSize];
		for (int i = 0; i < alphabetSize; ++i) {
			child[i] = NULL;
		}
	}
	int getCount() {
		return count;
		;
	}
	void setCount(int newNumber) {
		count = newNumber;
		;
	}
	Node* getChild(int index) {
		return child[index];
		;
	}
	void setChild(Node* newChild, int index) {
		child[index] = newChild;
		return;
	}
private:
	Node** child;
	char value;
	int count;
};

class TrieTree {
public:
	TrieTree() {
		root = NULL;
	}
	void add(std::string word) {
		Node* curr = root;
		for (int i = 0; i < (int)word.size(); ++i) {
			if (curr->getChild(word[i]-'a') == NULL) {
				Node* tmp = new Node;
				curr->setChild(tmp, int(word[i]-'a'));
			}
			curr = curr->getChild(word[i]-'a');
		}
		curr->setCount(curr->getCount() + 1);
		return;
	}
	void del(std::string word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); ++i) {
			if (curr->getChild(word[i]-'a') == NULL) {
				return;
			}
			curr = curr->getChild(word[i]-'a');
		}
		curr->setCount(std::max(curr->getCount()-1, 0));
		return;
	}
	int count(std::string word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); ++i) {
			if (curr->getChild(word[i]-'a') == NULL) {
				return;
			}
			curr = curr->getChild(word[i]-'a');
		}
		return curr->getCount();	
	}
	Node* getRoot() {
		return root;
		;
	}
	bool isEmpty() {
		return ((root==NULL)?true:false);
		;
	}
private:
	Node* root;
};