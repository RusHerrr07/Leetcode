class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>st={'a','e','i','o','u'};
        int i=0;
        int j=0;
        int n=s.size();
        int cnt=0;
        int maxi=0;
        while(j<n){
            char ch=s[j];
            if(st.find(ch)!=st.end()){
                cnt++;
            }
            while(j-i+1>=k){
                maxi=max(maxi,cnt);
                if(st.find(s[i])!=st.end()){
                    cnt--;
                }
                i++;
            }
            j++;

        }
        return maxi;
        
    }
};