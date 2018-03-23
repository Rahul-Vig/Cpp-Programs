#include <iostream>

using std::cout;
using std::endl;

int main(){
  int board[8][8] =  {0}; //Initialize our board to a 2D 8*8 int array object with null values.
  int row = 0, col = 0; //Iniitialize our row and col variables to 0, each respectively reprsenting the boards row and the boards col.
  board[0][0] = 1; //Place the first queen in the first position of the board

  nextCol: //this label will be used to bring us back to the nextCol
  ++col; //since we already placed our queen in the first col, we want to start out by shifting to the next col.
    if(col == 8){ //if we have reached the end of the cols then we must have found a solution
      goto print; //print the solution
    }
    row = -1; //we need to make sure our row always increaments to 0 when we go to a new col

  nextRow: //this label will be used to bring us back to the nextRow
  ++row; //increment row when the queen cannot occupy curr row
  if(row == 8){ //If we couldnt find a possible position for the queen we need to backtrack
    goto backtrack;
  }

  //row test
  for(int i = 0; i < col; i++){
    if(board[row][i] == 1){
      goto nextRow;
    }
  }

  //upper diagnol test
  for(int i = 0; row - i >= 0 && col - i >= 0; i++){
    if(board[row-i][col-i] == 1){
      goto nextRow;
    }
  }

  //lower diagnol test
  for(int i = 0; row + i < 8 && col - i >= 0; i++){
    if(board[row+i][col-i] == 1){
      goto nextRow;
    }
  }

  board[row][col] = 1; // we can place a queen here because there was no conflict detected
  goto nextCol; //goto nextCol

  backtrack:
  --col; //when we backtrack we go back one col.
  if(col == -1){ //if we go one before the first col we have found all possible solutions and now we should exit the program
    return 0;
  }

  row = 0; //reset the row to check if the col has any queens
  while(board[row][col] != 1){ //find the row with the queen
    ++row; //increment the row until you find the row with the queen.
  }

  board[row][col] = 0; //set the current pos to 0 to indicate the removal of the queen.

  goto nextRow; //Now we can go to the next row

  print: //Prints all the solutions in the form of a 2D matrix
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  goto backtrack; //backtrack after printing to see if there are most possible solutions


  return 0;

}
