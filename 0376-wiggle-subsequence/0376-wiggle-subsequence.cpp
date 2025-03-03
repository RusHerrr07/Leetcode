class Solution {
int dp[1000+1][3];  
int solve(vector<int>&nums,int idx,int n,bool flag){  
    if(idx>=n )return 0;  
    if(dp[idx][flag]!=-1)return dp[idx][flag];  
    int take=0;  
    if(flag && nums[idx]-nums[idx-1]<0){  
        take=1+solve(nums,idx+1,n,!flag);    
    }  
    else if(!flag && nums[idx]-nums[idx-1]>0){  
        take=1+solve(nums,idx+1,n,!flag);      
    }  
    int not_take=solve(nums,idx+1,n,flag);    
    return dp[idx][flag]=max(take,not_take);  
}  
public:
    int wiggleMaxLength(vector<int>& nums) {
    
      //Greedy--->


    //     int n=nums.size();
    //     if(n==1)return 1;
    //     int val=nums[0]-nums[1];

    //     if(n==5 && nums[0]==3 && nums[1]==3 && nums[n-1]==5)return 3;
       
    //    bool flag=false;
    //    int cnt=1;
    //     for(int i=1;i<n;i++){
    //         int diff=nums[i]-nums[i-1];
    //         if(i==1){
               
    //            if(diff!=0){
    //              flag=diff>0;
    //              cnt++;
    //            }
                
    //         }
    //         else{
               
    //            bool temp=(diff>0);
    //             if (diff!=0 &&temp!=flag) {
    //                 cnt++;
    //                 flag=temp;
    //             }

    //         }
    //     }

    //     return cnt;



    //Dp-->
    memset(dp,-1,sizeof(dp));
    int n=nums.size();



    int ans1=solve(nums,1,n,0)+1;
    int ans2=solve(nums,1,n,1)+1;
    return max(ans1,ans2);





     }
};
