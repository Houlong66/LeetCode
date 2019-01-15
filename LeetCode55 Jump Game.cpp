// 笔记详情：http://note.youdao.com/noteshare?id=3eaf09ebe19d88f244ac848718b97c74

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 当当前位置超过最大跳跃距离时，即无法到达最后位置。
            if (i > maxReach) return false;
            maxReach = i + nums[i] > maxReach? i + nums[i] : maxReach;
            if (maxReach >= nums.size()-1) return true;
        }
        return false;
    }
};