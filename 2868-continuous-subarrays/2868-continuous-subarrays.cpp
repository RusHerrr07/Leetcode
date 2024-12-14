class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

       int n=nums.size();
       long long cnt = n;
       unordered_map<int,int> mp;
       long long ans=0;
       int maxi=0;
       int mini=1e9+1;
       long long i=0;
       long long j=-1;

       while(i<n && j<n){
            while(j==-1 || (j<n && (maxi-mini)<=2)){
                j++;
                if(j==n){
                    break;
                }
                mp[nums[j]]++;
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
            }
            while(i<j && maxi-mini>2){
                ans+=(j-i);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;

                if(mp[maxi]==0){
                    if(mp.count(maxi-1)){
                        maxi=maxi-1;
                    }
                    else if(mp.count(maxi-2)){
                        maxi=maxi-2;
                    }
                }
                if(mp[mini]==0){
                    if(mp.count(mini+1)){
                        mini=mini+1;
                    }
                    else if(mp.count(mini+2)){
                        mini=mini+2;
                    }
                }

                if(i==j){
                    mini=nums[j];
                    maxi=nums[j];
                }
            }
       }

       while(i<j){
            if(maxi-mini<=2){
                ans+=j-i;
            }
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;

            if(mp[maxi]==0){
                if(mp.count(maxi-1)){
                    maxi=maxi-1;
                }
                else if(mp.count(maxi-2)){
                    maxi=maxi-2;
                }
            }
            if(mp[mini]==0){
                if(mp.count(mini+1)){
                    mini=mini+1;
                }
                else if(mp.count(mini+2)){
                    mini=mini+2;
                }
            }
       }

       return ans;
    }
};
