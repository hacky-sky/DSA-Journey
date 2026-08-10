//this program is to find the nth fibonacci number using recursion
/*sample input:-
n=3 */
/*Sample output:-
2 */
//fibonacci series=0,1,1,2,3,5,8,13.....
#include<bits/stdc++.h>
using namespace std;
long long int fib(long long int n){
    if(n==0) return 0;
    if(n==1) return 1;
    
    return fib(n-1)+fib(n-2);
}
int main(){
    long long int n;
    cout<<"Enter the position: ";
    cin>>n;
    cout<<fib(n);
    return 0;
}