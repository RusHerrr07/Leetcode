class Solution {
vector<int>nums={1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string>s={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
public:
    string intToRoman(int num) {
        string ans="";
        for(int i=0;i<nums.size();i++){
            while(num>=nums[i]){
                num-=nums[i];
                ans+=s[i];
        
            }
        }
        return ans;
        
    }
};