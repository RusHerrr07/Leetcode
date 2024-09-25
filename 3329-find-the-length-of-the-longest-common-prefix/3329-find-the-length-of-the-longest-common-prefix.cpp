class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        map<string,int>mp;
        int n=arr1.size();
        for(int i=0;i<n;i++){
            string temp=to_string(arr1[i]);
            string pref="";
            for(auto &j:temp){
                pref+=j;
                mp[pref]++;
            }
        }
        int maxi=0;
        n=arr2.size();
        for(int i=0;i<n;i++){
            string temp=to_string(arr2[i]);

            string pref="";
            for(auto &j:temp){
                pref+=j;
                if(mp.count(pref)){
                  int size=pref.size();
                  maxi=max(maxi,size);
                }
            }
        }

        return maxi;
        
    }
};