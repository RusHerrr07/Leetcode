class Solution {
private:
    bool isValid(string &s){
       int i=0;
       int j=s.size()/2;
       int sum1=0;
       int sum2=0;
       while(i<s.size()/2 && j<s.size()){
        sum1+=(s[i]-'0');
        sum2+=(s[j]-'0');
        i++;
        j++;

       } 
       return sum1==sum2;

    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2==0 && isValid((s))) cnt++;
        }
        return cnt;

    }
};
