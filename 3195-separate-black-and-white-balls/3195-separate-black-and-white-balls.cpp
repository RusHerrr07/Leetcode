class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
       
        int x=n-1;
        long long cnt=0;
        int inc=0;
        int i=n-1;
        int j=n-1;
        while(i>=0){
            char ch=s[i];
            if(ch=='1'){
                cnt+=(j-i);
                j--;
            }
            i--;
           
        }

        return cnt;

        
        

        
    }
};