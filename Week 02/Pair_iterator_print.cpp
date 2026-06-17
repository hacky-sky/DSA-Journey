//this program displays vector pair using iterators
/*Sample input:
3
1 2
3 4
5 6*/
/*Sample output:
1 2
3 4
5 6*/
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
     for(vector<pair<int,int>>::iterator it=v.begin();it!=v.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}