// 笔记详情 http://note.youdao.com/noteshare?id=6c484e402c195d436ce5364225c58b89

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right) {
            mid = (left+right)/2;
            if (mid == 1 && nums[0] != nums[mid]) {
                return nums[0];
            }
            if (mid == nums.size() - 2 && nums[mid] != nums[nums.size() - 1]) {
                return nums[nums.size() - 1];
            }
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }
            if (nums[mid] == nums[mid-1]) {
                if (mid%2 == 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] == nums[mid+1]) {
                if (mid%2 == 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    }
};