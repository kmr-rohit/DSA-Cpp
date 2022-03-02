/*
We can solve the problem by 3 methods 
1. Recursion 
2. Memoization
3. Tabulation


*/

// Recursion Method : 

int climbStairs(int n) {
        //  Recursive
        
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }


// Memoization : 

int helper(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=helper(n-1,dp) + helper(n-2,dp);
    }
    
    int climbStairs(int n) {
        
        vector<int>dp(n+1 , -1);
        return helper(n,dp);
    }
};

// Tabulation  Method:

int climbStairs(int n) {
        //DP
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
