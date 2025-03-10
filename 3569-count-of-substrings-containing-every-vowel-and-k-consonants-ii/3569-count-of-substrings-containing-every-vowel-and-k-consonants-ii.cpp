class Solution {
long long sliding_window(string &word,int k){
    set<char> st = {'a', 'e', 'i', 'o', 'u'};
        map<char, int> mp;
        int i = 0, j = 0;
        long long cnt = 0;
        int n = word.size();
        int conso = 0;

        while (j < n) {
            char ch = word[j];
            if (st.find(ch) != st.end()) {
                mp[ch]++;
            } else {
                conso++;
            }

            while (mp.size() == 5 && conso >k) {
                if (st.find(word[i]) != st.end()) {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0) {
                        mp.erase(word[i]);
                    }
                } else {
                    conso--;
                }
                i++;
                
            }

            // while (conso > k) {
            //     if (st.find(word[i]) != st.end()) {
            //         mp[word[i]]--;
            //         if (mp[word[i]] == 0) {
            //             mp.erase(word[i]);
            //         }
            //     } else {
            //         conso--;
            //     }
            //     i++;
              
            // }
            cnt+=(j-i+1);


            j++;
        }

        return cnt;

    
}
public:
    long long countOfSubstrings(string word, int k) {
        // set<char> st = {'a', 'e', 'i', 'o', 'u'};
        // map<char, int> mp;
        // int i = 0, j = 0;
        // int cnt = 0;
        // int n = word.size();
        // int conso = 0;

        // while (j < n) {
        //     char ch = word[j];
        //     if (st.find(ch) != st.end()) {
        //         mp[ch]++;
        //     } else {
        //         conso++;
        //     }

        //     while (mp.size() == 5 && conso == k) {
        //         if (st.find(word[i]) != st.end()) {
        //             mp[word[i]]--;
        //             if (mp[word[i]] == 0) {
        //                 mp.erase(word[i]);
        //             }
        //         } else {
        //             conso--;
        //         }
        //         i++;
        //         cnt++;
        //     }

        //     while (conso > k) {
        //         if (st.find(word[i]) != st.end()) {
        //             mp[word[i]]--;
        //             if (mp[word[i]] == 0) {
        //                 mp.erase(word[i]);
        //             }
        //         } else {
        //             conso--;
        //         }
        //         i++;
              
        //     }

        //     j++;
        // }

        // // mp.clear();
        // // conso=0;
        // // for(auto &i:word){
        // //     if(st.find(i)!=st.end())mp[i]++ ;
        // //     else conso++;
        // // }

        // // if(mp.size()==5 && conso==k )cnt++;


        long long ans1= sliding_window(word,k);
        long long ans2=sliding_window(word,k-1);
        return ans1-ans2;
    }
};