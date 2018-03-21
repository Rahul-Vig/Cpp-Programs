#include <iostream>
#include <climits>

using std::cout;
using std::endl;

int main(){
  //The Problem: Write a program to find and print the first perfect square (i*i) whose last two digits are both odd.
  //This program attempts to find the first perfect square whose last two digits are odd
  //1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225.
  int i = 1; //start i at 1
  int digit1; //last digit
  int digit2; //second to last digit
  int square = i * i; //initialize our square variable to the first perfect square (1 * 1)
  bool notFound = true;

  while(notFound){ //Start while loop and do not terminate until you have found the square whose last two digits are odd or square < INT_MAX (no such square exists)
    i++;
    square = i * i;
    digit1 = square % 10; //get the last digit
    square /= 10; //divide original square value by 10 to obtain second to last digit
    digit2 = square % 10; //get second to last digit

    if((digit1 % 2 == 1 && digit2 % 2 == 1) && i >= 4){
      square = i * i; //reset value of the square
      notFound = false;
    }

    square = i*i; //reset value of the square;

    if(i == 100){ //We must have found a square at this point because the last two digits of perfect squares cycles. If this wasn't here the program would loop forever.
      cout << "No perfect square with the specified criteria found" << endl;
      break;
    }

  }

  cout << i << endl;
  cout << square << endl;

  return 0;
}
