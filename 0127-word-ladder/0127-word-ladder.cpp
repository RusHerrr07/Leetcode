
class Solution {
private:
    bool isValid(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
                if (diff > 1) return false;
            }
        }
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, bool> mp;
        for (auto& s : wordList) {
            mp[s] = true;
        }
        if (!mp.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); 
        set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [curr, cost] = q.front();
            q.pop();

            if (curr == endWord) return cost;

            for (auto& word : wordList) {
                if (isValid(curr, word) && visited.find(word) == visited.end()) {
                    q.push({word, cost + 1});
                    visited.insert(word);
                }
            }
        }

        return 0;
    }
};
