#include<bits/stdc++.h>
using namespace std;
int countsum(int ind , vector<int> &a , int sum){
        if(ind == 0){
            if(a[0] == sum && a[0] != -1){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int not_taken  = countsum(ind-1 , a, sum);
        int taken = INT_MIN;
        if(a[ind] == 1){
            if(countsum(ind-1 , a, sum-1) == 0){
                taken =  countsum(ind-1 , a , sum-1);
            }
            else{
                 taken =  1+countsum(ind-1 , a , sum-1);
            }
           
        }
        else{
            if(countsum(ind-1 , a, sum+1) == 1){
                taken = countsum(ind-1 , a, sum+1);
            }
            taken =  1+countsum(ind-1 , a, sum+1);
        }
        return max(taken , not_taken);
    }
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>a(n);
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                a[i] = +1;
            }
            else{
                a[i] = -1;
            }
        }
       
        
        return countsum(n-1 , a,0);
        
    }

int main(){
  int n = 6;

  string s = "(()()(";
  int ans = 0;
  ans = longestValidParentheses(s);
  cout<<ans<<endl;

}