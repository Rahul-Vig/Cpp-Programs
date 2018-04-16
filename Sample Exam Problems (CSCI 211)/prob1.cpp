#include <iostream>

using std::cout;

void f(int i){
  if(i = 4 || i = 5) return;

  cout << "hello, world\n";

}

int main(){
  f(3);
  f(4);
  f(5);
}


//This program will not compile!
