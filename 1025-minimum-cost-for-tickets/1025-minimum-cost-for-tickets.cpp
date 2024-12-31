class Solution {
    int sonal[365];
    int solve(vector<int>& days,vector<int>&costs,int idx) {
        int n =days.size();
        if (idx>=n) {
            return 0;
        }
        if (sonal[idx]!=-1) {
            return sonal[idx];
        }
        int one_day =costs[0]+solve(days,costs,idx + 1);
        int i = idx;
        while (i<n&&days[i]<days[idx]+7) {
            i++;
        }
        int one_week=costs[1] +solve(days,costs,i);
        i = idx;
        while (i<n &&days[i]<days[idx]+30) {
            i++;
        }
        int thirty_day=costs[2]+solve(days,costs,i);
        return sonal[idx]=min({one_day,one_week,thirty_day});
    }
public:
    int mincostTickets(vector<int>&days,vector<int>&costs) {
        int n=days.size();
       memset(sonal,-1,sizeof(sonal));
        return solve(days,costs,0);
    }
};
