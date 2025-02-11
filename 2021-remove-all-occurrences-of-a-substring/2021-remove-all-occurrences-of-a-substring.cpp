class Solution {
public:
    string removeOccurrences(string s, string part) {
        // int n=s.size();
        // int m=part.size();
        // for(int i=0;i<n;i++ ){
        //     if(i+m<=n){
        //        string str = s.substr(i, m);
        //         if(str==part){
        //            s.erase(i, m);
        //             n-=m;
        //             i=max(i-m,-1);

        //         }
        //     }
           
        // }
        // return s;


// ----------------------------------------------------------------------


        int m=part.size();

        while(s.find(part)!=string::npos){
            s.erase(s.find(part),m);
        }
        return s;



        
    }
};