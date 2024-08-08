class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result(rows * cols, vector<int>(2));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = rStart, c = cStart, directionIndex = 0, steps = 1, resultIndex = 0;
        result[resultIndex++] = {r, c};
        
        while (resultIndex < rows * cols) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    r += directions[directionIndex][0];
                    c += directions[directionIndex][1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result[resultIndex++] = {r, c};
                    }
                }
                directionIndex = (directionIndex + 1) % 4;
            }
            steps++;
        }
        return result;
    }
};
