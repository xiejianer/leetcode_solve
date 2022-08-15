#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            int len = arr.size();
            if (len == 0) return arr;
            quickSort(arr, 0, len - 1);
            int startIdx = 1;
            int lastNum = arr[0];
            arr[0] = 1;
            for (int i = 1; i < len; ++i) {
                if (arr[i] != lastNum) {
                    ++startIdx;
                }
                arr[i] = startIdx;
            }
            return arr;
        }
        void quickSort(vector<int>& vec, int left, int right) {
            if (left == right) return;
            int pivot = vec[left];
            int startPos = left + 1;
            int endPos = right;
            while (startPos < endPos) {
                if (vec[startPos] > pivot) {
                    swap(vec[startPos], vec[endPos--]);
                } else {
                    ++startPos;
                }
            }
            if (vec[startPos] < pivot) {
                swap(vec[startPos], vec[left]);
            }
            quickSort(vec, left, startPos - 1);
            quickSort(vec, startPos + 1, right);
        }
};

int main()
{
    return 0;
}
