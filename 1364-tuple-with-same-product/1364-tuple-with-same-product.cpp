
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        set<tuple<int,int,int,int>>st;
        map<int,int>mp;
        int n=nums.size();
        int cnt=0;

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {  
                long long prod=nums[i]*nums[j];
                if (mp.count(prod)){
                    cnt+=mp[prod];
                } 
                mp[prod]++;
                
            }
        }

        return cnt*8;
    }
};