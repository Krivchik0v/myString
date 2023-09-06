#include <iostream>
using namespace std;

class MyString {
private:
	char* arrayStrings;
	int size;
public:
	MyString() {
		arrayStrings = nullptr;
		size = 0;
	}
	void operator =(const char arr[]) {

		if (arrayStrings != nullptr) {
			delete[] arrayStrings;
		}
		size = strlen(arr);
		arrayStrings = new char[size + 1];
		for (int i = 0; i < size; i++) {
			arrayStrings[i] = arr[i];
		}
		arrayStrings[size] = '\0';
	}

	MyString& operator =(const MyString& str) {
		if (this == &str) {
			return *this;
		}

		if (arrayStrings != nullptr) {
			delete[] arrayStrings;
		}
		size = str.size;
		arrayStrings = new char[size + 1];
		for (int i = 0; i < size; i++) {
			arrayStrings[i] = str.arrayStrings[i];
		}
		arrayStrings[size] = '\0';
		return *this;
	}
	MyString operator +(const char arr[]) {
		MyString tempStr;
		char* tempArr = new char[size];

		for (int i = 0; i < size; i++) {
			tempArr[i] = arrayStrings[i];
		}
		int oldsize = size;

		int newSize = strlen(arr);


		tempStr.arrayStrings = new char[oldsize + newSize + 1];
		for (int i = 0; i < oldsize; i++) {
			tempStr.arrayStrings[i] = tempArr[i];
		}

		for (int i = 0; i < newSize; i++) {
			tempStr.arrayStrings[oldsize + i] = arr[i];
		}
		tempStr.arrayStrings[oldsize + newSize] = '\0';
		tempStr.size = oldsize + newSize;
		delete[] tempArr;
		return tempStr;
	}



	MyString operator +(char character) {
		MyString tempStr;
		char* tempArr = new char[size];

		for (int i = 0; i < size; i++) {
			tempArr[i] = arrayStrings[i];
		}
		int oldsize = size;

		int newSize = 1;

		tempStr.arrayStrings = new char[oldsize + newSize + 1];
		for (int i = 0; i < oldsize; i++) {
			tempStr.arrayStrings[i] = tempArr[i];
		}


		tempStr.arrayStrings[oldsize] = character;
		tempStr.arrayStrings[oldsize + newSize] = '\0';
		tempStr.size = oldsize + newSize;
		delete[] tempArr;
		return tempStr;
	}

	MyString& operator +(const MyString& arr) {

		char* tempArr = new char[size];

		for (int i = 0; i < size; i++) {
			tempArr[i] = arrayStrings[i];
		}
		int oldsize = size;

		int newSize = strlen(arr.arrayStrings);

		arrayStrings = new char[oldsize + newSize + 1];
		for (int i = 0; i < oldsize; i++) {
			arrayStrings[i] = tempArr[i];
		}

		for (int i = 0; i < newSize; i++) {
			arrayStrings[oldsize + i] = arr.arrayStrings[i];
		}
		arrayStrings[oldsize + newSize] = '\0';
		size = oldsize + newSize;
		delete[] tempArr;


		return *this;
	}
	void operator +=(const char arr[]) {

		char* tempArr = new char[size];

		for (int i = 0; i < size; i++) {
			tempArr[i] = arrayStrings[i];
		}
		int oldsize = size;

		size = strlen(arr);

		arrayStrings = new char[oldsize + size + 1];
		for (int i = 0; i < oldsize; i++) {
			arrayStrings[i] = tempArr[i];
		}

		for (int i = 0; i < size; i++) {
			arrayStrings[oldsize + i] = arr[i];
		}
		arrayStrings[oldsize + size] = '\0';
		size = oldsize + size;
		delete[] tempArr;
	}
	void operator +=(char character) {

		char* tempArr = new char[size];

		for (int i = 0; i < size; i++) {
			tempArr[i] = arrayStrings[i];
		}
		int oldsize = size;
		size = 1;

		arrayStrings = new char[oldsize + size + 1];
		for (int i = 0; i < oldsize; i++) {
			arrayStrings[i] = tempArr[i];
		}
		arrayStrings[oldsize] = character;
		arrayStrings[oldsize + size] = '\0';
		size = oldsize + size;
		delete[] tempArr;
	}

	MyString(const char arr[]) {

		size = strlen(arr);
		arrayStrings = new char[size + 1];
		for (int i = 0; i < size; i++) {
			arrayStrings[i] = arr[i];
		}
		arrayStrings[size] = '\0';
	}
	~MyString() {
		if (arrayStrings != nullptr) {
			delete[] arrayStrings;
			arrayStrings = nullptr;
		}
	}
	char& operator[](int index) {
		return arrayStrings[index];
	}

	friend ostream& operator <<(ostream& os, MyString& obj);
};

ostream& operator <<(ostream& os, MyString& obj) {
	return os << obj.arrayStrings;
}

void main() {
	string a;
	a = "a";
	a = a + "a";
	MyString ad;
	ad += "Ky lol";
	cout << ad << endl;
	ad[0] = 'H';
	cout << ad << endl;

}