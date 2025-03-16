class Solution {
private:
    bool isValid(vector<int>&ranks,long long mid,int cars){
        int cnt=0;
        for(auto &val:ranks){
            if(mid>=val)cnt+=sqrt(mid/val);
            if(cnt>=cars)return true;
        }
        return false;
    }

public:
    long long repairCars(vector<int>&ranks,int cars){
        sort(ranks.begin(),ranks.end());
        long long low=1,high=(long long)ranks[0]*cars*cars,ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isValid(ranks,mid,cars)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};
