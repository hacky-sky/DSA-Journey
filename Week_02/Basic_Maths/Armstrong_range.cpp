//this program print all armstrong numbers between two numbers a and b
/*sample input:
1
1000*/
/*sample output:
1 2 3 4 5 6 7 8 9 153 370 371 407*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,totalDigit;
    cout<<"Enter the range:";
    cin>>a>>b;
    
    for(int i=a;i<=b;i++){
        int sum=0;
        int dup=i;
         if(dup==0){
         totalDigit=1;}
         else{
         dup=abs(dup);
         totalDigit=(int)(log10(dup))+1;
        }
         do{
        int ld=dup%10;
        sum=sum+(int)round(pow(ld,totalDigit));
        dup=dup/10;
    }while(dup!=0);
     if(i==sum)
     cout<<sum<<" "<<endl;
    }
   
    return 0;
}