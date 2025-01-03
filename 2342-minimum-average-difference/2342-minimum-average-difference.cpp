class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for (int i=1;i<n;i++) {
            pref[i]=nums[i]+pref[i-1];
        }   
        int mini=INT_MAX,idx=-1;
        for (int i=0;i<n;i++) {
            long long val1=(pref[i]/(i+1));
            long long val2=(i==n-1)?0:(pref[n-1]-pref[i])/(n-i-1);
            int diff=abs(val1-val2);
            if(diff<mini){
                mini=diff;
                idx=i;
            }
        }  
        return idx;   
    }
};
