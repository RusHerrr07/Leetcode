class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
        for(auto &i:nums){
            pq.push(i);
        }
        int cnt=0;
        cout<<pq.top();
        if(pq.top()>=k)return 0;
        // return 2;
        while(true){
            if(pq.size()<2)break;
            long long int first=pq.top();
            if(first>=k){
                break;
            }
            pq.pop();
            long long int sec=pq.top();
            pq.pop();
            long long int val=min(first,sec)*2+max(first,sec);
            pq.push(val);
            cnt++;
            
            
        }

        return cnt;

        
    }
};