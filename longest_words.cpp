#include <iostream>
#include <string>

using namespace std;

int SearchMaxLength(string);
int SearchSizeofArray(string, int);
void SearchIndeces(string, int *, int);
void outputString(string, int *, int, int);

int main()
{
	string str;
	cout << "Input your string: ";
	getline(cin, str);
	
	int maxLength = SearchMaxLength(str);
	int counter_2 = SearchSizeofArray(str, maxLength);
	int* Array = new int[counter_2];
	SearchIndeces(str, Array, maxLength);
	cout << "The longest words are: ";
	outputString(str, Array, counter_2, maxLength);
	
	delete[] Array;
}

int SearchMaxLength(string str) {
	int counter = 0;
	int maxLength = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			counter++;
		}
		if (!(isalpha(str[i]))) {
			counter = 0;
		}
		if (counter > maxLength) {
			maxLength = counter;
		}
	}
	return maxLength;
}

int SearchSizeofArray(string str, int maxLength) {
	int counter = 0;
	int counter_2 = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			counter++;
		}
		if (!(isalpha(str[i]))) {
			counter = 0;
		}
		if (counter == maxLength) {
			counter_2++;
		}
	}
	return counter_2;
}

void SearchIndeces(string str, int *Array, int maxLength) {
	int counter = 0;
	int counter_3 = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			counter++;
		}
		if (!(isalpha(str[i]))) {
			counter = 0;
		}
		if (counter == maxLength) {
			Array[counter_3] = i + 1;
			counter_3++;
		}
	}
}

void outputString(string str, int *Array, int counter_2, int maxLength) {
	string strExp;
	for (int i = 0; i < counter_2; i++) {
		strExp += str.substr(Array[i] - maxLength, maxLength) + " ";
	}
	cout << strExp << endl;
}
