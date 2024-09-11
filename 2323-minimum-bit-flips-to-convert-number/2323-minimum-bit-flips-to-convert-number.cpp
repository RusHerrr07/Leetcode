class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp=start^goal;
        int cnt=0;
        while(temp){
            if(temp%2)cnt++;
            temp/=2;
        }
        return cnt;
        
    }
};