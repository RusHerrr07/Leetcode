class Solution {
public:
    int maxScore(string s) {
   

    // int maxi=0;
    // for(int i=1;i<n;i++){
    //     int one=0,zero=0;
    //       for(int backward=0;backward<i;backward++){
    //         if(s[backward]=='0')zero++;
    //       }
    //       for(int forward=i;forward<n;forward++){
    //         if(s[forward]=='1')one++;
    //       }
    //       maxi=max(maxi,zero+one);

    // }
    
    int n=s.length();
    int one =0;
    int zero=0;
    int maxi=0;
    for(auto &i:s){
      if(i=='1')one++;
    }

    if(one==n|| one==0)return n-1;
    int idx=0;
    for(int i=0;i<s.size()-1 ;i++){
      
        if(s[i]=='1'){
            --one;
        }
        else{
            ++zero;
        }

        maxi=max(maxi,zero+one);
       
       
       
    }

    return maxi;

    

    return maxi;
        
    }
};
