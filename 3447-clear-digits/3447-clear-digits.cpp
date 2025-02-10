
class Solution {
public:
    string clearDigits(string s) {
    // bool flag=true;
    
    //     for(int i=0;i<s.size();i++){
    //         int n=s.size();
    //         if(isdigit(s[i])){
    //             int left=i-1,right=i+1;
    //             while(left>=0 && !isalpha(s[left])) left--;
    //             while(right<n && !isalpha(s[right])) right++;
    //             if(left>=0 && (i-left<=right-i)){
    //                 s.erase(left,1);
    //                 i--;
    //             } 
    //             else if(right<n){
    //                 s.erase(right,1);
    //             }
    //             s.erase(i,1);
    //             flag=true;
    //             break;
    //         }
    //     }
    
    // return s;
    bool flag =false;
    while(!flag){
        for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(isdigit(ch)){
            int left=i;
            while(left>=0 && !isalpha(s[left]))left--;
            if(isalpha(s[left])){
                s.erase(left,1);
                i--;
            }
            s.erase(i,1);
        }

    }
    flag=true;
    for(int j=0;j<s.size();j++){
        if(isdigit(s[j])){
            flag=false;
        }

    }

    }
    
    return s;


    
    }
};
