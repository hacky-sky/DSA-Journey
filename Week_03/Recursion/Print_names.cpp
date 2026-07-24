//this program will print the given name n times using recursion
/*Sample Input:-
N = 5 */
/*Sample Output:-
GFG
GFG
GFG
GFG
GFG */
#include<bits/stdc++.h>
using namespace std;
int print(int i,int n,string name){
    if (i>n) return 0;
    cout<<name<<endl;
    print(i+1,n,name);
    return 0;
}
//time complexity=O(n)
//space complexity=O(n)
int main(){
    int n;
    string name;
    cout<<"enter the number:- ";
    cin>>n;
    cout<<"The name to be printed: ";
    cin>>name;
    print(1,n,name);
    return 0;
}