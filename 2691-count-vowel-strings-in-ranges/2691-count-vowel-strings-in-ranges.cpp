class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        /*

        //brute force------->





        int n=words.size();
        int m=queries.size();
        
        vector<int>ans;
        for(auto &i:queries){
            int start=i[0];
            int end=i[1];
            int cnt=0;
            for(int i=start ;i<=end;i++){
                string s=words[i];
                char ch=s[0];
                char e=s[s.size()-1];
                // if((s[0]=''))
                if((ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u') && (e=='a'|| e=='e'|| e=='i'|| e=='o'|| e=='u')){
                    cnt++;
                }

            }
            ans.push_back(cnt);
        }

        return ans;

        */

        //optimal-->
    // ham pref array main pehle se hi compute krr lete valid string ke coount ko from left to right---->



    

    int n=words.size();
    vector<int>pref(n,0);
    int cnt=0;
    for(int i=0;i<n;i++){
          string s=words[i];
                char ch=s[0];
                char e=s[s.size()-1];
                // if((s[0]=''))
                if((ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u') && (e=='a'|| e=='e'|| e=='i'|| e=='o'|| e=='u')){
                    cnt++;
                }
                pref[i]=cnt;

            }

            /*

            now pref-->[1,1,2,3,4]-->agar statt==0 raha then pref[end] hi ans[i]rehega other wise pref[end]-pref[start-1];


            */

         
            vector<int>ans;
            for(auto &i:queries){
                int start=i[0];
                int end=i[1];
                int val=0;
                start==0?val=pref[end]:val=pref[end]-pref[start-1];
                ans.push_back(val);
        
            }

            return ans;

            

    }




    
        
    
};