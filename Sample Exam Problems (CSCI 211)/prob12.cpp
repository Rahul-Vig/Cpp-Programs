#include <iostream>

using namespace std;

typedef bool (*TEST)(int);

bool is_even(int n){
  return n%2 == 0;
}

bool is_odd(int n){
  return n%2 == 1;
}

int* return_matches(int a[], int& size, TEST t){
  int temp_size = 0;
  for(int i = 0;  i < size; i++){
    if(t(a[i])){
      temp_size++;
    }
  }

  int* new_a = new int[temp_size];

  int j = 0;
  for(int i = 0; i < size; i++){
    if(t(a[i])){
      new_a[j++] = a[i];
    }
  }

  size = temp_size;
  return new_a;

}

void print(int a[], int size){
  for(int i = 0; i < size; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}


int main(){
  int size = 5;
  int a[size] = {1, 2, 3, 4, 5};

  int* new_a = return_matches(a, size, is_odd);

  print(new_a, size);

  size = 5; 
  int* new_b = return_matches(a, size, is_even);

  print(new_b, size);


  delete[] new_a;
  delete[] new_b;
}
