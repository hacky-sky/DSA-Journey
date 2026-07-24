//this program find the sum of the first N natural numbers using recursion
/*sample input:-
5 */
/*Sample output:-
15 */
#include<bits/stdc++.h>
using namespace std;
int printsum(int i,int sum){
    if(i<1) 
   {  cout<<sum; return 0;}
    printsum(i-1,sum+i);
    return 0;
}
int main(){
    int n;
    cout<<"enter the number:- ";
    cin>>n;
    printsum(n,0);
    return 0;
}
   