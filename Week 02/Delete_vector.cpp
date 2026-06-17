// this program demonstrates the deletion of vector elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements: "<<endl;
    for(int &i:v){
        cin>>i;
    }
    v.pop_back();
    //v.erase(v.begin()+1,v.begin()+3);
    //v.erase(v.begin()+1);
    cout<<"Elements of vector are: "<<endl;
    for(int i:v){
        cout<<i<<endl;
    }
    v.clear();
    cout<<v.size();
    return  0;
}