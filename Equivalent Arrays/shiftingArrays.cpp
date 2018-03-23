//This program allows you to shift the elements of an array right or left by a specified offset

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void rightShift(int a[], int size){ //func. to shift array to the right;
  int temp; //we need this to store the final value
  int offset; //will determine offset by taking user input
  cin >> offset;
  for(int i = 0; i < offset; i++){ //outer for loop: repeats the single shift until offset is reached
    temp = a[size-1]; //store final value
    for(int j = size - 1; j > 0; j--){ //shifts all elements to the right one
      a[j] = a[j-1];
    }
    a[0] = temp; //finally store the temp entry  in the intial entry.
  }
}

void leftShift(int a[], int size){
int temp;
int offset;
cin >> offset;

  for(int i = 0; i < offset; i++){
    temp = a[0]; //for the left shift we want to store the first value instead of last
    for(int j = 0; j < size; j++){  //now we want to move everything to the left one
      a[j] = a[j+1]; //moves everything to the left one
    }
    a[size-1] = temp; //finally assign temp (initial position) to the final position to
  }
}

void printArr(int a[], int size){ //simply prints the array
  for(int i = 0; i < size; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

int main(){
  int a[] = {1, 2, 3, 4};

  printArr(a, 4);
  cout << endl;

  rightShift(a, 4);

  printArr(a, 4);

  cout << endl;

  int b[] = {1, 2, 3, 4};
  printArr(b, 4);

  cout << endl;

  leftShift(b, 4);
  printArr(b, 4);


  return 0;
}
