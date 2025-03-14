class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        // sort(happiness.begin(),happiness.end());
        // int n=happiness.size();
        // int cnt=0;
        // int idx=n-1;
        // long long ans=0;
        // while(idx>=0 && k>0){
        //     int val=(happiness[idx]-cnt)>=0?(happiness[idx]-cnt):0;
        //     ans+=val;
        //     cnt++;
        //     k--;
        //     idx--;
        // }

        // return ans;

        
        priority_queue<int> pq(happiness.begin(), happiness.end());
        int cnt=0;
        long long ans=0;
        
        while(!pq.empty() && k>0){
            int val=(pq.top()-cnt)>=0?(pq.top()-cnt):0;
            ans+=val;
            pq.pop();
            cnt++;
            k--;
        }

        return ans;
    
        
    }
};