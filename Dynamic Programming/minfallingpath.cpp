// recursive approach 
class Solution {
public:
   int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix){
    
    // Base Conditions
    if(j<0 || j>=m)
        return 1e9;
    if(i==0)
        return matrix[0][j];
    
   
    
    int up = matrix[i][j] + getMinUtil(i-1,j,m,matrix);
    int leftDiagonal = matrix[i][j] + getMinUtil(i-1,j-1,m,matrix);
    int rightDiagonal = matrix[i][j] + getMinUtil(i-1,j+1,m,matrix);
    
    return min(up,min(leftDiagonal,rightDiagonal));
    
}

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    int maxi = INT_MAX;
    
    for(int j=0; j<m;j++){
        int ans = getMinUtil(n-1,j,m,matrix);
        maxi = min(maxi,ans);
    }
    
    return maxi;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return getMaxPathSum(matrix);
        
    }
};


// memoized approach

class Solution {
public:
   int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, 
){
    
    // Base Conditions
    if(j<0 || j>=m)
        return 1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMinUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMinUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMinUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= min(up,min(leftDiagonal,rightDiagonal));
    
}

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = INT_MAX;
    
    for(int j=0; j<m;j++){
        int ans = getMinUtil(n-1,j,m,matrix,dp);
        maxi = min(maxi,ans);
    }
    
    return maxi;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return getMaxPathSum(matrix);
        
    }
};