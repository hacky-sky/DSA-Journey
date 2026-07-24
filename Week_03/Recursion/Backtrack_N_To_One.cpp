//thus program will print N to 1 numbers linearly using backrack method
/*Sample input:-
n=6 */
/*Sample output:-
6 5 4 3 2 1 */
#include<bits/stdc++.h>
using namespace std;
int printNto1(int i,int n){
   if(i>n) return 0; 
    printNto1(i+1,n);
     cout<<i<<" ";
    return 0;
}
int main(){
    int n;
    cout<<"enter the number:- ";
    cin>>n;
    printNto1(1,n);
    return 0;
}

