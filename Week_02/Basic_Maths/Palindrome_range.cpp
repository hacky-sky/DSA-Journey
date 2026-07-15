//this program reverses the given number and check if it is palindrome.
/*sample input:
10
151 */
/*sample output:
11 22 33 44 55 66 77 88 99 101 111 121 131 141 151*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter a range: ";
    cin>>a>>b;
    
    for(int i=a;i<=b;i++){
        int rev=0;
        int decoy=i;
        do{
        int rem=decoy%10;
        rev=(rev*10)+rem;
        decoy=decoy/10;
    }while(decoy!=0);
     if(i==rev)
     cout<<rev<<" "<<endl;
    }
   
    return 0;
}