#include<bits/stdc++.h>
using namespace std;

int solve(int ind , vector<int> &weights , vector<int> &values , int maxweight){
  if(ind == 0){
    if(weights[0] <= maxweight){
      return values[0];
    }
    else{
      return 0;
    }
  }

  int not_taken = solve(ind-1 , weights, values,maxweight) + 0;
  int taken = INT_MIN;
  if(weights[ind]<= maxweight){
      taken = solve(ind -1 , weights,values,maxweight-weights[ind])+ values[ind];
  }
  
  return max(taken , not_taken);

}

int main(){
  int n;
  cin>>n;
  vector<int> weights;
  for(int i = 0;i<n;i++){
    int t;
    cin>>t;
    weights.push_back(t);
  }
  vector<int> values;
  for(int i = 0;i<n;i++){
    int t;
    cin>>t;
    values.push_back(t);
  }
  int maxweight;
  cin>>maxweight;

  int ans = solve(n-1 , weights , values , maxweight);
  cout<<ans<<endl;


}

// Dynamic Approach : Memoisation
#include<bits/stdc++.h>
using namespace std;

int solve(int ind , vector<int> &weights , vector<int> &values , int maxweight, vector<vector<int>> &dp){
  if(ind == 0){
    if(weights[0] <= maxweight){
      return values[0];
    }
    else{
      return 0;
    }
  }
  if(dp[ind][maxweight] != -1){
    return dp[ind][maxweight];
  }

  int not_taken = solve(ind-1 , weights, values,maxweight,dp) + 0;
  int taken = INT_MIN;
  if(weights[ind]<= maxweight){
      taken = solve(ind -1 , weights,values,maxweight-weights[ind],dp)+ values[ind];
  }
  
  return  dp[ind][maxweight] =  max(taken , not_taken);

}

int main(){
  int n;
  cin>>n;
  vector<int> weights;
  for(int i = 0;i<n;i++){
    int t;
    cin>>t;
    weights.push_back(t);
  }
  vector<int> values;
  for(int i = 0;i<n;i++){
    int t;
    cin>>t;
    values.push_back(t);
  }
  int maxweight;
  cin>>maxweight;
  vector<vector<int>> dp(n,vector<int>(maxweight+1,-1));
  int ans = solve(n-1 , weights , values , maxweight , dp);
  cout<<ans<<endl;


}

// Tabulation Approach 

#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

int main() {

  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}