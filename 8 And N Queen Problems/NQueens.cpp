#include <iostream>
#include <cmath>
#include <stdlib.h>

//N Queens Problem Solved without using GOTO Statements

using namespace std;

bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || c-i == abs(q[c] - q[i])){
      return false;
    }
  }
  return true;
}

void backtrack(int& c){
  --c;
  if(c == -1){
    exit(1);
  }
}

void print(int q[], int n){
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < n; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

int main(){
  int n;
  cout << "Enter N to find the Solution for N Queens: ";
  cin >> n;
  int q[n] = {}, c = 0;
  q[c] = 0;

  while(c >= 0){
    ++c;
    if(c == n){
      print(q, n);
      backtrack(c);
    } else{
      q[c] = -1;
    }

    while(c >= 0){
      ++q[c];
      if(q[c] == n){
        backtrack(c);
      } else{
        if(ok(q, c)){
          break;
        }
      }
    }
  }
}
