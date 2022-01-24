#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename DataType>
class BinaryTree {
public:
	BinaryTree() {
		treeNodes = NULL;
		sizee = 0;
	}
	DataType &operator[] (const int &index) {
		if (index >= sizee)
			throw std::invalid_argument("index out of bound");
		return treeNodes[index];
	}
	void createWithSize (int newSize) {
		sizee = newSize;
		treeNodes = new DataType [sizee];
	}
	void createWithHeight (int height) {
		sizee = (1 << height) - 1;
		treeNodes = new DataType [sizee];
	}
	void getInput () {
		for (int i = 0; i < sizee; ++i) {
			std::cin >> treeNodes[i];
		}
	}
	bool isEmpty() {
		return ((sizee==0)? true : false);
		;
	}
	bool isRoot (int index) {
		return ((index==0)? true : false);
		;	
	}
	int size() {
		return sizee;
		;
	}
	void operator= (const BinaryTree<DataType> &assignee) {
		sizee = assignee.size();
		treeNodes = new DataType [sizee];
		for (int i = 0; i < sizee; ++i) {
			treeNodes[i] = assignee[i];
		}
	}
private:
	DataType* treeNodes;
	int sizee;
};



/*
void inOrderTraverse() {
		bool* isPassed = new bool [sizee];
		LinkedList<int> traverseStack;
		traverseStack.push_front(0);
		int root;
		while(traverseStack.isEmpty() == false) {
			root = traverseStack.begin()->getValue();
			isPassed[root] = true;
			if (2 * root + 1 < sizee and isPassed[2 * root + 1] == false) {
				traverseStack.push_front(2 * root + 1);
			} else {
				if (treeNodes[root] != -1)
					cout << treeNodes[root] << " ";
				traverseStack.pop_front();
				if (2 * root + 2 < sizee and isPassed[2 * root + 2] == false) {
					traverseStack.push_front(2 * root + 2);
				}
			}
		}
	}/*