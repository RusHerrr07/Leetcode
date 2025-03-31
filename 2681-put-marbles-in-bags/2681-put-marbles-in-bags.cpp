class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int>scores;
        for(int i=0;i<weights.size()-1;i++){
            scores.push_back(weights[i]+weights[i+1]);
        }
        sort(scores.begin(),scores.end());
        long long  mini=0;
        long long maxi=0;
        int n=scores.size();
        for(int i=0;i<k-1;i++){
            mini+=scores[i];
            maxi+=scores[n-1-i];
        }
        // for(int i=scores.size()-1;i>=k-1;i--){
        //     maxi+=scores[i];
            
            
            
        // }

        return maxi-mini;
        
        
        
        
        
        
    }
};