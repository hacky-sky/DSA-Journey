//this program demonstrate lexicographically greater arrangement using next permutation function
/*sample input:
3
1 2 3*/
/*sample output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1*/
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
    do {
     for(int x:v){
        cout<<x<<" ";
     }
     cout<<endl;
    }
    while(next_permutation(v.begin(),v.end()));
    return 0;
}