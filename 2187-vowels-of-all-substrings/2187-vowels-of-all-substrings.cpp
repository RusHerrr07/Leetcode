class Solution {
public:
    long long countVowels(string word) {
        set<char>st ={'a','e','i','o','u'};
        long long ans=0;
        int n = word.size();

        for (int i=0;i<n;i++) {
            if (st.find(word[i])!=st.end()) {
                ans +=(long long)(i+1)*(n-i);
            }
        }
        return ans;
    }
};
