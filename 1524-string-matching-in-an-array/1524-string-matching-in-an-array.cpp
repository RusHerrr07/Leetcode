class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        /* 
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            int m=s.size();
            for(int j=0;j<n;j++){
                if(i==j || words[j].size()<m)continue;
                if(words[j].find(s)!=string::npos){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;

        */

    /// aa jao bc optimize karte hai ,,,,,,,,use string maching algo such as--->

// The Naive String Matching Algorithm
// The Rabin-Karp-Algorithm
// Finite Automata
// The Knuth-Morris-Pratt Algorithm
// The Boyer-Moore Algorithm



set<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && automaton_match(words[i], words[j])){
                    ans.insert(words[i]);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }

    void compute_automaton(string s, vector<vector<int>>& aut) {
        s+='#';
        int n=s.size();
        vector<int>pi=prefix_function(s);
        aut.assign(n, vector<int>(26));
        for(int i=0;i<n;i++){
            for(int c=0;c<26;c++){
                if(i>0 && 'a'+c!=s[i])
                    aut[i][c]=aut[pi[i-1]][c];
                else
                    aut[i][c]=i+('a'+c==s[i]);
            }
        }
    }

    bool automaton_match(const string& pattern, const string& text) {
        vector<vector<int>>aut;
        compute_automaton(pattern, aut);
        int state=0;
        for(char c:text){
            state=aut[state][c-'a'];
            if(state==pattern.size()){
                return true;
            }
        }
        return false;
    }

    vector<int> prefix_function(string s) {
        int n=s.size();
        vector<int>pi(n);
        for(int i=1;i<n;i++){
            int j=pi[i-1];
            while(j>0 && s[i]!=s[j])
                j=pi[j-1];
            if(s[i]==s[j])
                j++;
            pi[i]=j;
        }
        return pi;
    }
};
