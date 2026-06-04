//this program demonstretes the linear search using arrays
#include <iostream>
using namespace std;
int main()
{
    int n,key,found=0,count=0;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the key to be searched: ";
    cin>>key;
    for(int i=0;i<n;i++)
    {
        count++;
        if(arr[i]==key)
        {
            found=1;
            cout<<"key found at index no.: "<<i;
           
            break;
        }
        
    }
    if(found!=1)
    {
        cout<<"key not found";
    }
    cout<<"comparisons made: "<<count;
    return 0;
}