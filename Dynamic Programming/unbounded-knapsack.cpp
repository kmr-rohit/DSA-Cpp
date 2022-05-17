// DP - Memoisation


int solve(int ind , vector<int> &profit , vector<int> &weight , int w , vector<vector<int>> &dp){
	if(ind == 0){
		return (w/weight[0]) * profit[0];
	}
	if(dp[ind][w] != -1){
		return dp[ind][w];
	}
	
	int not_taken = solve(ind-1 , profit , weight , w , dp);
	int taken = 0;
	if(weight[ind] <= w){
		taken = profit[ind] + solve(ind, profit , weight , w-weight[ind] , dp);
	}
	
	return dp[ind][w] = max(taken , not_taken);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n , vector<int>(w+1 , -1));
    // Write Your Code Here.
	return solve(n-1 , profit , weight , w ,dp);
}

// DP - Tabulation

int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = -1e9;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}