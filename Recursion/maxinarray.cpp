#include <iostream>
using namespace std;

int recarray(int arr[] , int n ){
  if(n ==1){
    return arr[0];

  }

  return max(arr[n-1], recarray(arr , n-1));


}

int main()
{
  int arr[] = {1, 4, 5, 6, 2, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<< recarray(arr , n);
  return 0;
}