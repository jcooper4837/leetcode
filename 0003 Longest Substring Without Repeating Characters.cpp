class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> used;
        int max = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            used.push_back(s[i]);
            for (int j = 0; j < used.size() - 1; j++) {
                if (s[i] == used[j]) {
                    while (used.size() > 0) {
                        used.pop_back();
                    }
                    i -= count;
                    count = -1;
                    break;
                }
            }
            count++;
            if (count > max) {
                max++;
            }
        }
        return max;
    }
};