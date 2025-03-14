class Solution {
private:
bool isValid(vector<int>& arr, int mid, int h){
    int cnt = 0;
    for(auto &val:arr){
        cnt += ceil((double)val/mid); 
        if(cnt > h)return false;  
    }
    return cnt <= h;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int ans=*max_element(piles.begin(),piles.end());
        int left=1; 
        int right=ans;
        ans=-1;
        while(right>=left){
            int mid=(left+right)/2;
            if(isValid(piles, mid, h)){ 
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;  
    }
};
