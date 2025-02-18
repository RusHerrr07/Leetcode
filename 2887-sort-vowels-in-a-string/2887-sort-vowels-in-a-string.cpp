class Solution {
public:
    set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string sortVowels(string s) {
        vector<pair<int, char>> p;
        for (auto &i : s) {
            if (st.find(i) != st.end()) {
                p.push_back({int(i), i});
            }
        }
        sort(p.begin(), p.end());

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) {
                s[i] = p[j].second;
                j++;
            }
        }
        return s;
    }
};
