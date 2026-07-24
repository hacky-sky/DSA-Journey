//this program will display factorial of a number using recursion.
// factorial =1*2*3*n.
/*sample input:-
4 */
/*Sample output:-
24 */
#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==0) return 1;
    return n*(factorial (n-1));
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<factorial(n);
}