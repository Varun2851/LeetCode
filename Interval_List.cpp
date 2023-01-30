class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        int i = 0;
        int j = 0;
        vector<vector<int>>ans;
        

        while(i<n1 and j<n2){
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];

            int s2 = secondList[j][0];
            int e2 = secondList[j][1];
            vector<int>res;

            if(s2<=e1 and s1<=e2){
                
                res.push_back(max(s1,s2));
                res.push_back(min(e1,e2));
                ans.push_back(res);
            }
            if(e1<e2){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};