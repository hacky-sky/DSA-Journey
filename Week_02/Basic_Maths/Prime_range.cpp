//This program finds all prime numbers in a given range from a to b.
/*Sample input:-
1
50*/
/*Sample output:-
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the range: ";
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        bool isPrime = true;
         if(i==1){
        isPrime=false;
         }
      for(int j=2;j<=sqrt(i);j++){
        if(i%j==0) {
        isPrime=false;
        break;}
       }
       if(isPrime==true) {cout<<i<<endl;}
    }

    return 0;
}