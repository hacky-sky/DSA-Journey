// Basic Hashing Implementation
//Hashing is a technique where you store information
// about elements (like their frequency, or whether they exist)
// at a specific index in an array.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i]; }
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1; }
    int q;
    cout<<"find frequency of: "<<endl;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<hash[num]<<endl;
    }
    return 0;

}