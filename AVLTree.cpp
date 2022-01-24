#include <iostream>

using namespace std;

template <typename DataType>
class Node {
public:
	Node(DataType startingValue) {
		leftChild = NULL;
		rightChild = NULL;
		value = startingValue;
		balance = 0;
		size = 0;
		amount = 1;
		height = 0;
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
	void setSize(int newSize) {
		size = newSize;
		;
	}
	bool isBalanced() {
		if (balance < -1 or balance > 1)
			return false;
		else 
			return true;
	}
	void addAmount() {
		amount++;
		;
	}
	void setHeight(int val) {
		height = val;
		return;
	}
	bool setBalance(int val) {
		balance = val;
		return isBalanced();
	}
	int getBalance() {
		return balance;
		;
	}
	int getSize() {
		return size;
		;
	}
	int getAmount() {
		return amount;
		;
	}
	int getHeight() {
		return height;
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
	int balance, size, amount, height;
};

template <typename DataType>
class AVL {
public:
	AVL() {
		root = NULL;
	}
	void LLRotate(Node<DataType>* APar, bool Direction, bool isPar = false) {
		/*
		         A                    B
		        / \                 /   \
		       B  Ar               C     A
		      / \       ===>      / \   / \
		     C   Br              Cl Cr Br Ar
		    / \
		   Cl Cr
		*/
		Node<DataType>* A;
		if (!isPar) {
			if (Direction == false)	A = APar->getLeft(); 
			else A = APar->getRight();
		} else {
			A = APar;
		}

		Node<DataType>* B = A->getLeft();
		Node<DataType>* C = B->getLeft();
		A->setLeft(B->getRight());
		B->setRight(A);
		
		A->setSize((A->getRight()!=NULL?A->getRight()->getSize():0) + (A->getLeft()!=NULL?A->getLeft()->getSize():0)+1);
		B->setSize(A->getSize() + C->getSize()+1);
		
		A->setBalance((A->getLeft()!=NULL?A->getLeft()->getHeight():-1) - (A->getRight()!=NULL?A->getRight()->getHeight():-1));
		B->setBalance(C->getBalance() - A->getBalance());

		A->setHeight(max((A->getLeft() != NULL? A->getLeft()->getHeight(): -1), (A->getRight() != NULL? A->getRight()->getHeight(): -1)) + 1);
		B->setHeight(max(A->getHeight(), C->getHeight())+1);

		if (isPar) return;
		if (Direction == false)	APar->setLeft(B); else APar->setRight(B);
		return;
	}
	void RRRotate(Node<DataType>* APar, bool Direction, bool isPar = false) {	
		/*
		         A                    B
		        / \                 /   \
		       Al  B               A     C
		          / \       ===>  / \   / \
		         Bl  C           Al Bl Cl Cr
		            / \
		           Cl Cr
		*/
		Node<DataType>* A;
		if (!isPar) {
			if (Direction == false)	A = APar->getLeft(); 
			else A = APar->getRight();
		} else {
			A = APar;
		}
		
		Node<DataType>* B = A->getRight();
		Node<DataType>* C = B->getRight();
		A->setRight(B->getLeft());
		B->setLeft(A);
		
		A->setSize((A->getRight()!=NULL?A->getRight()->getSize():0) + (A->getLeft()!=NULL?A->getLeft()->getSize():0)+1);
		B->setSize(A->getSize() + C->getSize()+1);
		
		A->setBalance((A->getLeft()!=NULL?A->getLeft()->getHeight():-1) - (A->getRight()!=NULL?A->getRight()->getHeight():-1));
		B->setBalance(A->getBalance() - C->getBalance());

		A->setHeight(max((A->getLeft() != NULL? A->getLeft()->getHeight(): -1), (A->getRight() != NULL? A->getRight()->getHeight(): -1)) + 1);
		B->setHeight(max(A->getHeight(), C->getHeight())+1);

		if (isPar) return;
		if (Direction == false)	APar->setLeft(B); else APar->setRight(B);
		return;	
	}
	void LRRotate(Node<DataType>* APar, bool Direction, bool isPar = false) {
		/*
		         A                    C
		        / \                 /   \
		       B  Ar               B     A
		      / \       ===>      / \   / \
		     Bl  C               Bl Cl Cr Ar
		        / \
		       Cl Cr
		*/
		Node<DataType>* A;
		if (!isPar) {
			if (Direction == false)	A = APar->getLeft(); 
			else A = APar->getRight();
		} else {
			A = APar;
		}
		
		Node<DataType>* B = A->getLeft();
		Node<DataType>* C = B->getRight();
		A->setLeft(C->getRight());
		B->setRight(C->getLeft());
		C->setLeft(B);
		C->setRight(A);
		
		A->setSize((A->getRight()!=NULL?A->getRight()->getSize():0) + (A->getLeft()!=NULL?A->getLeft()->getSize():0)+1);
		B->setSize((B->getRight()!=NULL?B->getRight()->getSize():0) + (B->getLeft()!=NULL?B->getLeft()->getSize():0)+1);
		C->setSize(B->getSize() + A->getSize());
		
		A->setBalance((A->getLeft()!=NULL?A->getLeft()->getHeight():-1) - (A->getRight()!=NULL?A->getRight()->getHeight():-1));
		B->setBalance((B->getLeft()!=NULL?B->getLeft()->getHeight():-1) - (B->getRight()!=NULL?B->getRight()->getHeight():-1));
		C->setBalance(B->getBalance() - A->getBalance());

		A->setHeight(max((A->getLeft() != NULL? A->getLeft()->getHeight(): -1), (A->getRight() != NULL? A->getRight()->getHeight(): -1)) + 1);
		B->setHeight(max((B->getLeft() != NULL? B->getLeft()->getHeight(): -1), (B->getRight() != NULL? B->getRight()->getHeight(): -1)) + 1);
		C->setHeight(max(A->getHeight(), B->getHeight())+1);

		if (isPar) return;
		if (Direction == false)	APar->setLeft(C); else APar->setRight(C);
		return;
	}
	void RLRotate(Node<DataType>* APar, bool Direction, bool isPar = false) {
		/*
		         A                    C
		        / \                 /   \
		       Al  B               A     B
		          / \       ===>  / \   / \
		         C  Br           Al Cl Cr Br
		        / \
		       Cl Cr
		*/
		Node<DataType>* A;
		if (!isPar) {
			if (Direction == false)	A = APar->getLeft(); 
			else A = APar->getRight();
		} else {
			A = APar;
		}
		
		Node<DataType>* B = A->getRight();
		Node<DataType>* C = B->getLeft();
		A->setRight(C->getLeft());
		B->setLeft(C->getRight());
		C->setLeft(A);
		C->setRight(B);
		
		A->setSize((A->getRight()!=NULL?A->getRight()->getSize():0) + (A->getLeft()!=NULL?A->getLeft()->getSize():0)+1);
		B->setSize((B->getRight()!=NULL?B->getRight()->getSize():0) + (B->getLeft()!=NULL?B->getLeft()->getSize():0)+1);
		C->setSize(A->getSize() + B->getSize());
		
		A->setBalance((A->getLeft()!=NULL?A->getLeft()->getHeight():-1) - (A->getRight()!=NULL?A->getRight()->getHeight():-1));
		B->setBalance((B->getLeft()!=NULL?B->getLeft()->getHeight():-1) - (B->getRight()!=NULL?B->getRight()->getHeight():-1));
		C->setBalance(A->getBalance() - B->getBalance());

		A->setHeight(max((A->getLeft() != NULL? A->getLeft()->getHeight(): -1), (A->getRight() != NULL? A->getRight()->getHeight(): -1)) + 1);
		B->setHeight(max((B->getLeft() != NULL? B->getLeft()->getHeight(): -1), (B->getRight() != NULL? B->getRight()->getHeight(): -1)) + 1);
		C->setHeight(max(B->getHeight(), A->getHeight())+1);

		if (isPar) return;
		if (Direction == false)	APar->setLeft(C); else APar->setRight(C);
		return;	
	}
	void add(DataType newValue, Node<DataType>* curr) {
		curr->setSize(curr->getSize() + 1);
		if (newValue == curr->getValue()) {
			curr->addAmount();
			return;
		} else if (newValue < curr->getValue()) {
			if (curr->getLeft() == NULL) {
				Node<DataType>* newNode = new Node<DataType>(newValue);
				curr->setLeft(newNode);
			} else {
				add(newValue, curr->getLeft());
			}
		} else {
			if (curr->getRight() == NULL) {
				Node<DataType>* newNode = new Node<DataType>(newValue);
				curr->setRight(newNode);
			} else {
				add(newValue, curr->getRight());
			}
		}
		curr->setHeight(max((curr->getLeft() != NULL? curr->getLeft()->getHeight(): -1), (curr->getRight() != NULL? curr->getRight()->getHeight(): -1)) + 1);
		curr->setBalance((curr->getLeft() != NULL? curr->getLeft()->getHeight(): -1) - (curr->getRight() != NULL? curr->getRight()->getHeight(): -1));
		
		if (curr->getLeft() != NULL and curr->getLeft()->isBalanced() == false) {
			if (curr->getLeft()->getBalance() > 0) {
				if (curr->getLeft()->getLeft()->getBalance() > 0) {
					LLRotate(curr, false);
				} else {
					LRRotate(curr, false);
				}
			} else {
				if (curr->getLeft()->getRight()->getBalance() > 0) {
					RLRotate(curr, false);
				} else {
					RRRotate(curr, false);
				}
			}

		}
		if (curr->getRight() != NULL and curr->getRight()->isBalanced() == false) {
			if (curr->getRight()->getBalance() > 0) {
				if (curr->getRight()->getLeft()->getBalance() > 0) {
					LLRotate(curr, true);
				} else {
					LRRotate(curr, true);
				}
			} else {
				if (curr->getRight()->getRight()->getBalance() > 0) {
					RLRotate(curr, true);
				} else {
					RRRotate(curr, true);
				}
			}
		}
		return;
	}
	void addNode(DataType newValue) {
		if (root == NULL) {
			root = new Node<DataType>(newValue);
			return;
		}

		add(newValue, root);
		root->setHeight(max((root->getLeft() != NULL? root->getLeft()->getHeight(): -1), (root->getRight() != NULL? root->getRight()->getHeight(): -1)) + 1);
		root->setBalance((root->getLeft() != NULL? root->getLeft()->getHeight(): -1) - (root->getRight() != NULL? root->getRight()->getHeight(): -1));
		if (root->isBalanced()) return;
		if (root->getBalance() > 0) {
			Node<DataType>* currRoot = root;
			if (root->getLeft()->getBalance() > 0) {
				root = root->getLeft();
				LLRotate(currRoot, true, true);
			} else {
				root = root->getLeft()->getRight();
				LRRotate(currRoot, true, true);
			}
		} else {
			Node<DataType>* currRoot = root;
			if (root->getRight()->getBalance() > 0) {
				root = root->getRight()->getLeft();
				RLRotate(currRoot, true, true);
			} else {
				root = root->getRight();
				RRRotate(currRoot, true, true);
			}
		}
		
		return;
	}
	bool isEmpty() {
		return ((root==NULL)?true:false);
		;
	}
	int size() {
		return root.getSize() + 1;
		;
	}
	void preOrderTraverse(Node<DataType>* curr) {
		if (curr == NULL) {
			return;
		}
		cout << curr->getValue() << " " << flush;
		preOrderTraverse(curr->getLeft());
		preOrderTraverse(curr->getRight());
		return;
	}
	Node<DataType>* getRoot() {
		return root;
		;
	}
private:
	Node<DataType>* root;
};
