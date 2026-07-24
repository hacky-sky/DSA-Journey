//this program find the sum of the first N natural numbers using function recursion
/*sample input:-
5 */
/*Sample output:-
15 */
#include<bits/stdc++.h>
using namespace std;
int sumf(int n){
    if(n==0) return 0;
    return n+sumf(n-1);
}
int main(){
    int n;
   cout<<"Enter the no.: ";
   cin>>n;
    cout<<sumf(n);
    return 0;
}