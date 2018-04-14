#include <iostream>
#include <cmath>
//8 Queens with no backtracking required due to recursion.

using std::cout;
using std::endl;
using std::abs;

bool ok(int q[], int c){ //Same ok as other 1D 8 Queens
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || c-i == abs(q[c] - q[i])){
      return false;
    }
  }
  return true;
}

void print(int* q){ //same print as other 1D 8 Queens
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < 8; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

void next(int* q, int c){
  if(c == 8){ //if we reach past last col print our solution
    print(q);
    return;
  }
  for(int j = 0; j < 8; j++){ //use for loop to test all possible rows
    q[c] = j; //set row to j
    if(ok(q, c)){ //see if the current placement works, if it does
        next(q, c+1); //go on to the next queen
    }
  }
}

int main(){
  int q[8] = {};
  next(q, 0); //Start at first col.
  return 0;
}
