//In an array of n +ve integers, find the element with the highest frequency and the element with the lowest frequency. If there's a tie for lowest, pick the smaller value
/*Sample input:-
arr = [10, 5, 10, 15, 10, 5]*/
/*Sample output:-
Highest = 10 (freq 3), Lowest = 15 (freq 1) */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i]; }
    int maxElement=*max_element(arr,arr+n);

    int hash[maxElement+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1; }

    auto it= max_element(hash, hash+maxElement+1);
    cout<<"Hihest ="<<(it-hash);
    cout<<"(freq "<<*it<<" )";
    
    int lf=hash[maxElement];
    int element=maxElement;
    for(int i=maxElement;i>0;i--){
        if(hash[i]!=0 && hash[i]<=lf){
        lf=hash[i];
        element=i;}
    }
     cout<<"lowest = "<<element<<"(freq "<<lf<<")";
    return 0;
}