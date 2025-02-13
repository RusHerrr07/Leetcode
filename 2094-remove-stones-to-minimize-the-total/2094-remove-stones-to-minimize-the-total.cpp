class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {

        priority_queue<int>pq;
        for(auto &i:nums){
            pq.push(i);
        }
        while(k!=0){
             int val=pq.top();
             pq.pop();
             if(val&1){
                val/=2;
                val++;
             }
             else{
                val/=2;
             }
             pq.push(val);
             k--;

        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;    
    }
};