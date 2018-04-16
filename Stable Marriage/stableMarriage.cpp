#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

   int mp[3][3]={0,2,1,
                 0,2,1,
                1,2,0};

   int wp[3][3]={2,1,0,
                 0,1,2,
                 2,0,1};

   bool ok(int q[], int col)
   {   int i;
       for(i=0; i<col;i++)
       {
          if(q[col]==q[i])
            return false;
       }

       for(i=0; i<col; i++)
       {
         if( ( mp[col][q[i]]<mp[col][q[col]] )&& ( wp[q[i]][col]<wp[q[i]][i]) )
               return false;
         if( ( wp[q[col]][i]<wp[q[col]][col] )&& ( mp[i][q[col]]<mp[i][q[i]]) )
               return false;
       }

       return true;

   }

  void backtrack(int &col){
       col--;
       if(col==-1) return;
      }

 void print(int q[]) {
         static int solution = 0;
         cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
         for (int i = 0; i < 3; ++i)
            cout << i << "\t" << q[i] << "\n";
         cout << "\n";
      }

   int main()
   {
     int q[3];
     q[0]=0;
     int c=0;

     while (c >= 0) { // End the loop if you backtrack from the first column
         ++c; // Move to the next column
         if(c == 3){
          print(q);
          backtrack(c);
        } else {
          q[c] = -1;
        }// If you have passed the last column,
           // Call the print function and backtrack
        // Otherwise, move to one before the first row
        while (c >= 0) {
           ++q[c];// Move to the next row
           if(q[c] == 3){
             backtrack(c);
           } else{
             if(ok(q,c)) break;
           }// If you have passed the end of the column, backtrack
           // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
        }
     }
 }
