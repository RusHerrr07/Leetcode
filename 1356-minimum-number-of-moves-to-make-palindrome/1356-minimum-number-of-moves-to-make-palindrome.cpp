class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size(),cnt=0;
        int i=0,j=n-1;
        while(j>=i){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                int left=i+1,right=j-1;
                while(left<j&&s[left]!=s[j])left++;
                while(right>i&&s[right]!=s[i])right--;
                if(j-right<=left-i){
                    cnt+=j-right;
                    for(int k=right;k<j;k++)swap(s[k],s[k+1]);
                }
                else{
                    cnt+=left-i;
                    for(int k=left;k>i;k--)swap(s[k],s[k-1]);
                }
                i++;
                j--;
            }
        }
        return cnt;
    }
};
