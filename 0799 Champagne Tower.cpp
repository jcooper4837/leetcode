class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101, vector<double>(101));
        double d;
        t[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                d = ((t[i][j] - 1.0) / 2.0);
                if (d > 0) {
                    t[i + 1][j] += d;
                    t[i + 1][j + 1] += d;
                }
            }
        }
        return t[query_row][query_glass];
    }
};