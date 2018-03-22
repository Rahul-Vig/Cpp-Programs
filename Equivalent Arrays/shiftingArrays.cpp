#include <iostream>

using std::cout;
using std::endl;


void rightShift(int a[], int offset, int size){
  int temp; 
  for(int i = 0; i < offset; i++){
    temp = a[size-1];
    for(int j = size - 1; j > 0; j--){
      a[j] = a[j-1];
    }
    a[0] = temp;
  }
}

void leftShift(int a[], int offset, int size){
int temp;
  for(int i = 0; i < offset; i++){
    temp = a[0];
    for(int j = 0; j < size; j++){
      a[j] = a[j+1];
    }
    a[size-1] = temp;
  }
}


int main(){
  int a[] = {1, 2, 3, 4};
  for(int i = 0; i < 4; i++)
    cout << a[i] << ", ";

  cout << endl;

  rightShift(a, 2, 4);

  for(int i = 0; i < 4; i++)
    cout << a[i] << ", ";

  cout << endl;

  int b[] = {1, 2, 3, 4};
  for(int i = 0; i < 4; i++)
    cout << b[i] << ", ";

  cout << endl;

  leftShift(b, 2, 4);

  for(int i = 0; i < 4; i++)
    cout << b[i] << ", ";

  cout << endl;

  return 0;
}
