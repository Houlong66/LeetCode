// 笔记详情 http://note.youdao.com/noteshare?id=154c41eb2f1ce47b52a7af2ec7457814

class Solution {
public:
    int findComplement(int num) {
        int bits = (log(num)/log(2)) + 1;
        return (int)(pow(2,bits) - 1 - num);
    }
};