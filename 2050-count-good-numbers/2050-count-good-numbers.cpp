class Solution {
const int mod=1e9+7;
long long binPow(long long a,long long b){
    a%=mod;
    long long ans=1;
    while(b>=1){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;

}
public:
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n-odd;
        long long ans1=binPow(4,odd)%mod;
        long long ans2=binPow(5,even)%mod;
        return (ans1*ans2)%mod;
        
    }
};