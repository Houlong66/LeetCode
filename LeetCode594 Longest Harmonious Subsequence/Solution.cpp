// 笔记详情 http://note.youdao.com/noteshare?id=9f200230a2b7af10d37b14d34475d771

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size()==0||nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int max = 0, temp = nums[0], index = 0, begin = 0;
        bool isSecond = false;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i]!=temp) {
                if (isSecond) {
                    max = max > (i-begin)? max: (i-begin);
                    begin = index;
                }
                if (i == nums.size()) break;
                if (nums[i] - temp == 1) {
                    isSecond = true;
                } else {
                    isSecond = false;
                    begin = i;
                }
                temp = nums[i];
                index = i;
            }
        }
        return max;
    }
};