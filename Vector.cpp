#include <cstddef>

template <typename DataType>
class Vector {
public:
	Vector() {
		arraySize = 2;
		currIterator = 0;
		array = new DataType [arraySize];
	}
	~Vector() {
		delete[] array;
	}
	void push_back(DataType newValue) {
		if (currIterator < arraySize - 1) {
			currIterator++;
			array[currIterator] = newValue;
		} else {
			arraySize <<= 1;
			DataType* tmp = new DataType [arraySize];
			for (int i = 0; i <= currIterator; ++i)
				tmp[i] = array[i];
			swap(array, tmp);
			delete[] tmp;
			currIterator++;
			array[currIterator] = newValue;
		}
		return;
	}
	DataType pop_back() {
		if (currIterator == 0) {
			return NULL;
		}
		else if (currIterator <= 1 or  currIterator > arraySize/2+1) {
			currIterator--;
			return array[currIterator+1];
		} else {
			arraySize >>= 1;
			DataType* tmp = new DataType [arraySize];
			DataType value = array[currIterator];
			for (int i = 0; i < currIterator; ++i)
				tmp[i] = array[i];
			swap(array, tmp);
			delete[] tmp;
			currIterator--;
			return value;
		}
	}
	DataType* begin() {
		return array;
		;
	}
	DataType* end() {
		return array+arraySize;
		;
	}
	int size() {
		return currIterator;
		;
	}
	int max_size() {
		return arraySize;
		;
	}
	bool empty() {
		return ((currIterator == 0)? true : false);
		;
	}
	DataType operator[](int index) {
		return array[index];
		;
	}
	DataType at(int index) {
		return array[index];
		;
	}
	DataType front() {
		return array[0];
		;
	}
	DataType back() {
		return array[currIterator];
		;
	}
private:
	DataType* array;
	int arraySize, currIterator;
};