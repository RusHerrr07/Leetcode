class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
    /*
    bruteeeee force---------->


        int n=s.size();
        for(auto &i:shifts){
            int start=i[0];
            int end=i[1];
            int dir=i[2];
            if(dir){
                for(int idx=start;idx<=end ;idx++){
                    if(s[idx]=='z'){
                        s[idx]='a';
                    }
                    else{
                        s[idx]++;
                    }
                }

            }
            else{
                 for(int idx=start;idx<=end ;idx++){
                    if(s[idx]=='a'){
                        s[idx]='z';
                    }
                    else{
                        s[idx]--;
                    }
                }
            }
        }
        return s;

        */

        // optimize--->socho beta how we can optimize-->

        /*

        sabse pehle  shifting-letters-i kro jisse tume basis shifting ka knowledge ho jayega and ye bhi same hai with some modification-->


        */
int n = s.size();
vector<long long>track(n+1, 0);

for (auto &i :shifts) {
    int start=i[0];
    int end =i[1];
    int dir =i[2];
    if (dir) {
        track[start]++;
        track[end+1]--;
    }
    else {
        track[start]--;
        track[end+1]++;
    }
}

for (int i=1;i<n;i++) {
    track[i]+=track[i-1];
}


for (int i=0;i<n;i++) {
   if(track[i]<0){
    track[i]=(-abs(track[i]%26)+26)%26;
   }
    s[i]=(char)((s[i]-'a'+track[i]+26)%26+'a');
}
return s;
       

    }
};