//this program displays divisors of a number
/*sample input: 36*/
/*sample output:
1 2 3 4 6 9 12 18 36 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
     cout<<"Enter the number: ";
    cin>>n;

    vector<int>v;
      for (int i=1;i<=sqrt(n);i++)
      {
        if(n%i==0) {v.push_back(i);
        if( (n/i)!=i) v.push_back(n/i);}
      }
      //Time complexity of sorting is O(n log n)
      //so total TC = O(sqrt n)+O(n log n)
      sort(v.begin(),v.end());
      for(auto it:v)  {cout<<it<<" ";}

    /*for(int i=1;i<=n;i++){
        if(n%i==0)
        cout<<i<<" ";
    }*/
        return 0;
}
/* EXPLANATION:-
                    |  simple loop         |  optimized loop (√n way)
    time complexity |     O(n)             |         O(√n)
    output order    | sorted automatically |      unsorted
    duplicate issue |  no problem          |   needs extra condition
    code simplicity |  clean and simple    |   slightly more complex
    
    for small numbers like 36, the difference between O(n) and O(√n) is invisible. both feel instant.
    but for a number like 1,000,000,000:

    O(n) → 1 billion steps
    O(√n) → about 31,623 steps*/
