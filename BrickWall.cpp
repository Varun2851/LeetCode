class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>mp;
        int res = 0;
        for(auto row : wall){
            int width = 0;

            for(int i = 0; i<row.size()-1; i++){
                width = width+row[i];
                mp[width]++;

                res = max(res,mp[width]);
            }
        }
        return wall.size()-res;
    }
};