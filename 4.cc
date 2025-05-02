#include "stdcc.h"

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        if (m > n) return findMedianSortedArrays(B, A);
        int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = halfLen - i;
            if (i < m && B[j - 1] > A[i])
                imin = i + 1;
            else if (i > 0 && A[i - 1] > B[j])
                imax = i - 1;
            else {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = B[j - 1];
                else if (j == 0)
                    maxLeft = A[i - 1];
                else
                    maxLeft = max(A[i - 1], B[j - 1]);
                if ((m + n) % 2 == 1) return maxLeft;

                int minRight = 0;
                if (i == m)
                    minRight = B[j];
                else if (j == n)
                    minRight = A[i];
                else
                    minRight = min(A[i], B[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};