//this program reverses the given number.
/*sample input:
1234 */
/*sample output:
4321*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,rev=0;
    cout<<"Enter a number: ";
    cin>>n;
    do{
        int rem=n%10;
        rev=(rev*10)+rem;
        n=n/10;
    }while(n!=0);
    cout<<endl<<"reverse number: "<<rev;
    return 0;
}