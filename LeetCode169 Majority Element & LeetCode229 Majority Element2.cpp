// 笔记详情 http://note.youdao.com/noteshare?id=769dc820ded069bd090e60e77e6032f7

// LeetCode 169
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, num;
        for(auto val : nums) {
            if (val == num) {
                count++;
            } else if (count == 0) {
                count = 1;
                num = val;
            }
            else {
                count--;
            }
        }
        return num;
    }
};

// LeetCode 229
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int num1,num2,count1 = 0, count2=0;
        for (auto val : nums) {
            if (val == num1) {
                count1++;
            }
            else if (val == num2) {
                count2++;
            }
            else if (count1 == 0) {
                count1 = 1;
                num1 = val;
            }
            else if (count2 == 0) {
                count2 = 1;
                num2 = val;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0; count2 = 0;
        for(auto val : nums) {
            if(val == num1) {
                count1++;
            }
            else if (val == num2) {
                count2++;
            }
        }
        vector<int> result;
        if (count1 > (nums.size()/3)) {
            result.push_back(num1);
        }
        if (count2 > (nums.size()/3)) {
            result.push_back(num2);
        }
        return result;
    }
};