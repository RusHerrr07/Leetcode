class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans ="";
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            auto [first, ch1] = pq.top();
            pq.pop();
            if (!pq.empty()) {
            auto [sec, ch2] = pq.top();
            pq.pop();

            if (first >= 2 && first > sec) {
                ans += ch1;
                ans += ch1;
                first -= 2;
            } else {
                ans += ch1;
                first -= 1;
            }

            if (sec > 0) {
                ans += ch2;
                sec -= 1;
            }

            if (first > 0) pq.push({first, ch1});
            if (sec > 0) pq.push({sec, ch2});
            }

            else{
                if (first >= 2) {
                    ans += ch1, ans += ch1;
                    first-=2;
                }
                else {
                    ans += ch1;
                    first-=1;
                }
                
            }
            
        }
        return ans;
    }
};
