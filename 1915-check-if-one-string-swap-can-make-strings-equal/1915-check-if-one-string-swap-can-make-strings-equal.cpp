class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       
/* journey from 10% to 100% beats--->o(n)time o(1)space---->*/

// threee aproaches--->


//------------------------------------------------------------------------

    // int n=s1.size();
    // //for string 1-->
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         swap(s1[i],s1[j]);
    //         if(s1==s2)return true;
    //         swap(s1[i],s1[j]);
    //     }
    // }

    // // for string 2-->

    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         swap(s2[i],s2[j]);
    //         if(s1==s2)return true;
    //         swap(s2[i],s2[j]);
    //     }
    // }

    // return false;

    ///----------------------------------------------------------------------



    // int n=s2.size();
    
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         swap(s2[i],s2[j]);
    //         if(s1==s2)return true;
    //         swap(s2[i],s2[j]);

    //      swap(s1[i],s1[j]);
    //         if(s1==s2)return true;
    //         swap(s1[i],s1[j]);




    //     }
    // }

    // return false;


//-----------------------------------------------------------------------
// best solution in the world-->

      int cnt=0;
      int idx1=-1;
      int idx2=-1;
        if(s1==s2)return true;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt==1){
                    idx1=i;
                }
                else if(cnt==2){
                    idx2=i;
                }
                if(cnt>2)return false;
             }
        }
        int n=s2.size();
    //    if (n == 2) {
    //     if (s1[0] > s1[1]) swap(s1[0], s1[1]);
    //     if (s2[0] > s2[1]) swap(s2[0], s2[1]);
    //    return s1 == s2;
    //    }

        bool flag =false;
        if(cnt==2){
            swap(s1[idx1],s1[idx2]);
            if(s1==s2)return true;
            swap(s1[idx1],s1[idx2]);
            swap(s2[idx1],s2[idx2]);
            if(s1==s2)return true;
            

            
        }

        return false;
        



      
        
    }
};
