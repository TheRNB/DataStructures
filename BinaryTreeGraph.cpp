#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename DataType>
class BinaryTree {
public:
	BinaryTree() {
		children = NULL;
		weights = NULL;
		sizee = 0;
	}
	int getLeft (const int &index) {
		if (index >= sizee)
			throw std::invalid_argument("index out of bound");
		return children[index][0];
	}
	int getRight (const int &index) {
		if (index >= sizee)
			throw std::invalid_argument("index out of bound");
		return children[index][1];
	}
	void getInput () {
		cin >> sizee;

		children = new int* [sizee];
		for (int i = 0; i < sizee; ++i) {
			children[i] = new int* [2];
			children[i][0] = children[i][1] = -1;
		}

		int father;
		for (int i = 1; i < sizee; ++i) {
			cin >> father;
			if (children[father][0] == -1)
				children[father][0] = i;
			else
				children[father][1] = i;
		}

		weights = new int [sizee];
		for (int i = 0; i < sizee; ++i)
			cin >> weights[i];

		return;
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
			children[i][0] = assignee.getLeft(i);
			children[i][1] = assignee.getRight(i);
		}
	}
private:
	DataType* weights;
	int** children;
	int sizee;
};