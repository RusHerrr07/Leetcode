class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // int setBits =__builtin_popcount(num2);
        // int result =num1;
        // int minDiff =INT_MAX;

        // for (int i=0; i<(1<<31);i++) {
        //     if (__builtin_popcount(i) == setBits) {
        //         int diff =num1 ^ i;
        //         if (diff<minDiff) {
        //             minDiff=diff;
        //             result=i;
        //         }
        //     }
        // }

        // return result;


// ------------------------------------------------------------------------------------
        int setBits=__builtin_popcount(num2), bit = 31, res = 0;
        while (bit>=0 &&setBits>0) {
            if (num1&(1<<bit))res|=(1<<bit),setBits--;
            bit--;
        }
        bit = 0;
        while(setBits>0&&bit<32) {
            if (!(num1&(1<< bit)))res|=(1<<bit),setBits--;
            bit++;
        }
        return res;
    }
};
