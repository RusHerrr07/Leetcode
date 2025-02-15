class Solution {
public:
    int punishmentNumber(int n) {
    int ans=0;
    for(int i=1;i<=n;i++){
        int sqr=i*i;
        string s=to_string(sqr);
        if(isValid(s,i)){
            ans+=sqr;
        }
    }
    return ans;
    }

private:
    bool isValid(string &s,int target){
        int len=s.size();
        for(int mask=0;mask<(1<<(len-1));mask++){
            int sum=0,num=0;
            for(int j=0;j<len;j++){
                num=num*10+(s[j]-'0');
                if(j==len-1 || (mask&(1<<j))){
                    sum+=num;
                    num=0;
                }
            }
            if(sum==target){
                return true;
            }
        }
        return false;
    }
};
