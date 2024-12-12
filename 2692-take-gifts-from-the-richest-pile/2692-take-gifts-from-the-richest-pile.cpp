class Solution {
public:
    long long pickGifts(vector<int>& nums, int k) {
        

        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        priority_queue<int>pq;
        for(auto &&i:nums){
            pq.push(i);
        }
        while(k!=0){
            int val=pq.top();
            if(val>1){
                pq.pop();
                pq.push(sqrt(val));
                sum-=(val-sqrt(val));
            }
            else{
                break;
            }
            k--;
        }
        return sum;
    }
};