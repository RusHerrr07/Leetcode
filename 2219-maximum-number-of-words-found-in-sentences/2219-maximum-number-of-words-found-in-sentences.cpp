class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;
        for(auto &str:sentences){
            int cnt=0;
            for(auto &ch:str){
                if(ch==' '){
                    cnt++;
                }
            }
            maxi=max(cnt,maxi);
       
        }
        return maxi+1;
        
    }
};