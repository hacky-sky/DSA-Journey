//this program finds maximum score and prints it with name
/*Sample input:
3
Alice 95
Bob 87
Charlie 76 */
/*Sample output:
topper is: Alice with score 95 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of pairs: "<<endl;
    cin>>n;
    vector<pair<string,int>> v(n);
    cout<<"Enter name and score of students: "<<endl;
    for(pair<string,int> &p:v){
        cin>>p.first>>p.second;
    }
    string topper=v[0].first;
    int maxScore=v[0].second;
    for(int i=0;i<n;i++){
        if(v[i].second>maxScore){
        maxScore=v[i].second;
        topper=v[i].first;}
    }
    cout<<"topper is: "<<topper<<" with score "<<maxScore<<endl;

return 0;
}