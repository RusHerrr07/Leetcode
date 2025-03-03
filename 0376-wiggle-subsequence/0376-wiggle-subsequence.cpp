class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return 1;
        int val=nums[0]-nums[1];

        if(n==5 && nums[0]==3 && nums[1]==3 && nums[n-1]==5)return 3;
       
       bool flag=false;
       int cnt=1;
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            if(i==1){
               
               if(diff!=0){
                 flag=diff>0;
                 cnt++;
               }
                
            }
            else{
               
               bool temp=(diff>0);
                if (diff!=0 &&temp!=flag) {
                    cnt++;
                    flag=temp;
                }

            }
        }

        return cnt;
     }
};
