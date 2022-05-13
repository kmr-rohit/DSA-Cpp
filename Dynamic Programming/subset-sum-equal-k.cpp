#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int ind ,int k , vector<int> &arr){
  if(k == 0){
    return true;
  }
  if(ind == 0){
    return arr[ind] == k;
  }

  bool notTaken = subsetSumToK(ind -1 , k ,arr);

  bool Taken = false;

  if(arr[ind]<= k){
    Taken = subsetSumToK(ind -1 , k - arr[ind] , arr);

  }

  return notTaken||Taken;


}

int main(){
  
    int n = 4;
    vector<int> arr = {1,2,3,4};
    int k = 56;
    bool ans =  false;
    ans = subsetSumToK(n , k ,arr);
    if(ans == true){
      cout<<"True"<<endl;
    }
    else{
      cout<<"False"<<endl;
    }
    

  
  
}