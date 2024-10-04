class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = accumulate(skill.begin(), skill.end(), 0);
        if (n == 2) 
        return (skill[0] * skill[1]);
        int need = sum / (n / 2);
        sort(skill.begin(), skill.end());
        int i = 0, j = n - 1;
        long long ans = 0;
        while (j > i) {
            if (skill[j] + skill[i] != need) return -1;
            ans += (skill[j] * skill[i]);
            i++; 
            j--;
        }
        return ans;
    }
};
