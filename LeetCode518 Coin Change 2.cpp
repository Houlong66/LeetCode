// 笔记详情 http://note.youdao.com/noteshare?id=8e1ff26a21dcc5b87fdd7e29ef7da9de

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j>= coins[i]) {
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};