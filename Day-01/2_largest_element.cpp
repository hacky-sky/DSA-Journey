//this program finds the largest and smallest element in an array
#include <iostream>
using namespace std;
int main()
{
  int n,largest,count=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    largest=arr[0];
    for(int i=1;i<n;i++)
    {
        count++;
        if (arr[i]>largest)
        {
            largest=arr[i];
        }
    }
   cout<<"The largest element: "<<largest<<endl;
   /*int smallest=arr[0];
   for(int i=1;i<n;i++)
    {
        count++;
        if (arr[i]<smallest)
        {
            smallest=arr[i];
        }
    }
    cout<<"The smallest element: "<<smallest<<endl;*/
    cout<<"No. of comparisons made: "<<count<<endl;
    return 0;
}