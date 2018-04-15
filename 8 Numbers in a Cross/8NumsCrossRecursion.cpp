#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::abs;

//Recursive solution to 8 Nums in Cross

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

void print(int cross[]){
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  cout << "  |" << cross[1] << "|" << cross[4] << "|" << endl << "|" << cross[0] << "|" << cross[2] << "|" << cross[5] << "|" << cross[7]  << "|" << endl << "  |" << cross[3]
  << "|" << cross[6] << "|" << " ";

  cout << endl <<endl;
}

void next(int cross[], int box){
  if(box == 8){
    print(cross);
    return;
  }
  for(int i = 1; i < 9; i++){
    cross[box] = i;
    if(ok(cross, box)){
      next(cross, box+1);
    }
  }
}

int main(){
  int cross[8] = {};
  next(cross, 0);
  return 0;
}
