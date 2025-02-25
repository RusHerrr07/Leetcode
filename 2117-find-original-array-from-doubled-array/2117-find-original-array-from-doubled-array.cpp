class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n&1)return {};
        vector<int>ans;
        map<int,int>mp;
        sort(changed.begin(),changed.end());
        for(int i=0;i<n;i++)mp[changed[i]]++;
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0)continue;
            if(mp[changed[i]*2]==0)return {};
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
    }
};
