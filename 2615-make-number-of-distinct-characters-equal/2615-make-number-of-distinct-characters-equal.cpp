class Solution {
public:
    bool isItPossible(string s1, string s2) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto &i:s1){
            mp1[i]++;
        }
        for(auto &i:s2){
            mp2[i]++;
        }
        // if(mp1.size() == mp2.size()) return true;
        // if(mp1.size() > mp2.size()) swap(mp1, mp2);

        // set<char> st;
        // for(auto &i : mp1){
        //     if(i.second > 1 ){
        //         st.insert(i.first);
        //     }
        // }

        // if(st.empty()) return false;
        // int i = 0;
        // while(i < s2.size()){
        //     if(mp1[s2[i]] == 0 && mp2[s2[i]] > 1 ){
        //         mp1[s2[i]]++;
        //         // st.erase(st.begin());
        //     }
        //     if(mp1.size() == mp2.size()) return true;
        //     i++;
        // }

        // return false;

        for(auto i='a';i<='z';i++){
            for(auto j='a';j<='z';j++){
                if(mp1.count(i) && mp2.count(j)){
                      // if(mp1[i]>0){
                    mp1[i]--;
                    if(mp1[i]==0)mp1.erase(i);
                // }
                mp1[j]++;
                // if(mp2[j]>0){
                    mp2[j]--;
                    if(mp2[j]==0)mp2.erase(j);
                // }
                mp2[i]++;
                if(mp1.size()==mp2.size())return true;
                
                mp1[j]--;
                if(mp1[j]==0)mp1.erase(j);
                mp2[i]--;
                if(mp2[i]==0)mp2.erase(i);
                
                mp1[i]++;
                mp2[j]++;
            

                }
            }
              
        }

        return false;







    
    }
};
