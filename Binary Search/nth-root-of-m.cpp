//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
  int multiply(int mid , int n){
    int ans = 1;
    for(int i = 1;i<=n;i++){
      ans = ans*mid;
    }
    return ans;
  }
	int NthRoot(int n, int m)
	{
	  int low = 1;
    int high = m;
    

    while(high>low){
      int mid = (low + high)/2;
      if(multiply(mid , n)  == m){
        return mid;
      }
      else if(multiply(mid , n) > m){
        high = mid;
      }
      else{
        low = mid;
      }
    }
    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends