//this program adds the the pairs of vectors and display the output
/*Sampple input:
3
3 4
10 2
5 9*/
/*Sample output:
Pair 1: 3 + 4 = 7
Pair 2: 10 + 2 = 12
Pair 3: 5 + 9 = 14 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num=1;
    cout<<"Enter no. of pairs: ";
    cin>>n;
    vector<pair<int,int>> v(n);
    for(pair<int,int> &p:v){
        cin>>p.first>>p.second;
    }
    for(pair<int,int> p:v){
        int sum=p.first+p.second;
        cout<<"Pair "<<num<<" : "<<p.first<<" + "<<p.second<<" = "<<sum<<endl;
        num++;
    }
return 0;
}