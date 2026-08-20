//demonstrating hashing of characters
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string:"<<endl;
    cin>>s;
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int q;
    cin>>q;
    cout<<"Enter characters to find their frequency:";
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}