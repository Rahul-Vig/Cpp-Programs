#include <iostream>

using namespace std;


bool isPrime(int num){
  if(num <= 1) return false;
  else if(num == 2) return true;
  else {
    for(int i = 2; i <= num/2; i++){
      if(num % i == 0){
        return false;
      }
    }
  }
  return true;
}

int number_of_primes(int from, int to){
  int count = 0;
  for(int i = from; i <= to; i++){
    if(isPrime(i)){
      count++;
    }
  }
  return count;
}

int main(){
  cout << boolalpha;
  cout << isPrime(1) << endl;
  cout << isPrime(2) << endl;
  cout << isPrime(3) << endl;
  cout << isPrime(4) << endl;
  cout << isPrime(5) << endl;
  cout << isPrime(6) << endl;
  cout << isPrime(7) << endl;
  cout << isPrime(8) << endl;
  cout << isPrime(9) << endl;
  cout << isPrime(10) << endl;
  cout << isPrime(11) << endl;

  cout << number_of_primes(0, 100) << endl;
  cout << endl;
}
