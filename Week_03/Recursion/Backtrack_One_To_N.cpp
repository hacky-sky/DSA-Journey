//this program will print 1 to N numbers linearly
/*Sample input:-
n=5 */
/*Sample output:-
1 2 3 4 5 */
#include<bits/stdc++.h>
using namespace std;
int print1toN(int i, int n){
    if(i<1) return 0;
    print1toN(i-1,n);
    cout<<i<<" ";
    return 0;
}
int main(){
    int n;
    cout<<"enter the number:- ";
    cin>>n;
    print1toN(n,n);
    return 0;
}