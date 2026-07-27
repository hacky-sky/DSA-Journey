//reversing an array using recursion
/*Sample input:-
arr = {1, 2, 3, 4, 5} */
/*Sample output:-
arr = {5, 4, 3, 2, 1} */
#include<bits/stdc++.h>
using namespace std;
//This is using vector-indices:
void reverse(int l,int r,vector<int> &arr){
    if( l>=r) return ;
     int temp= arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
     reverse(l+1,r-1,arr);
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
}
    reverse(0,n-1,arr);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//This is raw method:
/*void reverse(int *l,int *r,int n){
    if( l>=r) return ;
     int temp= *l;
    *l=*r;
    *r=temp;
  
    ++l;
    --r;
     reverse(l,r,n);
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *l=&arr[0];
    int *r=&arr[n-1];
    reverse(l,r,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/