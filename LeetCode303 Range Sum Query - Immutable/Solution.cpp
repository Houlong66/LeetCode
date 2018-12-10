// 笔记详情 http://note.youdao.com/noteshare?id=96ef5fc24487bf718148ba06289b6b9a

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        }
        sums.push_back(nums[0]);
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            sums.push_back(sums[i-1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return sums[j];
        }
        return sums[j] - sums[i-1];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */