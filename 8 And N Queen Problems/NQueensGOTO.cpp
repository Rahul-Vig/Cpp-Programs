#include <iostream>
#include <cmath>

using namespace std;


int main(){
  int n, c = 0;
  cout << "Enter the number of Queens you want to determine a solution for: ";
  cin >> n;
  int q[n] = {};
  q[c] = 0;

nextCol:
  c++;

  if(c == n){
    goto print;
  }

  q[c] = -1;

nextRow:
  q[c]++;
  if(q[c] == n){
    goto backtrack;
  }

  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || c-i == abs(q[c] - q[i])){
      goto nextRow;
    }
  }

  goto nextCol;

backtrack:
  --c;
  if(c == -1){
    //delete[] q;
    return 0;
  }

  goto nextRow;

print:
  static int count = 0;
  cout << "Solution #: " << ++count << endl;
  for(int i = 0; i < n; i++){
      cout << q[i] << " ";
  }
  cout << endl;

  goto backtrack;
}
