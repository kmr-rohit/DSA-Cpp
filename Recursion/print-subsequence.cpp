#include<bits/stdc++.h>
using namespace std;

void PrintSubsequences(int ind , vector<int>&ans , int arr[] , int n){
  if(ind == n){
    for(auto it : ans){
      cout<<it<<" ";

    }
    cout<<endl;
    return;
  }
  // Pick the ind element
  ans.push_back(arr[ind]);
  PrintSubsequences(ind+1 ,ans , arr, n);
  ans.pop_back();

  // non-pick of ind element
  PrintSubsequences(ind+1 ,ans , arr, n);

  

}


int main(){
  int n = 3;
  int arr[] = {3,1,2};
  vector<int> ans;
  PrintSubsequences(0 ,ans , arr , n );
  return 0;


  
}