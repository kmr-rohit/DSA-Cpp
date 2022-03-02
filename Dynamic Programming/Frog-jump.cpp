/*
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. 
HEIGHT[i] is the height of the (i+1)th stair.
If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
For Example
If the given ‘HEIGHT’ array is [10,20,30,10], 
the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and 
then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of stairs in the staircase,

The next line contains ‘HEIGHT’ array.
Output Format:
For each test case, return an integer corresponding to the minimum energy lost to reach the last stair.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.


*/


//Recursion Top-bottom approach
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &Heights)
{
    if(n ==0)return 0;
    int left = frogJump(n -1 , Heights) + abs(Heights[n] - Heights[n-1]);
    int right = INT16_MAX;
    if(n>1){
     right = frogJump(n-2 , Heights) + abs(Heights[n] - Heights[n-2]);
        
    }
    return min(left , right);
}

int main(){
  vector<int>Heights{30,10,60 , 10 , 60 , 50};
  int n = Heights.size()-1;
  cout<<frogJump( n , Heights);
  

}

// MEMOIZATION
#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &Heights , vector<int> &dp)
{
    if(n ==0)return dp[0] =0;
    if(dp[n] != -1){
      return dp[n];
    }
    int left = frogJump(n -1 , Heights ,dp) + abs(Heights[n] - Heights[n-1]);
    int right = INT16_MAX;
    if(n>1){
     right = frogJump(n-2 , Heights , dp ) + abs(Heights[n] - Heights[n-2]);
        
    }
    return dp[n] = min(left , right);
}

int main(){
  vector<int>Heights{30,10,60 , 10 , 60 , 50};
  int n = Heights.size()-1;
  vector<int> dp(n +1 , -1);
  cout<<frogJump( n , Heights , dp);
  

}

//Tabulation 
#include<bits/stdc++.h>
using namespace std;


int main(){
  vector<int>Heights{30,10,60 , 10 , 60 , 50};
  int n = Heights.size()-1;
  vector<int> dp(n +1 , -1);
  dp[0]=0;
  int left , right = INT_MAX;
  for(int i = 1 ; i<=n+1 ; i++  ){
    left  = dp[i-1] +  abs(Heights[i] - Heights[i-1]);
    if(i>=2){
      right = dp[i-2] + abs(Heights[i] - Heights[i-2]);
    }
    dp[i] = min(left , right);

    
  }
  cout<<dp[n];
}




