#include <iostream>
#include <cmath>

using namespace std;


bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || (c-i) == abs(q[c] - q[i])){
      return false;
    }
  }
  return true;
}

int nQueens(int n){
  int* q = new int[n];
  int c = 0;
  int numSolutions = 0;
  q[c] = 0;

  while(c >= 0){
    ++c;
    if(c == n){
      numSolutions++;
      --c;
      if(c == -1) break;
    } else{
      q[c] = -1;
    }

    while(c >= 0){
      ++q[c];
      if(q[c] == n){
        --c;
      } else{
        if(ok(q, c)){
          break;
        }
      }
    }
  }
  delete[] q;

  return numSolutions;
}

int main(){
  int n = 12;
  for(int i = 1; i <= n; ++i)
    cout << "There are " << nQueens(i) << " Solutions to the " << i << " Queens problem" << endl;

  return 0;
}
