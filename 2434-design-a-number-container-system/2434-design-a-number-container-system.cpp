class NumberContainers {
public:
    map<int,set<int>>st;
    map<int,int>mp;
    NumberContainers(){} 
    
    void change(int index, int number) {
        // int val=mp[index];
        // auto&temp=st[val];
        // temp.erase(idx);
        // sy
        // if(temp.empty()){
            
        // }

        int val=mp[index];
        st[val].erase(index);
        auto &temp=st[val];
        if(temp.empty()){
            st.erase(val);
        }
        mp[index]=number;
        st[number].insert(index);
        
        
        
    }
    
    int find(int number) { 
        int ans=-1;
        if(st.count(number) &&!st[number].empty()) {  
            ans=*st[number].begin();  
        } 
        return ans;  
    }

};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */