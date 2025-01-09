class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
    // int n=words.size();
    // int cnt=0;
    // for(auto &&i:words){
    //     if(i.size()>=pref.size() && pref==i.substr(0,pref.size()))cnt++;
    // }
    // return cnt;



    //  Knuth-Morris-Pratt (KMP) algooooo----->

    
    int cnt=0;
    for(auto &&word:words){
        bool isPrefix=true;
        for(int i=0;i<pref.size()&&i<word.size();++i){
            if(word[i]!=pref[i]){
                isPrefix=false;
                break;
            }
        }
        if(isPrefix&&pref.size()<=word.size())cnt++;
    }
    return cnt;
    
        
    }
};