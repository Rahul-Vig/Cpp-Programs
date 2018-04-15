#include <iostream>

using namespace std;


int exp(int x, int n){
  if(n ==  0) return 1;

  return x * exp(x, n-1);
}

void print(char* s){
  if(*s == '\0') return;
  cout << *s;
  print(s+1);
}

void rev_print(char* s){
  if(*s == '\0') return;
  rev_print(s+1);
  cout << *s;
}

void print_int(int n){
  if(n/10 == 0){
    cout << n % 10;
    return;
  }
  print_int(n / 10);
  cout << n % 10;
}

void rev_print_int(int n){
  if(n / 10 == 0){
    cout << n%10;
    return;
  }
  cout << n % 10;
  rev_print_int(n/10);
}

int main(){
  cout << "The exponent is: " << exp(4, 3) << endl;

  char word[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  print(word);
  cout << endl;
  rev_print(word);
  cout << endl;

  print_int(122);
  cout << endl;

  rev_print_int(122);
  cout << endl;

}
