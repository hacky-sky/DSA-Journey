// this program demonstrates the use of vector to take array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements: ";
    for(int &i:v){
        cin>>i;
    }
    cout<<"Elements are: ";
    for(int i:v){
        cout<<i<<endl;
    }
    return 0;
}