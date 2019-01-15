// 笔记详情 http://note.youdao.com/noteshare?id=1162c45d963c950616fcbfa49348189e

// 解法一
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        // 将一对的情侣变成相同的数字
        for (int i = 0; i < n; i++){
            row[i] -= row[i] %2;
        }
        int result = 0;
        for (int i = 0; i < n; i+=2) {
            if (row[i] == row[i+1]) continue;
            for (int j = i+2; j < n; j++) {
                if (row[i] == row[j]) {
                    result++;
                    swap(row[i+1], row[j]);
                    break;
                }
            }
        }
        return result;
    }
};

// 解法二
class Solution {
public:
     int minSwapsCouples(vector<int>& row) {
        int result = 0, n = row.size();
         vector<int> root(n/2,0);
         for (int i = 0; i < n/2; i++) root[i]=i;
         for (int i = 0; i < n; i+=2) {
             int x = find(root, row[i]/2);
             int y = find(root, row[i+1]/2);
             if (x!=y) {
                 result++;
                 root[x] = y;
             }
         }
         return result;
    }
    
    int find(vector<int>& root, int pos) {
        return (pos == root[pos])? pos: find(root,root[pos]);
    }
};

// 解法三
class Solution {
public:
     int minSwapsCouples(vector<int>& row) {
        int result = 0, n = row.size();
         vector<int> root(n/2,0);
         for (int i = 0; i < n/2; i++) root[i]=i;
         for (int i = 0; i < n; i+=2) {
             int x = find(root, row[i]/2);
             int y = find(root, row[i+1]/2);
             if (x!=y) {
                 result++;
                 root[x] = y;
             }
         }
         return result;
    }
    
    int find(vector<int>& root, int pos) {
        return (pos == root[pos])? pos: find(root,root[pos]);
    }
};