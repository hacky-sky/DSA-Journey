//this program demonstrates the use of min and max function
/*sample input:
5
40 10 30 20 50*/
/*sample output:
minimum: 10
maximum: 50*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: "<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of vector: "<<endl;
    for (int &x:v){
        cin>>x;
    }
    cout<<"Maximum :"<<*max_element(v.begin(),v.end())<<endl;
    cout<<"Minimum :"<<*min_element(v.begin(),v.end());
    return 0;
}