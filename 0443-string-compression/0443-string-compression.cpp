class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int len=0;
        while(i<n){
            char ch=chars[i];
            int cnt=0;
            while(i<n && chars[i]==ch){
                cnt++;
                i++;
            }
            chars[len++]=ch;
            if(cnt>1){
                for(char c:to_string(cnt)){
                    chars[len++]=c;
                }
            }
        }
        return len;
    }
};
