class Solution {
    int sonal[10001];
    int solve(int i,vector<int>& arr,int target) {
        if(i>=arr.size()-1) return 0;
        if(sonal[i]!=-1) return sonal[i];
        int ans=-1e9;
        for(int j=i+1 ; j<arr.size();++j) {
            int diff = arr[j]-arr[i];
            if(diff >=-target && target>=diff) {
                ans=max(ans,1+solve(j,arr,target));
                
            }
        }
        return sonal[i]=ans;
    }
public:
    int maximumJumps(vector<int>& nums,int target) {
        memset(sonal,-1,sizeof(sonal));
        int val = solve(0,nums,target);
        return val<0?-1:val;
    }
    
    
};