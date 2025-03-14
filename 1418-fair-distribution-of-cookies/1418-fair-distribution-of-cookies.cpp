
class Solution {
private:
    bool Solve(vector<int>& cookies,vector<int>& child, int i, int mid, int k) {
        if (i==cookies.size()) return true;
        for (int j=0;j<k;j++) {
            if (child[j]+cookies[i]<=mid) {
                child[j]+=cookies[i];
                if (Solve(cookies,child,i+1,mid,k)) return true;
                child[j]-=cookies[i];
            }
            if (child[j]==0) break;
        }
        return false;
    }

    bool isValid(vector<int>& cookies,int mid,int k) {
        vector<int> child(k,0);
        return Solve(cookies, child,0,mid,k);
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        int low=*max_element(cookies.begin(),cookies.end());
        int high=accumulate(cookies.begin(),cookies.end(), 0LL);
        int ans=high;

        while (high>=low) {
            int mid=(low+high)/2;
            if (isValid(cookies,mid,k)) {
                ans=mid;
                high=mid-1;
            } else {
                low =mid+1;
            }
        }
        return ans;
    }
};


