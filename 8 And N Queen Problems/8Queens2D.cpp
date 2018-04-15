#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

bool ok(int board[][8], int row, int col){ //This function will check for conflicts
  //row test
  for(int i = 0; i < col; i++){
    if(board[row][i] == 1){
      return false;
    }
  }

  //upper diagnol test
  for(int i = 0; row - i >= 0 && col - i >= 0; i++){
    if(board[row-i][col-i] == 1){
      return false;
    }
  }

  //lower diagnol test
  for(int i = 0; row + i < 8 && col - i >= 0; i++){
    if(board[row+i][col-i] == 1){
      return false;
    }
  }

return true;
}

void backtrack(int board[][8], int& row, int& col){ //backtrack function
  col--;
  if(col == -1) exit(1);

  row = 0;
  while(board[row][col] != 1){
    row++;
  }
  board[row][col] = 0;
}

void print(int board[][8]){ //print function
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
int board[8][8] = {};
int row = 0, col = 0;
board[row][col] = 1;

while(col >= 0){ //instead of using goto labels we use while loops
  ++col; //goto nextCol
  if(col == 8){
    print(board);
    backtrack(board, row, col); //need to backtrack once we print
  } else{
    row = -1; //if we don't print we need to reset the row
  }

  while(col >= 0){
    ++row;
    if(row == 8){
      backtrack(board, row, col);
    } else{
      if(ok(board, row, col)){
        board[row][col] = 1; //no conflict so we place queen
        break; //break out of inner for loop to go to the outer and start new col.
      }
    }
  }
}
}
