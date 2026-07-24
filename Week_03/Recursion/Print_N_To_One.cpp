//thus program will print N to 1 numbers linearly
/*Sample input:-
n=6 */
/*Sample output:-
6 5 4 3 2 1 */
#include<bits/stdc++.h>
using namespace std;
int printNto1(int n){
   if(n<1) return 0;
    cout<<n<<" ";
    printNto1(n-1);
    return 0;
}
int main(){
    int n;
    cout<<"enter the number:- ";
    cin>>n;
    printNto1(n);
    return 0;
}

