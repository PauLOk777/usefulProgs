#include <iostream>
#include <string>

using namespace std;

int searchIndex(string);
void FillArray(string, int *, int);

int main() {
  string str;
  cout << "Input your string: "; getline(cin, str);
  int size = searchIndex(str);
  int *Array = new int[size];
  FillArray(str, Array, size);
  for(int i = 0; i < size; i++){
    str.erase(Array[i], 1);
    Array[i+1]--;
  }
  cout << str << endl;
  delete[] Array;
}

int searchIndex(string str){
  int count = 0;
  int index = 0;
  for(int i =0; i < str.length(); i++){
    if(isspace(str[i])){
      count++;
    }
    if(!(isspace(str[i]))){
      count = 0;
    }
    if(count > 1){
      index++;
    }
  }
  return index;
}

void FillArray(string str, int *Array, int size){
  int count = 0;
  int index = 0;
  for(int i =0; i < str.length(); i++){
    if(isspace(str[i])){
      count++;
    }
    if(!(isspace(str[i]))){
      count = 0;
    }
    if(count > 1){
      Array[index] = i;
      index++;
    }
  }
}
