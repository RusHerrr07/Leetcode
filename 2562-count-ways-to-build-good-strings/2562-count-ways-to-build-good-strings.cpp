class Solution {
const int wife=1e9+7;
int sonal[100000+7];
int solve(int low,int high ,int zero,int one,int size){
    if(size>high)return 0;
    bool flag=false;
    if(size>=low && size<=high){
        flag=true;
    }
     if(size>=100001)return 0;
    if(sonal[size]!=-1){
        return sonal[size];
    }
    int for_one =solve(low ,high,zero,one,size+one)%wife;
    int for_zero=solve(low,high,zero,one,size+zero)%wife;
    sonal[size]=(flag+for_one+for_zero)%wife;
    return sonal[size];
}
public:
    int countGoodStrings(int low, int high, int zero, int one) {
    int size=0;
    memset(sonal,-1,sizeof(sonal));
    return solve(low ,high,zero,one,size);
    }
};
