class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        char c;
        bool cont = true;
        int i = 0;
        while (cont) {
            if (strs.size() == 0 || strs[0].length() == i) {
                break;
            }
            c = strs[0].at(i);
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].length()== i || c != strs[j].at(i)) {
                    cont = false;
                    break;
                }
            }
            if (cont) {
                s += c;
            }
            i++;
        }
        return s;
    }
};