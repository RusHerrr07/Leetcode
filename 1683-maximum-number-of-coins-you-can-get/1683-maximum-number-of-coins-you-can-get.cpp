class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans=0;
        int i=0;
        int j=piles.size()
        -1;
        while(j>i){
            ans+=piles[j-1];
            j-=2;
            i++;
        }
        return ans;
    }
};