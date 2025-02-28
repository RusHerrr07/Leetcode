class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int val=0;
            if(i&1)val=k;
            else val=(m-k)%m;
            for(int j=0;j<m;j++){
                int idx=(j+val)%m;
                if(idx<0)idx+=m;
                if(mat[i][j]!=mat[i][idx])return false;
            }
        }
        return true;
    }
};
