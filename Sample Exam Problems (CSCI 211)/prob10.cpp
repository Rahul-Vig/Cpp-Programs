#include <iostream>

using namespace std;

static int size;

int* return_an_array(int n){
  if(n == 0) return 0;
  int temp = n;
  size =  0;

  while(temp > 0){
    size++;
    temp /= 10;
  }

  cout << size << endl;

  int* arr = new int[size];

  for(int i = size - 1; i >= 0; i--){
    arr[i] = n % 10;
    n /= 10;
  }

  return arr;

}

int main(){
  int* a = return_an_array(100);

  for(int i = 0; i < size; i++){
    cout << a[i] << " ";
  }

  cout << endl;

  delete[] a;

  int* b = return_an_array(1000);

  for(int i = 0; i < size; i++){
    cout << b[i] << " ";
  }

  cout << endl;

  delete[] b;
}
