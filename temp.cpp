#include<bits/stdc++.h>
using namespace std;

vector<int> farNumber(int N, vector<int> &A) {
        vector<int> res(N , -1);
        if(N == 1){
            return res;
        }
        
        stack<pair<int , int>> st;
        stack<pair<int , int>> temp;
        st.push({A[N-1] , N-1});
        
        for(int i= N-2 ;i>=0;i--){
            if(A[i]<st.top().first){
                st.push({A[i] , i});
            }
        }
        
        
        for(int i = 0;i<N-1;i++){
            if(A[i] > st.top().first){
                while(A[i]>st.top().first && !st.empty()){
                    res[i] = st.top().second;
                    pair<int , int > tempPair;
                    tempPair = st.top();
                    st.pop();
                    temp.push(tempPair);
                }
                
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
            }
            else if(A[i] == st.top().first && i == st.top().second && !st.empty()){
                st.pop();
            }
        }
        return res;
    }


int main(){
  int n = 5;

  vector<int>arr(n);
  for(int i =0;i<n;i++){
    int temp;
    cin>>temp;
    arr[i] = temp;
  }
  vector<int> res = farNumber(n , arr);

  for(int i=0;i<n;i++){
    cout<<res[i]<<" ";
  }
  return 0;
}