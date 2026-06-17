//this programs prints vector using iterators.
/*Sample input:
5
10 20 30 40 50*/
/*Sample output:
10 20 30 40 50*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: "<<endl;
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements: "<<endl;
    for(int &i:v){
        cin>>i;
    }
    //for(auto it=v.begin();it!=v.end();it++){
    //instead of explicitly writing iterator we can use auto keyword
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
return 0;
}

