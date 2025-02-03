class Solution {
private:
long long GCD(long long a, long long b) {
    return b ? GCD(b, a % b) : a;
}

long long LCM(long long a, long long b) {
    return (a / GCD(a, b)) * b;  
}
long long findGCD(vector<int>& nums) {
        long long res = nums[0];
        for (int i = 1; i < nums.size(); i++) res = GCD(res, nums[i]);
        return res;
    }
    long long findLCM(vector<int>& nums) {
        long long res = nums[0];
        for (int i = 1; i < nums.size(); i++) res = LCM(res, nums[i]);
        return res;
    }
public:
    long long maxScore(vector<int>& nums) {
        long long ans=findLCM(nums)*findGCD(nums);
        int n=nums.size();
        if(n==1){
            return nums[0]*nums[0];
        }

        for(int i=0;i<n;i++){
           vector<int>temp;
           for(int j=0;j<n;j++){
            if(j!=i){
                temp.push_back(nums[j]);
            }
           }
           ans=max(ans,findLCM(temp)*findGCD(temp));
        }
        return ans;

        //-->note-->agar or bhi jyada effcient optimization chaiye then use multiset ,so you would be able to maintain the insertion and deletion in less time;

        // resources used -->https://cp-algorithms.com/algebra/euclid-algorithm.html
        
        
    }
};