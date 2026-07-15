//this program will display if array elements are in ascending order or not.
#include <iostream>
using namespace std;
int main()
{
  int n,count=0;
  cout<<"Enter size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(int i=1;i<n;i++)
  {
    if(arr[i-1]<arr[i])
        count++;
    else
    break;
  }  
  if (count==n-1)
  {
    cout<<"Yes, it is in ascending order"<<endl;
  }
  else
  {
    cout<<"No it is not is ascending order";
  }
  return 0;
}
