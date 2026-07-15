//this program reverses the given number and check if it is palindrome.
/*sample input:
1221 */
/*sample output:
1221
yes,it is palindrome*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,rev=0;
    cout<<"Enter a number: ";
    cin>>n;
    int num=n;
    do{
        int rem=n%10;
        rev=(rev*10)+rem;
        n=n/10;
    }while(n!=0);
    cout<<endl<<"reverse number: "<<rev<<endl;
    if(num==rev)
    cout<<"Yes, it is palindrome";
    else
    cout<<"No,it is not palindrome";
    return 0;
}