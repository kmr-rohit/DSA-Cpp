#include<iostream>
using namespace std;
int main(){
  int arr[10]={15,19,23,2,6,7,11,12,13,14 };
  int start=0,end=9,mid;
  while(start<=end){
    mid= start+(end-start)/2;
    if(arr[mid-1]>arr[mid]&&arr[mid+1]>arr[mid])return mid;
    else{
      if(arr[start]>arr[mid])end=mid-1;
      else if(arr[end]<arr[mid])start=mid+1;
      
    }
  }
}