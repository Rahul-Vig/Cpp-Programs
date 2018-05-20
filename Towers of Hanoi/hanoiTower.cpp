#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> t[3]; //declare our three towers which are int vectors.
  int n; //represents the number of rings
  cout << "Please enter the number of Rings: ";
  cin >> n; //get the number of rings using user input

  //from represents the index of the tower we move our candidate ring from.
  //to represents the index of the tower we move our candidate ring to.
  //candidate represents the smallest available ring that has not just been moved.
  //move keeps track of the ring movements
  int from = 0, to = (n%2 == 1) ? 1 : 2, candidate = 1, move = 0;

  //Now we need to initialize our towers
  for(int i = n+1; i > 0; i--){
    t[0].push_back(i); //place n+1, n, ... , 3, 2, 1 on the first tower. n+1 represents the base of each tower. The base does not move.
  }
    t[1].push_back(n+1); //place the base on the second tower. Also the destination tower where we want to move all the rings.
    t[2].push_back(n+1); //place the base on the third tower


  while(t[1].size() < n+1) { //while the size of our destination tower is less than the max size. Will terminate when all rings are placed.
    //The following cout statement will detail the move number and transfer action
    cout << "Move #" << ++move << ": Transfer Ring " << candidate << " from Tower " << char(from + 'A') << " to Tower " << char(to + 'A') << endl;

    t[to].push_back(t[from].back()); //We push the ring from the top of our from tower to our to tower.
    t[from].pop_back(); //We must get rid of the value of the ring we just transferred to the to tower from the from tower.

    if(n%2 == 1){ //in the case of odd n

      if(t[(to+1)%3].back() < t[(to+2)%3].back()){ //if the ring on t[(to+1)%3] < the ring on t[(to+2)%3] then
        from = (to+1)%3; //set from to the index of the tower (to+1)%3
      } else {
        from = (to+2)%3;
      } //this if finds the tower to move a ring from

      if(t[from].back() < t[(from+1)%3].back()){
        to = (from+1)%3;
      } else{
        to = (from+2)%3;
      }//this tower finds the tower to move the ring to.

      candidate = t[from].back();

    } else { //n is even

        if(t[(to+1)%3].back() < t[(to+2)%3].back()){
          from = (to+1)%3;
        } else{
          from = (to+2)%3;
        } //find the tower to move a ring from

        if(t[from].back() < t[(from+2)%3].back()){
          to = (from+2)%3;
        } else {
          to = (from+1)%3;
        }

        candidate = t[from].back();
    }
  }
}
