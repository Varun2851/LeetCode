class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>>ans;

    for(auto interval : intervals)
    { 
       if(interval[1]< newInterval[0]) ///intervals = [[1,3]] , new interwal = [12.15]
       {
           ans.push_back(interval);
       } 
       else if(interval[0]>newInterval[1]) // intervals = [[10,12]] , new interval = [3,8]
       {
           ans.push_back(newInterval);
           newInterval = interval;
       }
       else // case of overlapping , if end of previous interval is large then the strat of new interval
       {
           newInterval[0] = min(newInterval[0],interval[0]);
           newInterval[1] = max(newInterval[1],interval[1]);
       }
    }

    ans.push_back(newInterval);
    return ans;
    }
};