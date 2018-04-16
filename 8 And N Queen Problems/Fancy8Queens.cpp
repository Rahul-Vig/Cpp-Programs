#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
            return false;
    return true;
};


void print(int q[]) {
    static int solution =0;
    cout<< ++solution <<endl<<endl;

    int i,j,k,l;
    typedef char box[5][7];
    box bb,wb,*board[8][8];

    static box bq =
    {
        char(219), char(219), char(219), char(219), char(219), char(219), char(219),
        char(219), ' ', char(219), ' ', char(219), ' ', char(219),
        char(219), ' ', ' ', ' ', ' ', ' ', char(219),
        char(219), ' ', ' ', ' ', ' ', ' ', char(219),
        char(219), char(219), char(219), char(219), char(219), char(219), char(219)
    };


    static box wq =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', char(219), ' ', char(219), ' ', char(219), ' ',
        ' ', char(219), char(219), char(219), char(219), char(219), ' ',
        ' ', char(219), char(219), char(219), char(219), char(219), ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
    for(i=0;i<5;i++)
        for( j=0;j<7;j++)
        {
            wb[i][j]=' ';
            bb[i][j]=char(219);
        }

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i+j)%2==0){
                if(q[i]==j){
                    board[i][j]=&wq;
                } else {
                    board[i][j]=&wb;
                }
            } else {
                if(q[i]==j){
                    board[i][j]=&bq;
                } else {
                   board[i][j]=&bb;
                }
            }


    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<'_';
    cout<<endl;

    for(i=0;i<8;i++)
        for(k=0;k<5;k++)
        {cout<<" "<<char(179);
            for(j=0;j<8;j++)
                for(l=0;
                    l<7;l++)
                    cout<< (*board[i][j])[k][l];
            cout<<char(179)<<endl;
        }

    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<char(196);
    cout<<endl;

}

void next(int q[], int c){
  if (c == 8)
   print(q);
   else for (q[c] = 0; q[c] < 8; ++q[c])
   if (ok(q, c))
   next(q, c+1);
}

int main(){
    int q[8];
    next(q, 0);
    return 0;
}
