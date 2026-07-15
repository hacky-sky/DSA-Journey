/* PATTERN LIST:
 Pattern 1: 
****
****
****
****  
Pattern 2:
*
**
***
****
Pattern 3:
1
1 2
1 2 3
1 2 3 4
Pattern 4:
1
2 2
3 3 3
4 4 4 4
Pattern 5:
******
****
***
**
*
Pattern 6:
1 2 3 4 
1 2 3
1 2
1 
Pattern 7:
   *
  ***
 *****
*******
Pattern 8:
*******
 *****
  *** 
   *
Pattern 9:
    *
   ***
  *****
 *******
  *****
   ***
    * 
Pattern 10:
*
**
***
****
***
**
*
Pattern 11:
1
01
101
0101
10101
Pattern 12:
1      1
12    21
123  321
12344321
Pattern 13:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
Pattern 14:
A
AB
ABC
ABCD
Pattern 15:
ABCD
ABC
AB  
A
Pattern 16:
A
BB
CCC
DDDD
Pattern 17:
     A
    ABA
   ABCBA
  ABCDCBA
Pattern 18:
D
CD
BCD
ABCD
Pattern 19:
**********
****  **** 
***    ***
**      **
*        *
*        *
**      **      
***    ***
****  ****
**********
Pattern 20:
*         *
**       **
***     ***
****   ****     
***** *****
****   ****
***     ***
**       **
*         *
Pattern 21:
****
*  *
*  *
****
Pattern 22:
4444444
4333334
4322234     
4321234
4322234
4333334
4444444
*/
#include<bits/stdc++.h>
using namespace std;
/*Pattern 1: 
****
****
****
****  */
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
/*Pattern 2:
*
**
***
****
*/
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
/*Pattern 3:
1
1 2
1 2 3
1 2 3 4*/
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
/*Pattern 4:
1
2 2
3 3 3
4 4 4 4*/
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
        {cout<<i;}
        cout<<endl;}
}
/*Pattern 5:
******
****
***
**
*
*/
void pattern5(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";}
        cout<<endl;}
}
/*Pattern 6:
1 2 3 4 
1 2 3
1 2
1 */
void pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++)
        { cout<<j;}
        cout<<endl;}
}
/*Pattern 7:
   *
  ***
 *****
*******
*/
void pattern7(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
        { cout<<" "; }
        for(int j=1;j<i+i;j++)
        { cout<<"*";}
        cout<<endl;}
}
/*Pattern 8:
*******
 *****
  *** 
   *
*/
void pattern8(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*n-(2*i-1);j++)
        { cout<<"*";}
        cout<<endl;}
}
/*Pattern 9:
    *
   ***
  *****
 *******
  *****
   ***
    * 
*/
void pattern9(int n){
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n-i;j++)
        { cout<<" "; }
        for(int j=1;j<i+i;j++)
        { cout<<"*";}
        cout<<endl;}
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        for(int j=2;j<2*n-(2*i-1);j++)
        { cout<<"*";}
    cout<<endl;}    
}
/*Pattern 10:
*
**
***
****
***
**
*
*/
void pattern10(int n){
    for(int i=1;i<=n;i++){
     for(int j=1;j<=i;j++)
        { cout<<"*";}
        cout<<endl;}
    for(int i=1;i<n;i++){
        for(int j=1;j<n-i+1;j++)
        { cout<<"*";}
    cout<<endl;}   
}
/*Pattern 11:
1
01
101
0101
10101*/
void pattern11(int n){
    for(int i=1;i<=n;i++){
     for(int j=1;j<=i;j++)
        { if((i+j)%2==0)
        cout<<"1";
        else
        cout<<"0";}
        
        cout<<endl;}
    }
 /*Pattern 12:
1      1
12    21
123  321
12344321 */
void pattern12(int n){
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        /*if(j <= i)
         cout << j;
       else
         cout << " ";*/
     cout << (j <= i ? to_string(j) : " ");}
   for (int j=n;j>=1;j--){
       if(j<=i)
        cout<<j;
        else
        cout<<" ";}
   cout<<endl;}
}
/*Pattern 13:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15*/
void pattern13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           cout << num << " ";
        num++;
        }
        cout<<endl;
    } 
}
/*Pattern 14:
A
AB
ABC
ABCD */
void pattern14(int n){
    for(int i=1;i<=n;i++){
        char a='A';
        for(int j=1;j<=i;j++){
            cout<<a;
            a++; }
        cout<<endl; }
}
/*Pattern 15:
ABCD
ABC
AB  
A*/
void pattern15(int n){
    for(int i=1;i<=n;i++){
        char a='A';
        for(int j=1;j<=n-i+1;j++){
            cout<<a;
            a++; }
        cout<<endl; }
}
/*Pattern 16:
A
BB
CCC
DDDD */
void pattern16(int n){
    char a='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<a;}
             a++;
        cout<<endl; }
}
/*Pattern 17:
     A
    ABA
   ABCBA
  ABCDCBA */
void pattern17(int n){
    for (int i=1;i<=n;i++){
        char a='A';
        for(int j=1;j<=n-i;j++)
        { cout<<" "; }
        for(int j=1;j<=i;j++)
        { cout<<a;
            a++;}
        a--;
        for(int j=1;j<i;j++){
           --a;
            cout<<a; }
        cout<<endl;}
    }
/*Pattern 18:
D
CD
BCD
ABCD*/
void pattern18(int n){
    for(int i=1;i<=n;i++){
         char a='A';
            a=a+n-i;
        for(int j=1;j<=i;j++){
            cout<<a;
            a++;
        }
        cout<<endl;
    }
}
/*Pattern 19:
**********
****  **** 
***    ***
**      **
*        *
*        *
**      **      
***    ***
****  ****
 */
void pattern19(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cout<<(j<=n-i+1? "*": " "); }
        for(int j=1;j<=n;j++){
            cout<<(j<i? " ": "*");}
    cout<<endl; }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        cout<<(j<=i? "*" :" ");}
        for (int j=n;j>=1;j--){
        cout<<(j<=i? "*" :" ");}
   cout<<endl;}
}  
/*Pattern 20:
*        *
**      **
***    ***
****  ****     
**********
****  ****
***    ***
**      **
*        *
*/ 
void pattern20(int n){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        cout<<(j<=i? "*" :" ");}
        for (int j=n;j>=1;j--){
        cout<<(j<=i? "*" :" ");}
   cout<<endl;}
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cout<<(j<n-i+1? "*": " "); }
        for(int j=1;j<=n;j++){
            cout<<(j<=i? " ": "*");}
    cout<<endl; } 
}
/*Pattern 21:
****
*  *
*  *
****
*/
void pattern21(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 || i==n)
            cout<<"*";
            else if(j==1 || j==n)
            cout<<"*";
            else 
            cout<<" "; }
        cout<<endl; }
}
/*Pattern 22:
4444444
4333334
4322234     
4321234
4322234
4333334
4444444*/
void pattern22(int n){
    int num=n;
    for(int i=1;i<=2*n-1;i++){
       for(int j=1;j<=2*n-1;j++){
        cout<<n - min({i, j, (2*n-1)-i+1, (2*n-1)-j+1}) + 1;
       }
        cout<<endl;
    }
}

int main()
{
    int t;
    cout<<"Enter test case no. ";
    cin>>t;
    for(int i=0;i<t;i++)
    {int n;
    cout<<"Enter the no.: ";
    cin>>n;
    pattern19(n);}
    return 0;
}
