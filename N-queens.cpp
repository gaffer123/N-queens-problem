#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
  for(int i = 0; i < (c - 1); i++){
    if((q[i] == q[c]) || (abs(q[c] - q[i]) == (c - i)))
    return false;
  }
  return true;
}

bool backtrack(int &col){
    col--;
    if(col==-1) return false;
    return true;
}

int nqueens(int n){
  int *q=new int[n];
   for(int i = 0; i < n; i++) q[i]=0;
   int c=0, solutions=0;
   bool from_backtrack=false;

   while(true){
       while(c<n){
       if(!from_backtrack)
           q[c]=-1;
           while(q[c]<n){
               q[c]++;
               if(q[c]==n){
                   if(backtrack(c)) continue;
                   else return solutions;
               }
               if(ok(q,c)) break;
           }
           c++;
           from_backtrack=false;
       }
       solutions++;
       if(!backtrack(c)) return solutions;
       from_backtrack=true;
   }
   delete[]q;
   return solutions;
}


int main(){

   int n;
   cout << "Enter an integer: ";
   cin >> n;

    for (int i = 1; i <= n; i++){
       cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";

}
return 0;

}
