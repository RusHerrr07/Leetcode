class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>output;
         set<vector<int>> set;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int k=j+1;
            int l=n-1;
            while(l>k)
            {
            long long sum=long(nums[i])+long(nums[j])+long(nums[k])+long(nums[l]);
            if(sum==target)
            {
                 set.insert({nums[i], nums[j], nums[k], nums[l]});
            
                k++;
                l--;
                
            }
            else if(sum<target)
            {
                k++;
            }
            else
            {
                l--;
            }
        }
        }
    }

for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
        
    
};