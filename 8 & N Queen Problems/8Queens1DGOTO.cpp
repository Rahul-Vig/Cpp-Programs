#include <iostream>
#include <cmath>

using std::endl;
using std::cout;

int main(){
//This time we will use a 1D Array to represent our Queens. c represents our col whereas q[c] represents the row queen is in
int q[8] = {0}; //create empty array of 8 ints
int c = 0; //c will represent the column we are in
q[c] = 0; //q[c] represents the row our queen is in. So we first place a queen in the first row (0)

nextCol:
++c; //increment col;
if(c == 8) goto print; //if we go past last col then print
q[c] = -1; //set next col to one before first row, so that nextRow increments row to 0;

nextRow:
++q[c]; //increment our row
if(q[c] == 8) goto backtrack; //we cannot place queen so we must backtrack;

for(int i = 0; i < c; i++){
  if(q[c] == q[i]){ //if we have already have a queen in this row we cannot place a new one in the same row.
    goto nextRow;
  }
}

for(int i = 0; i < c; i++){
  if (c - i == std::abs(q[c] - q[i])){
    goto nextRow;
  }
}

//no conflict, but unlike 2D 8 Queens we don't have to place the queen since, our placement is determined by q[c]
goto nextCol;

backtrack:
--c;
if(c == -1) return 0; //we don't need to remove 1 from our row so we don't need to find our prev. queen

goto nextRow; //simply goto nextRow to see if next placement of Queen works

print:
static int count = 0;
cout << "Solution # " << ++count << endl;
for(int i = 0; i < 8; i++){
  cout << q[i] << " ";
}
cout << endl;

goto backtrack; //backtrack once we print solution to find another solution

}
