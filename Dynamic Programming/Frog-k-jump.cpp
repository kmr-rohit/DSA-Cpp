
// Problem Statement
// There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h 
// i
// ​
//  .

// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

// If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of ∣h 
// is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.

// Constraints
// All values in input are integers.
// 2≤N≤10 
// 5
 
// 1≤K≤100
// 1≤h 
// i
// ​
//  ≤10 
// 4
 

 
// Sample Input 1 
// Copy
// 5 3
// 10 30 40 50 20
// Sample Output 1 
// Copy
// 30
// If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30.





//Recursion Top-bottom approach
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &Heights , int k)
{
    if(n ==0)return 0;
    int minsteps = INT_MAX;
    int jump = 0;
    for(int j = 1 ; j<= k ;j++){
      if(n-j>0){
        jump = frogJump(n-j , Heights , k) + abs(Heights[n] - Heights[n-j]) ;
      }
      
      minsteps = min(jump ,minsteps);
    }
    return minsteps;
    
}

int main(){
  int k;
  cin>>k;
  vector<int>Heights{10,30,40,50,20};
  int n = Heights.size();
  cout<<frogJump( n , Heights , k);

}


// memoization;
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &Heights , int k , vector<int> &dp)
{
    if(n ==0)return 0;
    int minsteps = INT_MAX;
    int jump = 0;
    for(int j = 1 ; j<= k ;j++){
      if(dp[j] != -1){
        return dp[j];
      }
      if(n-j>0){
        jump = frogJump(n-j , Heights , k, dp) + abs(Heights[n] - Heights[n-j]) ;
      }
      
      minsteps = dp[j]= min(jump ,minsteps);
    }
    return minsteps;
    
}

int main(){
  int k;
  cin>>k;
  vector<int>Heights{10,30,40,50,20};

  int n = Heights.size();
  vector<int> dp(n+1 , -1);
  cout<<frogJump( n , Heights , k , dp);

}



