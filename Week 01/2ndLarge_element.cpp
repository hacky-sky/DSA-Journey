//this program displays the second largest element.
#include<iostream>4
#include<climits>
using namespace std;
int main()
//
{
int n;
cout<<"Enter array size: ";
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
int largest=arr[0];
for(int i=0;i<n;i++)
{
    if(arr[i]>largest)
       largest=arr[i];
}
int secondlargest=INT_MIN;
for(int i=0;i<n;i++)
{
    if(arr[i]>secondlargest && arr[i]<largest)
        secondlargest=arr[i];
}
if (secondlargest == INT_MIN)
        cout << "No second largest exists: -1" << endl;
    else
        cout << "Second largest: " << secondlargest << endl;
return 0;
}