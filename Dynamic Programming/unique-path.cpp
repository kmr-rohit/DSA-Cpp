// Recursive approach 

class Solution {
public:
    int solve(int i , int j ,int m , int n){
        if(i == m-1 && j == n-1){
            return 1;

        }
        else if(i>m-1 || j>n-1){
            return 0;
        }
        
        int right = solve(i, j+1, m, n);
        int down = solve(i+1 , j , m ,n);
        return down +right;
        
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
        
    }
};

// Recursive bottom up approach 
class Solution {
public:
    int solve(int i , int j ,int m , int n){
        if(i == 0 && j == 0){
            return 1;

        }
        else if(i<0 || j<0){
            return 0;
        }
        
        int left = solve(i, j-1, m, n);
        int up = solve(i-1 , j , m ,n);
        return up +left;
        
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};

// Memoisation Approach 

class Solution {
public:
  
   int solve(int m,int n,int i,int j, vector<vector<int>>&dp){
      
    if(i==m-1&&j==n-1){
        return 1;
    }
    if(i<0||j<0||i>m-1||j>n-1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int x=solve(m,n,i+1,j,dp);//for down move:
    int y=solve(m,n,i,j+1,dp);//for right move
    return dp[i][j]= x+y;


   }
   
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(m,n,0,0,dp);
       
    }
};





