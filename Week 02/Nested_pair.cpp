//this program demonstrate the use of nested pair.
#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,pair<int,int>>p;
    cin>>p.first>>p.second.first>>p.second.second;
    cout<<p.first<<endl;
    cout<<p.second.second<<endl<<p.second.first;
    return 0;
}