class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {



        // brute forces---->




    //     int n = s.size();
    //     vector<vector<int>> ans(queries.size(), vector<int>(2, -1));
        
    //     for (int q = 0; q < queries.size(); q++) {
    //         int first = queries[q][0];
    //         int second = queries[q][1];
    //         int target = first ^ second; 

    //         bool found = false;
    //         for (int i = 0; i < n; i++) {
    //             int decimalValue = 0;
    //             for (int j = i; j < n; j++) {
    //                 decimalValue = (decimalValue << 1) | (s[j] - '0');
    //                 if (decimalValue == target) {
    //                     if (!found || (j - i) < (ans[q][1] - ans[q][0])) {
    //                         ans[q] = {i, j};
    //                         found = true;
    //                     }
    //                 }
                    
    //             }
    //         }
    //     }
        
    //     return ans;

// -----------------------------------------------------------------------



// optimizaaaaaaaaaation--->

    // optimal--->sari substring ko unko decimal values ke sath map krlo bc-->


      int n=s.size();
        unordered_map<int,pair<int,int>> xorMap;
        vector<vector<int>> ans(queries.size(),vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=i;j<min(i+32,n);j++){
                val=(val<<1)|(s[j]-'0');
                if(!xorMap.count(val)||(j-i)<(xorMap[val].second-xorMap[val].first)){
                    xorMap[val]={i,j};
                }
            }
        }
        for(int q=0;q<queries.size();q++){
            int first=queries[q][0];
            int second=queries[q][1];
            int target=first^second;
            if(xorMap.count(target)){
                ans[q]={xorMap[target].first,xorMap[target].second};
            }
        }
        return ans;
    }
};
