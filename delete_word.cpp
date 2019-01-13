#include <iostream>
#include <string>

using namespace std;

int searchIndex(string);
void FillArray(string, int *, int);
int searchNumberOfWords(string);
void searchIndecesOfWords(string, int *);
void outputArray(int *, int);

int main() {
	string str;
	cout << "Input your string: "; getline(cin, str);
	int word;
	cout << "Input which word u wanna delete: "; cin >> word;
	int newWord = (2 * word) - 1;
	int size = searchIndex(str);
	if (size > 0) {
		int *Array = new int[size];
		FillArray(str, Array, size);
		for (int i = 0; i < size; i++) {
			str.erase(Array[i], 1);
			Array[i + 1]--;
		}
		delete[] Array;
	}
	cout << str << endl;
	int NumberOfWords = searchNumberOfWords(str);
	cout << "Number of words: " << NumberOfWords << endl;
	int *Array_1 = new int[NumberOfWords * 2];
	searchIndecesOfWords(str, Array_1);
	outputArray(Array_1, NumberOfWords * 2);
	str.erase(Array_1[newWord - 1] - Array_1[newWord] + 1, Array_1[newWord]);
	int size_1 = searchIndex(str);
	if (size_1 > 0) {
		int *Array_2 = new int[size_1];
		FillArray(str, Array_2, size_1);
		for (int i = 0; i < size_1; i++) {
			str.erase(Array_2[i], 1);
			Array_2[i + 1]--;
		}
		delete[] Array_2;
	}
	cout << str << endl;
	delete[] Array_1;
}

void outputArray(int *Array, int size) {
	int count = 1;
	for (int i = 0; i < size; i++) {
		if (i % 2 == 1) {
			cout << "Length of " << count << " word: " << Array[i] << endl;
			count++;
		}
	}
}

int searchIndex(string str) {
	int count = 0;
	int index = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isspace(str[i])) {
			count++;
		}
		if (!(isspace(str[i]))) {
			count = 0;
		}
		if (count > 1) {
			index++;
		}
	}
	return index;
}

void FillArray(string str, int *Array, int size) {
	int count = 0;
	int index = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isspace(str[i])) {
			count++;
		}
		if (!(isspace(str[i]))) {
			count = 0;
		}
		if (count > 1) {
			Array[index] = i;
			index++;
		}
	}
}

int searchNumberOfWords(string str) {
	int counter = 0;
	int NumberOfWords = 0;
	for (int i = 0; i < str.length(); i++) {
		if (counter == 0) {
			NumberOfWords++;
		}
		if (isalpha(str[i])) {
			counter++;
		}
		if (!(isalpha(str[i]))) {
			counter = 0;
		}
	}
	return NumberOfWords;
}

void searchIndecesOfWords(string str, int *Array) {
	int LengthOfWord = 0;
	int index = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			LengthOfWord++;
			Array[index] = i;
			Array[index + 1] = LengthOfWord;
		}
		if (!(isalpha(str[i]))) {
			LengthOfWord = 0;
			index += 2;
		}
	}
}
