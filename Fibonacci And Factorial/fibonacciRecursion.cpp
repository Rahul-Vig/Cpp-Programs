#include <iostream>

using namespace std;
//displays the first n fib numbers

int fib(int n){
  if(n == 1 || n == 2) return 1;

  return fib(n-1) + fib(n-2);
}

int main(){
  for(int i = 1; i < 100; i++){
    cout << i << ": " << fib(i) << endl;
  }
  cout << endl;
}
