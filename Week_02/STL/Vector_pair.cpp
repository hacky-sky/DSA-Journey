//this program demonstrates the use of pair in vector.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of pairs: ";
    cin>>n;
    vector<pair<int,int>> v(n);
    for(pair<int,int> &p:v){
        cin>>p.first>>p.second;
    }
    for(pair<int,int>p:v){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}