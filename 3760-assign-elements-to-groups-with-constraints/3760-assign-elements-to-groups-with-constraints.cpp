class Solution {
private:
    set<int> getDivisors(int n) {
        set<int> d; 
        for(int i=1; i*i<=n; i++) {
            if(n%i==0) {
                d.insert(i);
                if(i!=n/i) d.insert(n/i);
            }
        }
        return d;
       
       
        

    

    

    }

public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n=groups.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> mp;
        for(int i=0; i<elements.size(); i++) 
            if(mp.find(elements[i])==mp.end()) mp[elements[i]]=i;

        for(int i=0; i<n; i++) {
            int mini=-1;
            set<int> d=getDivisors(groups[i]);
            for(int x:d) 
                if(mp.count(x)) mini=(mini==-1)?mp[x]:min(mp[x],mini);
                ans[i]=mini;
           
        }
        return ans;
     
    }
};
