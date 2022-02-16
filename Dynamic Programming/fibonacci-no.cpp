/*
The problem can be solved in 3 ways: 
a. Recursion
b. With memoization technique
c. With tabulation technique

*/
// Memoization solution
#include<bits/stdc++.h>
using namespace std;
int f(int n , vector<int> &dp){
	if(n<=1){
		return n;
	}
	if(dp[n]!= -1){
		return dp[n];
	}
	return dp[n] = f(n-1 , dp) + f(n-2 , dp);

}

int main(){
	int n;
	cin>>n;
	vector<int>dp(n+1 , -1);
	cout<<f(n , dp);

}
// T.C = O(n)
// S.C = O(n) - for recursion stack + O(n) - for dp array ;



// tabulation solution : 

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1 , -1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2 ; i<=n ; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout<<dp[n];
}
// T.C = O(N)
// S.C = O(N)-only for dp array


// space optimised method : making S.C - O(N)
// concept is to use 3 pointers , curri , prev , prev2
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int prev2 = 0;
	int prev = 1;
	for(int i = 2 ; i<=n ; i++){
		int curri = prev2 + prev;
		prev2 = prev;
		prev = curri;

	}
	cout<<prev;
}


