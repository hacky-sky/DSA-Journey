// this program demonstrates copying a vector
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    vector<int>v(n);
     vector<int>v2(v);
    cout<<"Enter the elements: ";
    for(int &i:v){
        cin>>i;
    }
    cout<<"Elements of first vector are: ";
    for(int i:v){
        cout<<i<<endl;
    }
    cout<<"Elements of second vector are: ";
    for(int i:v2){
        cout<<i<<endl;
    }
    return 0;
}