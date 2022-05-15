// Idea behind is to divide any subset into half of the total sum 
// if sum is odd it cant be divided 
// if sum is even we just check wheather we can make a subset 
// with sum = sum/2 then there will be another subset with sum/2 



class Solution {
public:
    bool subsetSumToK(int ind ,int k , vector<int> &arr , vector<vector<int>> &dp){
  if(k == 0){
    return true;
  }
  if(ind == 0){
    return arr[ind] == k;
  }
  if(dp[ind][k] != -1){
      return dp[ind][k];
  }
  bool notTaken = subsetSumToK(ind -1 , k ,arr, dp);
  bool Taken = false;
  if(arr[ind]<= k){
    Taken = subsetSumToK(ind -1 , k - arr[ind] , arr ,dp);
  }
  return dp[ind][k] = notTaken||Taken;
}


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        else{
            sum = sum/2;
            int n = nums.size();
            vector<vector<int>> dp(n , vector<int>(sum+1 ,-1));
            return subsetSumToK(n-1,sum ,nums , dp);
            
        }
    }
};