class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = nums.size();
        for (int i = 1; i < res; i++) {
            if (nums[i] == nums[i-1]) {
                nums.erase(nums.begin() + i);
                res--;
                i--;
            }
        }
        return res;
    }
};