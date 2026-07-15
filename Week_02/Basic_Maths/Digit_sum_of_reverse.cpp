//this program displays the sum of reversed integers
/*sample input:
1234*/
/*sample output:
reversed: 4321
digit sum: 10*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,rev=0,sum=0;
    cout<<"Enter a number: ";
    cin>>n;
    do{
        int rem=n%10;
        rev=(rev*10)+rem;
        n=n/10;
        sum=sum+rem;
    }while(n!=0);
    cout<<endl<<"reversed : "<<rev<<endl<<"digit sum : "<<sum;
    return 0;
}