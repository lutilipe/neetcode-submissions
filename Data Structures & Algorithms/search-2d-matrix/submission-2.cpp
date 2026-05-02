class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lowRow = 0;
        int hiRow = n - 1;

        while (hiRow > lowRow) {
            int mid = lowRow + (hiRow-lowRow)/2;
            if (target <= matrix[mid][m-1]) hiRow = mid;
            else lowRow = mid + 1;
        }

        int low = 0;
        int hi = m-1;

        while (hi >= low) {
            int mid = low + (hi-low)/2;
            if (matrix[lowRow][mid] == target) return true;
            if (matrix[lowRow][mid] > target) hi = mid-1;
            else low = mid + 1;
        }

        return false;
    }
};
