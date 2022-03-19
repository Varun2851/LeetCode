//https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>ans;
        int startRow = 0;
        int EndRow= row-1;
        int startCol = 0;
        int EndCol = col-1;
        
        while(startRow <= EndRow and startCol <= EndCol){
            //1.Print from startCol to EndCol
            for(int i = startCol; i<=EndCol; i++){
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            //2.Print from startRow to EndRow
            for(int i = startRow; i<=EndRow; i++){
                ans.push_back(matrix[i][EndCol]);
            }
            EndCol--;
            //3.Print from EndCol to StartCol
            if(startRow <= EndRow){
            for(int i = EndCol; i>=startCol; i--){
                ans.push_back(matrix[EndRow][i]);
            }
            EndRow--;
            }
            //4.Print From  EndRow to EndCol
            if(startCol <= EndCol){
            for(int i = EndRow; i>= startRow; i--){
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
        
        }
        return ans;
    }
};