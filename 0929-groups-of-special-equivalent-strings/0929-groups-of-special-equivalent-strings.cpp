/*

this  apprach is acceptable , but this is not good, from this easy to medium problem today i have learned something great----->look at my second approach--------->



class Solution {
private:
bool isValid(string &s1,string &s2){
    int n=s1.size();
     vector<int> even1(26,0),odd1(26,0),even2(26,0),odd2(26,0);

    for (int i =0;i<n;i++) {
        if (i % 2 == 0) {
            even1[s1[i]-'a']++;
            even2[s2[i]-'a']++;
        } else {
            odd1[s1[i]-'a']++;
            odd2[s2[i]-'a']++;
        }
    }

    return even1==even2 && odd1==odd2;

}
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<words.size();i++){
           if(words[i]!="*"){
              cnt++;
              string s1=words[i];
              words[i]="*";
              for(int j=0;j<words.size();j++){
                if(words[j]!="*" && j!=i){
                    string s2=words[j];
                    if(isValid(s1,s2)){
                        words[j]="*";
                    }
                }
              }
           }


           
        }

        return cnt;
    }
};

*/





class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string>s;
        
        for(const string& s1:words){
            vector<int>even1(26,0),odd1(26,0);
            
            for(int i=0;i<s1.size();i++){
                if(i%2==0)even1[s1[i]-'a']++;
                else odd1[s1[i]-'a']++;
            }
            
            string sig;
            for(int i=0;i<26;i++)sig+=to_string(even1[i])+","; 
            for(int i=0;i<26;i++)sig+=to_string(odd1[i])+","; 
            
            s.insert(sig);
        }

        return s.size();
    }
};

