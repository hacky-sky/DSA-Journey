/* this program identifies if a no. is armstrong or not
example= 153= (1*1*1)+(5*5*5)+(3*3*3)
1+125+27=153.
definition: when a number is equal to the sum of its digits 
with power of (no. of digits in the no.) is armstrong no. */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,totalDigit;
    cout<<"Enter the number:";
    cin>>n;
    int dup=n;
    if(n==0){
    totalDigit=1;}
    else{
        n=abs(n);
        totalDigit=(int)(log10(n))+1;
    }
    do{
        int ld=n%10;
        sum=sum+(int)pow(ld,totalDigit);
        n=n/10;
    }while(n!=0);
    if(dup==sum)
    cout<<endl<<"Yes,it is armstrong";
    else
    cout<<"No,it is not";

    return 0;
}