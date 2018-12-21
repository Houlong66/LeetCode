// 笔记详情 http://note.youdao.com/noteshare?id=8c77d44be0205d8dca63b5680838bf23

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       if (nums.size() == 0) {
            return -1;
        }
        int mid = 0;
        int left_sum = 0, right_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > mid) {
                right_sum += nums[i];
            }
        }
        int result = -1;
        while (mid <= nums.size()-1) {
            if (left_sum == right_sum) {
                result = mid;
                break;
            }
            if (mid == nums.size()-1) break;
            left_sum += nums[mid];
            right_sum -= nums[mid+1];
            mid++;
        }
        return result;
    }
};