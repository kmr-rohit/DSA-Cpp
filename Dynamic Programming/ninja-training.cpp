// Problem link  : https://bit.ly/3ty78Yc

//Recursion approach 

int f(int day , int last , vector<vector<int>> &points){
	if(day == 0){
		int maxi = 0;
        for(int task = 0 ; task<3 ; task++){
			if(task != last){
					maxi = max(maxi , points[0][task]);
				}
        }
        return maxi; 
    }
    
    int maxi = 0;
        for(int task = 0 ; task<3 ; task++){
			if(task != last){
					int point = points[day][task] + f(day-1 , task , points);
                	maxi = max(maxi , point);
				} 
        }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return f(n-1 ,3, points);
}


 // Memoization


 int f(int day , int last , vector<vector<int>> &points , vector<vector<int>> &dp){
    if(dp[day][last] != -1) return dp[day][last];
	if(day == 0){
		int maxi = 0;
        for(int task = 0 ; task<3 ; task++){
			if(task != last){
					maxi = max(maxi , points[0][task]);
				}
        }
        return maxi;  
    }
    int maxi = 0;
        for(int task = 0 ; task<3 ; task++){
			if(task != last){
					int point = points[day][task] + f(day-1 , task , points,dp);
                	maxi = max(maxi , point);
				}    
        }
    return dp[day][last] = maxi;  
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n , vector<int>(4,-1));
    return f(n-1 ,3, points , dp);
}


// tabulation 


int solve(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n , vector<int>(4,-1));
     // Base cases 
    dp[0][0] = max(points[0][1] , points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][1] , points[0][0]);
    dp[0][3] = max(points[0][0] , max(points[0][1], points[0][2]));
                   
    for(int day = 1; day<n ; day++ ){
        for(int last = 0; last<4 ; last ++){
            dp[day][last] = 0;
            for(int task = 0 ; task <3 ; task++){
                if(task != last ){
                    int point = points[day][task]  + dp[day-1][task];
                    dp[day][last] = max(point , dp[day][last]);
                }
            }
        }
    }
    return dp[n-1][3];
}

