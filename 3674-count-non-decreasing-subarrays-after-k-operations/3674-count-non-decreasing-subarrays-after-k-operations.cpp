
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        // int n=nums.size();
        // long long total=(long long)n*(n+1)/2;
        // long long cnt=0;

        // for (int i =0;i<n;i++) {
        //     long long maxi=nums[i];
        //     long long diff=0;

        //     for (int j=i+1;j<n;j++) {
        //         if (nums[j]>=maxi) {
        //             maxi=nums[j];
        //         } else {
        //             diff+=(maxi-nums[j]); 
        //         }
                
        //         if (diff>k) {
        //             cnt +=(n-j); 
        //             break; 
        //         }
        //     }
        // }
        // return total-cnt;

         long long res=0;
        int n=nums.size();
        int r=-1;
        long long t=0;
        int last;
        vector<int> nb(n,n);
        vector<int> h;
        vector<long long> c{0};
        long long s=0;
        for(int q:nums){
            c.push_back(s+=q);
        }
        for(int i=0;i<n;++i){
            while(!h.empty()&&nums[h.back()]<=nums[i]){
                nb[h.back()]=i;
                h.pop_back();
            }
            h.push_back(i);
        }
        for(int l=0;l<n;++l){
            if(r<=l){
                r=l;
                t=0;
                last=nums[l];
            }
            if(r>0&&l<r){
                last=max(last,nums[r-1]);
            }
            while(r<n&&t<=k){
                if(t+max(0,last-nums[r])>k){
                    break;
                }
                t+=max(0,last-nums[r]);
                last=max(last,nums[r]);
                ++r;
            }
            // cout<<"l="<<l<<" r="<<r;
            res+=r-l;
            if(l+1<n&&nums[l+1]<nums[l]){
                int nl=nb[l];
                int z=l+1;
                while(z<nl&&z<r){
                    if(nl>=r){
                        last=nums[z];
                    }
                    int nz=nb[z];
                    t-=(nums[l]-nums[z])*(min(r,nz)-z);
                    z=nz;
                }
            }
            // cout<<" t="<<t<<" last="<<last<<endl;
        }

        return res;


    }
};
