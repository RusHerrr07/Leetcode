class Solution {
public:
    int minAddToMakeValid(string s) {
        int temp=0;
        int cnt=0;
        int n=s.size();
        for(auto &i:s){
            if(i=='('){
                temp++;
            }
            else{
                if(temp>0)temp--;
                else cnt++;
            }
        }

        return temp+cnt;
        
    }
};