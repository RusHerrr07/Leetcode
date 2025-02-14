
/*
class ProductOfNumbers {
    stack<int>st;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)  st = stack<int>();
        else  st.push(num);
        
    }
    
    int getProduct(int k) {
        if(st.size()<k)return 0;
        int prod=1;
        stack<int>temp=st;
        while(k!=0){
            prod*=temp.top();
            temp.pop();
            k--;
        }

        return prod;
        
    }
};


*/






class ProductOfNumbers {
public:
map<int,int>mp;
   int idx=1;
    ProductOfNumbers() {
        mp[0]=1;
        
    }
    
    void add(int num) {
        if(num==0){
            mp.clear();
            idx=0;
            mp[idx]=1;
            idx++;
        }
        else{
            mp[idx]=mp[idx-1]*num;
            idx++;
            
        }
        
    }
    
    int getProduct(int k) {
        if(mp.size()<=k)return 0;
        int n=mp.size()-1;
        return mp[n]/mp[n-k];
        
        
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */