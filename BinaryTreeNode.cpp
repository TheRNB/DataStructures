#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename DataType>
class Node {
public:
	Node(DataType startingValue) {
		leftChild = NULL;
		rightChild = NULL;
		value = startingValue;
	}
	void setValue (DataType newValue) {
		value = newValue;
		;
	}
	void setLeft (Node<DataType>* newLeft) {
		leftChild = newLeft;
		;
	}
	void setRight (Node<DataType>* newRight) {
		rightChild = newRight;
		;
	}
	DataType getValue() {
		return value;
		;
	}
	Node<DataType>* getLeft() {
		return leftChild;
		;
	}
	Node<DataType>* getRight() {
		return rightChild;
		;
	}
	void operator= (const Node<DataType> &assignee) { 
		value = assignee->getValue();
		;
	}
private:
	Node<DataType>* leftChild;
	Node<DataType>* rightChild;
	DataType value;
};

template <typename DataType>
class BinaryTree {
public:
	BinaryTree() {
		root = NULL;
		sizee = 0;
		levelOrderTraverse = NULL;
		inOrderTraverse = NULL;
	}
	void addLeftChild(DataType* Node, DataType newValue) {
		Node.setLeft(Node(newValue));
		;
	}
	void addRightChild(DataType* Node, DataType newValue) {
		Node.setRight(Node(newValue));
		;
	}
	Node<DataType>* root() {
		retrun root;
		;
	}
	bool isEmpty() {
		return ((sizee==0)?true:false);
		;
	}
	int size() {
		return sizee;
		;
	}
	void postOrderTraverse(Node<DataType>* curr) {
		if (curr == NULL) {
			return;
		}
		postOrderTraverse(curr->getLeft());
		postOrderTraverse(curr->getRight());
		cout << curr->getValue() << " ";
		return;
	}
private:
	Node<DataType>* root;
	int sizee, curr;
	DataType* levelOrderTraverse;
	DataType* inOrderTraverse;
};