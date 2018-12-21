// 笔记详情 http://note.youdao.com/noteshare?id=57a6d21084c5d15745737abee79d30d7

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        combine(result, path, candidates, target, 0);
        
        return result;
    }
    
    void combine(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int start) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            combine(result, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};