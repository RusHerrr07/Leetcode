class Solution {
public:
    vector<int> minOperations(string boxes) {


        /* 


        int n=boxes.size();
        if(n==1)return {0};
        vector<int>ans;
        for(int i=0;i<n;i++){
            long long cnt=0;
            int idx=i-1;
            while(idx>=0){
                if(boxes[idx]=='1'){
                    cnt+=(i-idx);
                }
                idx--;
            }
            idx=i+1;
            while(idx<n){
                if(boxes[idx]=='1'){
                    cnt+=(idx-i);
                }
                idx++;
            }
            ans.push_back(cnt);
        }

        return ans;

        */


        //aajao commulative sum value ki help se BC optimize krte hai isko.....>


        int n=boxes.size();
        vector<int>ans(n,0);
        int val=0;
        int sum=0;
        for(int i=0;i<n;i++){
            ans[i]+=sum;
            val+=(boxes[i]-'0');
            sum+=val;
        }
        val=0,sum=0;
        for(int i=n-1;i>=0;i--){
            ans[i]+=sum;
            val+=(boxes[i]-'0');
            sum+=val;
        }

        return ans;
    }
};