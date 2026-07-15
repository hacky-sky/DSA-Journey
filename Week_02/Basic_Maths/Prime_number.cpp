//this program checks if a number is prime or not.
/*Sample input:-
17 */
/*Sample output:-
Yes, 17 is a prime no.*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    bool isPrime = true;
    if(n==1){
        isPrime=false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) {
        isPrime=false;
        break;}
    }
    if(isPrime==true) {cout<<"Yes, "<<n<<" is a prime no.";}
    else { cout<<"No,"<<n<<" is not a prime no.";}
    return 0;
}