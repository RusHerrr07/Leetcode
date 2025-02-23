class Solution {
public:
    int minOperations(int n) {
        vector<int>arr(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            int val=(2*i)+1;
            arr[i]=val;
            sum+=arr[i];
        } 
        int target=sum/n;
        int cnt=0;
        int i=0;
        int j=n-1;
        while(j>i){
           
           if(arr[i]==target )i++;
           if(arr[j]==target)j--;
           if(arr[i]!=target && arr[j]!=target){
            int val=min(target-arr[i],arr[j]-target);
            cnt+=val;
            arr[i]+=val;
            arr[j]-=val;
           }
            
        }

        return cnt;
    }
};
