//this program will find the hcf of two numbers
/*sample input:
5 10*/
/*sample output:    
5*/
#include <bits/stdc++.h>
using namespace std;
int main(){
   int a,b;
    cout<<"Enter the number: ";
    cin>>a>>b;
    while(a>0 && b>0){
        if(a>b) {a=a%b;}
        else { b=b%a;}
    }
    cout<<"HCF: ";
    if(a==0) {cout<<b;}
    else { cout<<a;}
    return 0;
}
/* Simple way:- 
     int small;
     if(a>b) {small=b;}
     else {small=a;}
     cout<<"Common factors of "<<a<<" and "<<b<<" are: "<<endl;
     vector<int>v;
     for(int i=1;i<=small;i++){
        if(a%i==0 && b%i==0) {
            cout<<i<<" ";
            hcf=i;
        }
     }
    cout<<endl<<"HCF: "<<hcf;*/