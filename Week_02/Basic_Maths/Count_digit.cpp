//this program counts the number of digits in a given number
/*sample input:
2354*/
/*sample output:
4 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,count=0;
    cout<<"Enter a number: ";
    cin>>n;
    
    // method 1 -- loop approach
    // time complexity: O(log₁₀ n)
    if(n<0)
    n=-n;//handles -ve gracefully 
    do{
        count++;
        n=n/10;
    }while(n!=0);
    cout<<"number of digits:"<<count;

    // method 2 -- log formula
    // time complexity: O(1)
    /* if(n == 0){
    cout << 1;  // 0 has 1 digit
    } 
    else {
    n = abs(n);  // handle negatives
    int count = (int)(log10(n)) + 1;
    cout << count;
    }*/
    return 0;
}

