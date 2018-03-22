//Equivalent Array (Right Shift) : This program determines whether two arrays are equivalent despite being right shifted by an offset.
//All entries in b[(i+offset)%size] must correspond with entries in a[i] where i starts at 0 and continues to n which is the size of the array
//Written by Rahul Vig

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool equivalent(int a[], int b[], int size){
  for(int i = 0; i < size; i++) { //using this for loop, we first determine a possible offset then we check to see if all other entries in b match a according to the offset.

    if(a[0] == b[i]){ //if we find a corresponding entry in b that matches with a[0] (the first element in a) then we have found a possible offset.
      for(int j = 1; j < size; j++){ //now that we have found a possible offset, we must see if all the following entries in b match with a
        if(a[j] !=  b[(i+j)%size]){ //if we find an entry in b such that it does not correspond to a according to the offset, then we break out of the inner for loop and re-enter the outer for loop
          break; //to find another possible offset
        }

        if(j == size-1){ //we will only enter this if statement if no mismatch was found and j must be == to the last index
          return true;
        }
      }
    }
  }
  return false; //the arrays are not equivalent
}

int main(){
  cout<< std::boolalpha;

  int a1[5] = {1, 2, 3, 4, 5};
  int a2[5] = {3, 4, 5, 1, 2};
  cout << equivalent(a1, a2, 5) << endl; // true

  int b1[3] = {1, 2, 3};
  int b2[3] = {2, 3, 3};
  cout << equivalent(b1, b2, 3) << endl; // false

  int c1[4] = {2, 3, 4, 1};
  int c2[4] = {1, 4, 3, 2};
  cout << equivalent(c1, c2, 4) << endl; // false

  int d1[4] = {3, 2, 3, 1};
  int d2[4] = {3, 1, 3, 2};
  cout << equivalent(d1, d2, 4) << endl; // true

  int e1[5] = {1, 1, 1, 1, 2};
  int e2[5] = {1, 1, 1, 2, 1};
  cout << equivalent(e1, e2, 5) << endl; // true

  cout << endl;



  return 0;
}
