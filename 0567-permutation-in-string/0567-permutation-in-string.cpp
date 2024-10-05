class Solution {

    bool allZero(vector<int>&hash){
        for(auto &i:hash){
            if(i!=0){
                return false;
            }
        }

        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
    
       /*
       brute forceeee--->O(n×klogk)

        sort(s1.begin(), s1.end());
        int n = s2.length();
        for(int i = 0; i < n; i++) {
            string temp = "";
            for(int j = i; j < n; j++) {
                temp += s2[j];
                if(temp.size() == s1.size()) {
                    break;
                }
            }
            sort(temp.begin(), temp.end());
            if(temp == s1) {
                return true;
            }
        }
        return false;

        */


        //Sliding window ka kamal--->o(n);

        vector<int> hash(26, 0);
        int k = s1.length();
        int n = s2.length();

        for(auto &i : s1) {
            char ch = i;
            hash[ch - 'a']++;
        }

        int i = 0, j = 0;
        while(j < n) {
            char ch = s2[j];
            hash[ch - 'a']--;
            if(j - i + 1 == k) {
                if(allZero(hash)) {
                    return true;
                }
                hash[s2[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false;   
    }
};
