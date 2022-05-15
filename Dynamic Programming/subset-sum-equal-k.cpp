// #include<bits/stdc++.h>
// using namespace std;

// bool subsetSumToK(int ind ,int k , vector<int> &arr){
//   if(k == 0){
//     return true;
//   }
//   if(ind == 0){
//     return arr[ind] == k;
//   }

//   bool notTaken = subsetSumToK(ind -1 , k ,arr);

//   bool Taken = false;

//   if(arr[ind]<= k){
//     Taken = subsetSumToK(ind -1 , k - arr[ind] , arr);

//   }

//   return notTaken||Taken;


// }

// int main(){
  
//     int n = 4;
//     vector<int> arr = {1,2,3,4};
//     int k = 56;
//     bool ans =  false;
//     ans = subsetSumToK(n , k ,arr);
//     if(ans == true){
//       cout<<"True"<<endl;
//     }
//     else{
//       cout<<"False"<<endl;
//     }
    

  
  
// }


// Approach 2 - Dyanamic progarming(Memoisation)

#include <bits/stdc++.h>

using namespace std;

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return 1;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}