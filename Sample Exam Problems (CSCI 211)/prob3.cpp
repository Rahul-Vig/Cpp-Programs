#include <iostream>
#include <cmath>

using namespace std;


bool ok(int q[]){
  for(int col = 7; col >= 1; col--){
    for(int i = 0; i < col; i++){
      if(q[col] == q[i] || col-i == abs(q[col] - q[i])){
        return false;
      }
    }
  }
  return true;
}

int main(){
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int b[] = {0, 4, 7, 5, 2, 6, 1, 3};
  int c[] = {0, 5, 7, 2, 6, 3, 1, 4};

  cout << boolalpha;
  cout << ok(a) << endl;
  cout << ok(b) << endl;
  cout << ok(c) << endl;
}
