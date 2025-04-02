class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sx = startPos[0], sy = startPos[1];
        int dx = homePos[0], dy = homePos[1];
        int cost = 0;
        if (sx < dx) {
            for (int i = sx + 1; i <= dx; i++) cost += rowCosts[i];
        } else {
            for (int i = sx - 1; i >= dx; i--) cost += rowCosts[i];
        }
        if (sy < dy) {
            for (int j = sy + 1; j <= dy; j++) cost += colCosts[j];
        } else {
            for (int j = sy - 1; j >= dy; j--) cost += colCosts[j];
        }

        return cost;
    }
};
