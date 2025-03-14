class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.begin(),happiness.end());
        int n=happiness.size();
        int cnt=0;
        int idx=n-1;
        long long ans=0;
        while(idx>=0 && k>0){
            int val=(happiness[idx]-cnt)>=0?(happiness[idx]-cnt):0;
            ans+=val;
            cnt++;
            k--;
            idx--;
        }

        return ans;

    
    }
};