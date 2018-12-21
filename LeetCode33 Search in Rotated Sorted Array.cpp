// 笔记详情 http://note.youdao.com/noteshare?id=4e4ff348a742d2c0c137193d8fc6ab77

class Solution {
public
    int search(vectorint& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) return 0;
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left+right)2;
        while (left  right) {
            mid = (left+right)2;
            if (nums[left]==target) return left;
            if (nums[right]==target) return right;
            if (nums[mid]==target) return mid;
            if (nums[mid]nums[left]) {
                if (nums[mid]target) {
                    left = mid + 1;
                }
                else {
                    if (targetnums[left]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            else {
                if (nums[mid]target) {
                    right = mid - 1;
                } else {
                    if (targetnums[left]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};