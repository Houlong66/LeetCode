// 笔记详情 http://note.youdao.com/noteshare?id=c68226bcafa2f32c7e423f7336643e29

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        int mid;
        while(left <= right) {
            mid = (left+right)/2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
                return mid;
            }
            if (A[mid]>A[mid-1] && A[mid]<A[mid+1]) {
                left = mid + 1;
            }
            if (A[mid]<A[mid-1] && A[mid]>A[mid+1]) {
                right = mid - 1;
            }
        }
    }
};