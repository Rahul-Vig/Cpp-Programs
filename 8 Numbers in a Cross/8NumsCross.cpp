#include <iostream>
#include <cmath>
#include <stdlib.h>
/*
Write a program which allocates the integers 1-8 to the boxes in a cross shape:
      |1|4|
    |0|2|5|7|
      |3|6|
The numbers in the box above represent the indexes of the boxes. Our adjacency matrix is based on the positions of the boxes in our cross.
The goal is to make sure none of the integers 1-8 are set so that two adjacent squares contain consecutive integers.
*/

using std::cout;
using std::endl;
using std::abs;

bool ok(int cross[], int box){ //our ok f(x) checks to see if we can place an integer without any conflict
 static int adjacency_list[8][5]  = {
                                     {-1, -1, -1, -1, -1}, //box 0
                                     { 0, -1, -1, -1, -1}, //1
                                     { 0, 1, -1, -1, -1 }, //2
                                     { 0, 2, -1, -1, -1 }, //3
                                     { 1, 2, -1, -1, -1 }, //4
                                     { 1, 2,  3,  4, -1 }, //5
                                     { 2, 3, 5,  -1, -1 }, //6
                                     { 4, 5, 6,  -1, -1 }  //7
                                     };

  for(int i = 0; i < box; i++){ //this conflict test determines whether we have already used a value or not
    if(cross[box] == cross[i]){ //Same concept as the row conflict check for our 1D 8 Queens problem
      return false;
    }
  }

  for(int i = 0; adjacency_list[box][i] != -1; i++){ //This loop checks to see if any of the adjacent squares contains a consecutive integer.
    if(abs(cross[box] - cross[adjacency_list[box][i]]) == 1){
      return false;
    }
  }

  return true;

}

void backtrack(int& box){ //same backtrack as the 8 Queens 1D problem
  --box;
  if(box == 8){
    exit(1);
  }

}

void print(int cross[]){
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  cout << "  |" << cross[1] << "|" << cross[4] << "|" << endl << "|" << cross[0] << "|" << cross[2] << "|" << cross[5] << "|" << cross[7]  << "|" << endl << "  |" << cross[3]
  << "|" << cross[6] << "|" << " ";

  cout << endl <<endl;
}

int main(){
  int cross[8] = {0}; //This array indexed 0-7 will contain the integer values of our cross in which there are no conflicts
  int box = 0;
  cross[box] = 1; //We set the first box (box 0) to contain the first integer (1)

  while(box >= 0){ //We create an outer and inner for loop much like our 8 Queens problem, each loop determining col action and row action respectively
    ++box; //we already placed 1 in the first box so we move on to the next box
    if(box == 8){ //if we reach this point, we have found a solution and must print
      print(cross);
      backtrack(box); //we backtrack after printing to find another possible solution
    } else{
      cross[box] = 0; //if we don't print then we still need to determine an int to place in the current box, so we set the element in the box to default value 0
    }

    while(box >= 0){
      ++cross[box];
      if(cross[box] == 9){
        backtrack(box); //if we cannot place any int in the curr. box due to conflict we must backtrack
      } else{
        if(ok(cross, box)){ //if the current integer in the box is okay then, we can break out of the inner loop and go to the outer to find the int for the next box.
          break;
        }
      }
    }
  }

}
