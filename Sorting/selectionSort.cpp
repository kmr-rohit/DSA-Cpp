#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr , int n){
  for(int i = 0; i<n; i++){
    for(int j = i+1;j<n;j++){
      if(arr[i]>arr[j]){
        swap(arr[i] , arr[j]);
      }
    }
  }
}
int main(){
  int n;
  cin>>n;
  vector<int> arr;
  for(int i =0 ; i<n; i++){
    int n ;
    cin>>n;
    arr.push_back(n);
  }
  selectionSort(arr , n);
  for(int i =0 ;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;

}

// Time complexity:
//   Best  = Average = Wrost = O(n^2);
// Space Complexity:
//   O(1);