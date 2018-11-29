// 笔记链接： http://note.youdao.com/noteshare?id=c7943eb3a74ca556c0869ee00c2f2995
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string result = to_string(t->val);
        if (t->left) {
            result += "(" + tree2str(t->left) + ")";
        }
        else if (t->right) {
            result += "()";
        }
        if (t->right) {
            result += "(" + tree2str(t->right) + ")";
        }
        return result;
    }
};