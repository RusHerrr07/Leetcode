class Allocator {
    vector<int> arr;
public:
    Allocator(int n) {
        arr.assign(n, 0);
    }
    
    int allocate(int size, int mID) {
        int count = 0, start = -1;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) {
                if(count == 0) start = i;
                count++;
                if(count == size) {
                    for(int j = start; j < start + size; j++) {
                        arr[j] = mID;
                    }
                    return start;
                }
            } else {
                count = 0;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int freed = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == mID) {
                arr[i] = 0;
                freed++;
            }
        }
        return freed;
    }
};
