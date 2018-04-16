#include <iostream>
#include <cmath>

using namespace std;

bool ok(int q[]){
  static int a[8][5] = {
                        {-1, -1, -1, -1, -1}, //box 0
                        { 0, -1, -1, -1, -1}, //1
                        { 0, 1, -1, -1, -1 }, //2
                        { 0, 2, -1, -1, -1 }, //3
                        { 1, 2, -1, -1, -1 }, //4
                        { 1, 2,  3,  4, -1 }, //5
                        { 2, 3, 5,  -1, -1 }, //6
                        { 4, 5, 6,  -1, -1 }  //7
                        };

for(int box = 7; box >= 1; box--){
  for(int i = 0; i < box; i++){
    if(q[box] == q[i]) return false;
  }

  for(int j = 0; a[box][j] != -1; j++){
    if(abs(q[box] - q[a[box][j]]) == 1) return false;
  }
}

return true;

}


int main(){
  int a[] = {2, 5, 8, 6, 3, 1, 4, 7};
  int b[] = {2, 6, 8, 5, 4, 1, 3, 7};
  int c[] = {7, 3, 1, 4, 5, 8, 6, 2};
  int d[] = {7, 4, 1, 3, 6, 8, 5, 2};
  int e[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int f[] = {8, 7, 6, 5, 4, 3, 2, 1};

  cout << boolalpha;

  cout << ok(a) << endl;
  cout << ok(b) << endl;
  cout << ok(c) << endl;
  cout << ok(d) << endl;
  cout << ok(e) << endl;
  cout << ok(f) << endl;


}
