#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> t[3];
    // three towers A,B,c represented as an array of 3 vectors
    cout<<"Please enter a number of rings to move: ";
    int n;  // move counts the move number
    cin>>n;
    cout<<endl;

    //
    for(int i=n+1;i>=1;i--){
    t[0].push_back(i);
    }

    t[1].push_back(n+1);
    t[2].push_back(n+1);

    int candidate = 1 ,to = (((n%2)==1) ? 1 : 2), from = 0, move=0;

    while( t[1].size()<n+1){

        t[to].push_back(t[from].back());
        t[from].pop_back();
        cout<<"Move #"<<++move<<": Transfer ring "<<candidate<<" from tower "<<char(from+'A')<<" to tower "<<char(to+'A')<<endl;


        if(n%2==1){ //if n is odd
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;

            if(t[(from)].back() < t[(from+1)%3].back())
                to=(from+1)%3;
            else
                to=(from+2)%3;

            candidate=(t[from].back());
        } else { //else n is evem
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;

            if(t[(from)].back() < t[(from+2)%3].back())
                to=(from+2)%3;
            else
                to=(from+1)%3;

            candidate=(t[from].back());
        }
    }
    return 0;
}
