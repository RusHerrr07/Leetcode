class Solution {
public:
    int Sliding_Window(vector<int>& arr, int k, int n) {
        int cnt=0,i=0,j=0;
        while(j<n){
            if(j>0 && arr[j]==arr[j-1]){ 
                i=j;
            }
            if(j-i+1==k){ 
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int val=k-1;
        int n=colors.size();
        vector<int> colors2;
        if(k>n)return 0;

        for(int i=(n-(k-1));i<n;i++){ 
            colors2.push_back(colors[i]);
        }

        for(int i=0;i<val;i++){
            colors2.push_back(colors[i]);
            
        }
        for(auto &i:colors2){
            cout<<i<<" ";
        }
        int ans1=Sliding_Window(colors2,k,colors2.size());
        int ans2=Sliding_Window(colors,k,colors.size());
        return ans1+ans2;
    }
};
