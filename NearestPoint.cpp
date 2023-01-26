//static bool compare()

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        int n = points.size();
        for(int i = 0; i<n; i++){
            if(points[i][0] == x || points[i][1] == y){
                int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
                pq.push({distance,i});
            }
        }
        if(!pq.empty()){
            return pq.top().second;
            pq.pop();
        }
        return -1;
    }
};