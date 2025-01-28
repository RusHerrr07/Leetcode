
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int maxi = 0;
        int n = matrix.size(), m = matrix[0].size();

        for (int j = 0; j < m; j++) {
            int pref = 0;
            for (int i = 0; i < n; i++) {
                matrix[i][j] = (matrix[i][j] == 1) ? pref + 1 : 0;
                pref = matrix[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) break;
                maxi = max(maxi, matrix[i][j] * (j + 1));
            }
        }

        return maxi;
    }
};
