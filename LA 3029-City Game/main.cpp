
// The same idea of a leetcode.


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> checkmatrix;
        vector<vector<int>> left;
        vector<vector<int>> right;
        int ans = 0;
        if (matrix.size() == 0) return 0;
        checkmatrix.resize(matrix.size());
        left.resize(matrix.size());
        right.resize(matrix.size());
        for (auto& x: checkmatrix){
            x.resize(matrix[0].size());
        }
        for (auto& x: left){
            x.resize(matrix[0].size());
        }
        for (auto& x: right){
            x.resize(matrix[0].size());
        }
        for (int i = 0; i < matrix.size(); i++){
            int lo = -1;
            int hi = matrix[0].size();
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == '0'){
                    lo = j;
                    checkmatrix[i][j] = 0;
                    left[i][j] = 0;
                }
                else{
                    checkmatrix[i][j] = i==0 ? 1:checkmatrix[i-1][j]+1;
                    left[i][j] = i==0 ? lo+1 : max(lo+1, left[i-1][j]);
                }
            }
            for (int j = matrix[0].size()-1; j >=0; j--){
                if (matrix[i][j] == '0'){
                    hi = j;
                    right[i][j] = matrix[0].size();
                }
                else {
                    checkmatrix[i][j] = i==0? 1: checkmatrix[i-1][j]+1;
                    right[i][j] = i==0 ? hi-1 : min(hi-1, right[i-1][j]);
                    if (checkmatrix[i][j]*(right[i][j]-left[i][j]+1) > ans){
                        ans = checkmatrix[i][j]*(right[i][j]-left[i][j]+1);
                    }
                }
                
                
            }
        }
        return ans;
    }
};
