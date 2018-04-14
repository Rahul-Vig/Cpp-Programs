#include <stdlib.h>
#include <iostream>
#include <cmath>

using std::abs;
using std::cout;
using std::endl;

bool ok(int q[], int c){ //check if there is a conflict when placing a queen
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || (c-i) == abs(q[c]- q[i])){ //here we check for conflict in one conditional statement by using an || (or)
      return false; //if we find a conflict return false;
    }
}
return true;
}

void backtrack(int& c){ //must pass reference to c in order to actuall have an effect on the col.
  --c;
  if(c == -1) exit(1);
}

void print(int q[]){
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < 8; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

int main(){
int q[8] = {0}; //initialize our 1D array to 0
int c = 0;
q[c] = 0; //place our first queen

while(c >= 0){ //outer for loop representing nextCol
  ++c;
  if(c == 8){ //if we reach past last col, we have found a solution
    print(q);
    backtrack(c); //remember to backtrack after printing to find more solutions
  } else{
    q[c] = -1; //no solution found yet so set row to one before 1st.
  }
  while(c >= 0){ //inner for loop representing nextRow
    ++q[c]; //increment row;
    if(q[c] == 8){
      backtrack(c); //backtrack when we cannot place queen
    } else{
      if(ok(q, c)){ //if we find now conflict break out of inner for loop and go to the outer to start nextCol queen placement
        break;
      }
    }
  }
}
}
