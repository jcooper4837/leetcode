class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        int par = 0, cur = 0, bra = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.at(i)) {
                case '(':
                    par++;
                    v.push_back(s.at(i));
                    break;
                case '{':
                    cur++;
                    v.push_back(s.at(i));
                    break;
                case '[':
                    bra++;
                    v.push_back(s.at(i));
                    break;
                case ')':
                    if (v.size() > 0 && v.at(v.size() - 1) == '(') {
                        par--;
                        v.pop_back();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (v.size() > 0 && v.at(v.size() - 1) == '{') {
                        cur--;
                        v.pop_back();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (v.size() > 0 && v.at(v.size() - 1) == '[') {
                        bra--;
                        v.pop_back();
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        if (par == 0 && cur == 0 && bra == 0) {
            return true;
        }
        return false;
    }
};