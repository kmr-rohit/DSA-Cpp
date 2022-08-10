//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans(2 , -1);
    int i = 0;
    int j = n-1;
    
    while(i<j){
        int mid  = (i+j)/2;
        if(arr[mid] < x){
            i = mid+1;
        }
        else{
            j = mid;
        }
    }
    
    if(arr[i] == x){
        ans[0] = i;
    }
    
    
    // find the last occruence.
    
    // reseting j to last 
    j = n-1;
    
    while(i<j){
        int mid = (i+j)/2 + 1;
        if(arr[mid] > x ){
            j = mid-1;
        }
        else{
            i = mid;
        }
    }
    
    if(arr[j] ==x){
        ans[1] = j;
    }
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends