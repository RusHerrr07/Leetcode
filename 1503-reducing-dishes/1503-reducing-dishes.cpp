class Solution {
public:
    int maxSatisfaction(vector<int>& dish) {
        sort(dish.begin(), dish.end());
        // int maxi = 0;
        // int n = dish.size();
        // int x=n;
        // if (dish[n - 1] <= 0) return 0;
        // for (int i = 0; i < n; i++) {
        //     int rem = x;
        //     int j = n - 1;
        //     int val = 0;
        //     while (j >= i) {
        //         val = val + (dish[j] * rem);
        //         rem--;
        //         j--;
        //     }
        //     maxi = max(maxi, val);
        //     x--;
        // }
        // return maxi;






         sort(dish.begin(),dish.end());
        int maxi=0;
        int n = dish.size();
        if (dish[n - 1] <= 0) return 0;
        
        int val = 0;
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += dish[i];
            val += sum;
            maxi = max(maxi, val);
        }

        return maxi;
    }
};
