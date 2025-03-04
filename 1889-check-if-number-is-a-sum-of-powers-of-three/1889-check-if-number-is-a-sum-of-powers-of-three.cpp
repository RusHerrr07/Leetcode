class Solution {
vector<long long>GetPow(int n){
    long  long  x=1;
    vector<long long >pow;
    pow.push_back(1);
    while(x<=n){
        x*=3;
        pow.push_back(x);

    }
    return pow;
}
public:
    bool checkPowersOfThree(int n) {
        vector<long long>pow=GetPow(n);
        int right=pow.size()-1;
        long long sum=0;
        while(right>=0){
            if(sum+pow[right]<=n){
                sum+=pow[right];
                if(sum==n)return true;
            }
            right--;

        }
        return false;
        
    }
};