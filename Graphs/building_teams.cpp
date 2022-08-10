class Solution {
public:
    bool isValid(vector<int> & piles ,long long  int h  , long long int k, long long int n){
        long long int hourscnt = 0;
        
        for(int i=0;i<n;i++){
            long long int div = piles[i]/k;
            hourscnt += div;
            if(piles[i]%k){
                hourscnt++;
            }
            if(hourscnt>h){
                return false;
            }
        }
        
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long int low = 1;
        long long int high = 0;
        high = accumulate(piles.begin() , piles.end() , high);
        long long int res = -1;
        while(low<= high){
            long long int mid = low + (high - low)/2;
            if(isValid(piles , h , mid , n)){
                res = mid;
                high = mid -1;
            }
            else{
               low = mid +1;
            }
        }
        return res;
        
    }
};