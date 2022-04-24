#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr , int n){
  for(int i = 0 ; i<n-1 ;i++){
    bool swapped = false;
    for(int j =0 ; j<n-i-1 ; j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j] , arr[j+1]);
        swapped = true;
      }
    }
    if(swapped == false){
      break;
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
  bubbleSort(arr , n);
  for(int i =0 ;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}

// Time complexity:
//   Best  =Omega(n)
// Average = Wrost = O(n^2);
// Space Complexity:
//   O(1);
// No of Comparision : n(n-1)/2;
