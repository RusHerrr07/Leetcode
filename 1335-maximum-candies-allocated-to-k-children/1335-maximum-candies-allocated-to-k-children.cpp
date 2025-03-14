class Solution {
private:
bool isValid(vector<int>&arr,int n,int mid,int k){
    int cnt=0;
    int idx=0;
    while(idx<n && cnt<k){
       if(arr[idx]<mid){
        break;
       }
       else{
        if(mid>0){
            cnt+=(arr[idx]/mid);

        }
        else{
            break;
        }
        
       }
       idx++;  
    }
    return cnt>=k;
}
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi = INT_MIN;
        int n = candies.size();
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        int left=1;
        int right=sum/k;
        int ans=0;
        
        
       
        sort(candies.begin(),candies.end(),greater<int>());
        while(right>=left){
            int mid=(right+left)/2;
            if(isValid(candies,n,mid,k)){
                ans=max(ans,mid);
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
