class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        k=n-k;
        int mini=INT_MAX;
        int j=0;
        int i=0;
        int sum=0;
        while(j<n){
            sum+=card[j];
            while(j-i+1>=k){
                mini=min(sum,mini);
                sum-=card[i];
                i++;

            }
            j++;

        }
        long long total=accumulate(card.begin(),card.end(),0LL);
        return total-mini;
        
        
    }
};