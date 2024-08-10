class Solution {
private:
    vector<int> p;
    int cnt;
    void dsu(int n1,int n2){
        int up1 = findUp(n1);
        int up2 = findUp(n2);
        if(up1 == up2){
            cnt++;
            return;
        }
        p[up2] = up1;
    }
    int findUp(int node){
        if(node==p[node]) return node;
        return p[node] = findUp(p[node]);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int nn = n+1;

        p.resize(nn*nn);
        cnt = 0;
        for(int i=0; i<nn*nn; i++) p[i]=i;

        for(int i=0; i<nn; i++){
            for(int j=0; j<nn; j++){
                if(i==0 || j==0 || i==n || j==n) 
                    dsu(0,i*nn+j);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '/'){
                    dsu(  (i+1)*nn+j ,  i*nn+(j+1)  );
                }else if(grid[i][j] != ' '){
                    dsu(  i*nn+j ,  (i+1)*nn+(j+1)  );
                } 
            }
        }
        return cnt;
    }
};