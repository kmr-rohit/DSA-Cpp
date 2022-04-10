//https://leetcode.com/problems/house-robber/

class Solution {
public:
    int solve(vector<int>& nums , int ind ){
      if(ind == nums.size()-1){
        return 0;
      }

      // Condition for picking
      int pick = INT_MIN;
      if(ind<n-1){
           pick = nums[ind] + solve(nums , ind +2 );
      }
      // non picked
      int notpick = 0 + solve(nums , ind +1);

      return max(pick , notpick);
    }
    int rob(vector<int>& nums) {
      return solve(nums , 0);
        
    }
};