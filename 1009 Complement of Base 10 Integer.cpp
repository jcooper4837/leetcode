class Solution {
public:
    int findComplement(int N) {
        if (N == 0) {
            return 1;
        }
        vector<int> b;
        while (N > 0) {
            b.insert(b.begin(), N % 2);
            N /= 2;
        }
        for (int i = 0; i < b.size(); i++) {
            b[i] = !b[i];
        }
        int res = 0, m = 1;
        while (b.size() > 0) {
            res += b[b.size() - 1] * m;
            b.pop_back();
            m *= 2;
        }
        return res;
    }
};