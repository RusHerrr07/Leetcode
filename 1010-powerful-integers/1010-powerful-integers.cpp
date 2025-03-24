class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;

        //again hardcodong----->

        if(bound==0){
            return {};
        }
        if(bound==1 && x==1 && y==1){
            return {};
        }
        

        
        if(x == 1 && y == 1) {
            ans.insert(2);
        } else if(x == 1) {
            for(int j = 0; 1 + pow(y, j) <= bound; ++j) {
                ans.insert(1 + pow(y, j));
            }
        } else if(y == 1) {
            for(int i = 0; pow(x, i) + 1 <= bound; ++i) {
                ans.insert(pow(x, i) + 1);
            }
        } else {
            for(int i = 0; pow(x, i) <= bound; ++i) {
                for(int j = 0; pow(y, j) <= bound; ++j) {
                    int val = pow(x, i) + pow(y, j);
                    if(val <= bound) {
                        ans.insert(val);
                    }
                }
                if(pow(x, i) > bound) break;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
