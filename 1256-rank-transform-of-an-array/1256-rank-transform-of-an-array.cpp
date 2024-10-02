class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // if (arr.empty()) return {};
        // vector<pair<int, int>> p;
        // for (int i = 0; i < arr.size(); i++) {
        //     p.push_back({arr[i], i});
        // }
        // sort(p.begin(), p.end());
        // int n = arr.size();
        // vector<int> ans(n, 0);
        // int rank = 1;
        // ans[p[0].second] = rank;
        // for (int i = 1; i < n; i++) {
        //     if (p[i].first != p[i - 1].first) rank++;
        //     ans[p[i].second] = rank;
        // }
        // return ans;


       // ----------------------------------------------
 int n=arr.size();
  vector<int>ans(n,0);
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
  for(int i=0;i<arr.size();i++){
    pq.push({arr[i],i});
  }
  
  int rank=1;
  while(!pq.empty()){
    int val=pq.top().first;
    int idx=pq.top().second;
      pq.pop();
    ans[idx]=rank;
    while( !pq.empty() && pq.top().first==val){
       idx = pq.top().second;
       pq.pop();
       ans[idx] = rank;

    }
    rank++;

  }

  return ans;

    
    }
};
