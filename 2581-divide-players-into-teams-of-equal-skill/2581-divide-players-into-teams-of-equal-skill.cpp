class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        int n=skills.size();
        sort(skills .begin(),skills.end());
        long long ans=0;
        int temp=skills[0]+skills[n-1];
        int left=0;
        int right=n-1;
        while(right>left)
        {
            if(skills[left]+skills[right]==temp){
                 ans+=(skills[left]*skills[right]);
            }
            else{
                return -1;
            }
            left++;
            right--;
        }

        return ans;
       


        
    }
};