class Solution {
public:
    int bestClosingTime(string s) {
    int c =0,m=0,mi =0;
    for (int i= 0; i<s.size();i++) {
      int x=s[i];
      if (x=='Y') {
        c++;
        if (c>m) {
          m=c;
          mi=i+1;
        }
      } else {
        c--;
      }
    }
    return mi>0?mi:0;
        
    }
};