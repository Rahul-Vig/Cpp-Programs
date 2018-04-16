#include <iostream>

using namespace std;


int fib(int n){
  static int memo[100] = {0};

  if(n == 1 || n == 2) return 1;

  if(memo[n] != 0) return memo[n];

  return memo[n] = fib(n-1) + fib(n-2);

}


int main(){
  for(int i = 1; i <= 100; i++){
    cout << i << ": " << fib(i) << endl;
  }
  cout << endl;
}
