#include <iostream>

using namespace std;

int factorial(int n){
  if(n == 0) return 1;
  return n * factorial(n-1);
}


int main(){
  cout << factorial(5) << endl;
  cout << factorial(4) << endl;
  cout << factorial(3) << endl;
  cout << factorial(2) << endl;
  cout << factorial(1) << endl;
  cout << factorial(10) << endl;
}
