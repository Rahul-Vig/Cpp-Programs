#include <iostream>

using namespace std;

unsigned long fib(long n){
  if(n == 1 || n == 2) return 1;
  else{
    unsigned long a = 1, b = 1, c;
    for(int i = 2; i < n; i++){
      c = a+b;
      a = b;
      b = c;
    }
    return b;
  }
}



int main(){
  for(int i = 1; i < 100; i++){
    cout << i << ": " << fib(i) << endl;
  }
  cout << endl;
}
