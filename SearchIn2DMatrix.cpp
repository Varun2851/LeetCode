class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            int l=0;
            int h=matrix[i].size()-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]<target)
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return false;
    }
};