//this program demonstrates how to sort a vector using the sort function from the algorithm library
/*Sample input:
5
40 10 30 20 50*/
/*Sample output:
ascending: 10 20 30 40 50
descending: 50 40 30 20 10*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: "<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of vector: "<<endl;
    for (int &x:v){
        cin>>x;
    }
    sort(v.begin(),v.end());
    cout<<"Ascending :";
    for(int x:v){
        cout<<x<<" ";
    }
    sort(v.begin(),v.end(),greater<int>());
    cout<<endl<<"Descending :";
    for(int x:v){
        cout<<x<<" ";
    }
    return 0;
}