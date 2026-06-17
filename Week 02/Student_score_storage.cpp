//this program demonstrates fusion of vector and pair with differnet data types
/*sample input:
3
Alice 95
Bob 87
Charlie 76*/
/*sample output:
Alice 95
Bob 87
Charlie 76*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of pairs: ";
    cin>>n;
    vector<pair<string,int>> v(n);
    cout<<"Enter name and score of students: ";
    for(pair<string,int> &p:v){
        cin>>p.first>>p.second;
    }
    cout<<"The name and scores are: ";
    for(pair<string,int>p:v){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}