// You are given an array/list of ‘N’ integers. You are supposed to return 
// the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
// The first line contains a single integer ‘T’ denoting the number of test cases.

// The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

// The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.
// Sample Input 1:
// 2
// 3
// 1 2 4
// 4
// 2 1 4 9
// Sample Output 1:
// 5
// 11

// Recursive Approach 

int maximumNonAdjacentSumSolve(vector<int> &nums , int ind , vector<int> dp){
    if(dp[ind]!=-1) return dp[ind];
    if(ind<0)return 0;
    if(ind == 0) return nums[0];
    
    int pick = nums[ind] + maximumNonAdjacentSumSolve( nums , ind -2);
    int non_pick = 0 + maximumNonAdjacentSumSolve( nums , ind -1);
    
    return dp[n] = max(pick , non_pick);.
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ind = nums.size() - 1;
    vector<int>dp(n +1 , -1)
    return  maximumNonAdjacentSumSolve(nums , ind , dp);
    
}

// tabulation 
int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}


// space optimisaztion 
int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}


