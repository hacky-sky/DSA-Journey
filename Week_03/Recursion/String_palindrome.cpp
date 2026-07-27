//this program checks whether the given string is palindrome or not using recursion
/*Sample input:-
madam*/
/*Sample output:-
true*/
#include<bits/stdc++.h>
using namespace std;
bool palindrome(int l,int r,string &n){
    if(l>=r) return true;
    if(n[l]!=n[r]) return false;
    return  palindrome(l+1,r-1,n);
}
int main(){
    string n;
    cout<<"Enter the word: ";
    cin>>n;
    int len=n.size();
    cout<<palindrome(0,len-1,n);

    return 0;
}
