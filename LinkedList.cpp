#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename DataType>
class Node {
public:
	Node(DataType startingValue) {
		next = NULL;
		value = startingValue;
	}
	void setValue (DataType newValue) {
		value = newValue;
		;
	}
	void setNext (Node<DataType>* newNext) {
		next = newNext;
		;
	}
	DataType getValue() {
		return value;
		;
	}
	Node<DataType>* getNext() {
		return next;
		;
	}
	void operator= (const Node<DataType> &assignee) { 
		value = assignee->getValue();
		;
	}
private:
	Node<DataType>* next;
	DataType value;
};

template <typename DataType>
class LinkedList {
public:
	LinkedList() {
		beginn = NULL;
		endd = NULL;
		sizee = 0;
	}
	Node<DataType> &operator[] (int index) {
		if (index >= sizee)
			throw std::invalid_argument("index out of bound");

		Node<DataType>* currVertex = beginn;
		while (0 < index) {
			currVertex = currVertex->getNext();
			index--;
		}
		return currVertex;
	}
	void push_back(DataType newNodeValue) {
		Node<DataType>* newNode = new Node<DataType>(newNodeValue);
		if (endd == NULL) {
			beginn = endd = newNode;
		} else {
			endd->setNext(newNode);
			endd = newNode;	
		}
		sizee++;
	}
	void push_front(DataType newNodeValue) {
		Node<DataType>* newNode = new Node<DataType>(newNodeValue);
		if (beginn == NULL) {
			beginn = endd = newNode;
		} else {
			newNode->setNext(beginn);
			beginn = newNode;	
		}
		sizee++;
	}
	DataType pop_back() {
		Node<DataType> *previousVertex = NULL;
		Node<DataType> *currVertex = beginn;
		if (currVertex == NULL)
			throw std::invalid_argument("list is empty");
		while (currVertex->getNext() != NULL) {
			previousVertex = currVertex;
			currVertex = currVertex->getNext();
		}
		if (endd == beginn) {
			beginn = NULL;
		}
		endd = previousVertex;
		sizee--;
		DataType returnValue = currVertex->getValue();
		delete currVertex;
		return returnValue;
	}
	DataType pop_front() {
		Node<DataType>* result = beginn;
		if (result == NULL)
			throw std::invalid_argument("list is empty");
		if (endd == beginn) {
			endd = NULL;
		}
		beginn = beginn->getNext();
		sizee--;
		DataType returnValue = result->getValue();
		delete result;
		return returnValue;
	}
	Node<DataType>* begin() {
		return beginn;
		;
	}
	Node<DataType>* end() {
		return endd;
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
	void operator= (const LinkedList<DataType> &assignee) { 
		Node<DataType>* assigneeNode = assignee.begin();
		while (assigneeNode->getNext() != NULL) {
			if (beginn == NULL) {
				Node<DataType> newNode = new Node<DataType>(assigneeNode->getValue());
				beginn = endd = newNode; 
			} else {
				Node<DataType> newNode = new Node<DataType>(assigneeNode->getValue());
				endd->setNext(newNode);
				endd = newNode;
			}
			assigneeNode = assigneeNode->getNext();
		}
		sizee = assignee.size();
	}
private:
	Node<DataType>* beginn;
	Node<DataType>* endd;
	int sizee;
};