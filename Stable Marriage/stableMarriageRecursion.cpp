#include <iostream>
#include <cmath>

using namespace std;

int mp[3][3]={0,2,1,
              0,2,1,
             1,2,0};

int wp[3][3]={2,1,0,
              0,1,2,
              2,0,1};


bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
    if(q[c] == q[i]) return false;
  }

  for(int i = 0; i < c; i++){
    if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false;
    if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
  }

  return true;
}

void print(int q[]){
  static int count = 0;
  cout << "Solution # " << ++count << endl;
  for(int i = 0; i < 3; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

void next(int q[], int c){
  if(c == 3){
    print(q);
    return;
  }

  for(int i = 0; i < 3; i++){
    q[c] = i;
     if(ok(q,c)){
       next(q, c+1);
     }
  }
}

int main(){
  int q[3] = {};
  next(q, 0);
  return 0;
}
