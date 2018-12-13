// 笔记详情 http://note.youdao.com/noteshare?id=5880dc2ff2ba47869bbee1bebafccde2

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> sub;
        find(result, sub, nums, 0);
        return vector<vector<int>> (result.begin(), result.end());
    }
    
    void find (set<vector<int>>& result, vector<int>&sub, vector<int>& nums, int start) {
        if (sub.size() >= 2) {
            result.insert(sub);
        }
        for (int i = start; i < nums.size(); i++) {
            if (sub.size()==0 || nums[i] >= sub.back()) {
                sub.push_back(nums[i]);
                find(result,sub,nums,i + 1);
                sub.pop_back();
            }
        }
    }
};