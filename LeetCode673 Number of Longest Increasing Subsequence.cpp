// 笔记详情 http://note.youdao.com/noteshare?id=2564076364b395f81d666b304bfc6862
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_dp = 1, result = 0;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (nums[j] < nums[i] && dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
            max_dp = max(max_dp, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == max_dp) {
                result += cnt[i];
            }
        }
        return result;
    }
};