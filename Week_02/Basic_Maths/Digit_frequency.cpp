//this program counts how many time a digit appears in a no.
/*sample input:
12321
2 */
/*sample output:
2 appears 2 times*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,key,count=0;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the digit you want frequency of: ";
    cin>>key;
    if(n<0)
    n=-n;
    do{
        int rem=n%10;
        if(rem==key){
            count++;
        }
        n=n/10;
    }while(n!=0);
    cout<<endl<<key<<" appears "<<count<<" times.";
    return 0;
}