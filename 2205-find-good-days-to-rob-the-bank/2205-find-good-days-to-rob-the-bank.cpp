class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
     /*
     
       Brute force---->

          vector<int>ans;
        int n=security.size();
        if(time==0){for(int i=0;i<n;i++)ans.push_back(i);return ans;}
        for(int i=time;i<n-time;i++){
            bool flag=true;
            for(int j=i-time+1;j<=i;j++){
                if(security[j]>security[j-1]){flag=false;break;}
            }
            for(int j=i+1;j<=i+time;j++){
                if(security[j]<security[j-1]){flag=false;break;}
            }
            if(flag)ans.push_back(i);
        }
        return ans;

    */
        
        
    //optimal-->
    
        int n=nums.size();
        vector<int>dec(n,1);
        vector<int>inc(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                inc[i]=inc[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                dec[i]=dec[i+1]+1;
            }
        }
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(dec[i]>=(time+1) && inc[i]>=(time+1)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
