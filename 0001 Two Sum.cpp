class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted;
        for (int i = 0; i < nums.size(); i++) {
            sorted.push_back(nums[i]);
        }
        sort(sorted.begin(), sorted.end());
        vector<int>::iterator itL = sorted.begin(), itR = sorted.begin();
        advance(itR, sorted.size() / 2);
        int inR = distance(sorted.begin(), itR);
        while (*itR > target / 2) {
            advance(itR, -1);
            inR--;
        }
        while (*itR < target / 2) {
            advance(itR, 1);
            inR++;
        }
        advance(itL, inR - 1);
        if (target % 2 == 0 && *itR == target / 2 && *itL != *itR) {
            advance(itR, 1);
            advance(itL, 1);
        }
        int inL = distance(sorted.begin(), itL);
        int sum;
        while (inL > -1 && inR < sorted.size()) {
            sum = *itL + *itR;
            if (sum > target && inL > 0) {
                advance(itL, -1);
                inL--;
            } else if (sum < target && inR < sorted.size() - 1) {
                advance(itR, 1);
                inR++;
            } else {
                break;
            }
        }
        vector<int>::iterator L = find(nums.begin(), nums.end(), *itL);
        vector<int>::iterator R;
        if (*itR == *itL) {
            R = find(L + 1, nums.end(), *itR);
        } else {
            R = find(nums.begin(), nums.end(), *itR);
        }
        int ansL = distance(nums.begin(), L);
        int ansR = distance(nums.begin(), R);
        vector<int> result;
        result.push_back(ansL);
        result.push_back(ansR);
        return result;
    }
};