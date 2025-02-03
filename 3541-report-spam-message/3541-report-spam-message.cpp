/* class TrieNode{
public:
    unordered_map<char,TrieNode*> c;
    bool e;
    int cnt;
    TrieNode():e(false),cnt(0){}
};

class Trie{
public:
    TrieNode* r;
    Trie(){
        r=new TrieNode();
    }
    void insert(string& w){
        TrieNode* n=r;
        for(char ch:w){
            if(n->c.find(ch)==n->c.end())
                n->c[ch]=new TrieNode();
            n=n->c[ch];
        }
        n->e=true;
        n->cnt++;
    }
    int search(const string& w){
        TrieNode* n=r;
        for(char ch:w){
            if(n->c.find(ch)==n->c.end()) return 0;
            n=n->c[ch];
        }
        return n->cnt;
    }
};

class Solution{
public:
    bool reportSpam(vector<string>& m,vector<string>& b){
        unordered_set<string> s(b.begin(),b.end());
        Trie t;
        for(string& x:m)
            t.insert(x);
        int c=0;
        for(const string& x:s){
            int y=t.search(x);
            if(y!=0) c+=y;
            if(c>=2) return true;
        }
        return false;
    }
};

*/


// Easy and best Approach use hashSet of HashMap-->

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& banned) {

        set<string>st(banned.begin(),banned.end());
        int cnt=0;
        for(auto &i:message){
            if(st.find(i)!=st.end())cnt++;
        }

        return cnt>1;
        
    }
};