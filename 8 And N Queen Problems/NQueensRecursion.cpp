#include <iostream>
#include <cmath>

using namespace std;


bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || c-i == abs(q[c] - q[i])){
      return false;
    }
  }
  return true;
}


void print(int q[], int n){
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < n; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

void next(int q[], int c, int n){
  if(c == 8){
    print(q, n);
    return;
  }

  for(int j = 0; j < n; j++){
    q[c] = j;
    if(ok(q, c)){
      next(q, c+1, n);
    }
  }
}

int main(){
  cout << "Enter N to find Solution for N Queens: ";
  int n;
  cin >> n;
  int q[n] = {}, c = 0;
  next(q, c, n);
  return 0;
}
