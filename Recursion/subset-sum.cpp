#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void solve(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      solve(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      solve(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    solve(0, arr, n, ans, 0);
    return ans;
  }
};


int main() {
  vector < int > arr{2,3,5,6,8,10};
  Solution ob;
  vector < int > ans = ob.subsetSums(arr, arr.size());
  sort(ans.begin(), ans.end());
  map<int, int> m ;
  int val = 5;
  unordered_map<int , int> freq;
  for(int const &i : ans)
    {
      freq[i]++;

    }
    cout<<freq[val]<<endl;


  
  

  return 0;
}
