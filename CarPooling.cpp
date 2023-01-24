// 1st approach using map
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int>mp;
        for (int i = 0; i < trips.size(); ++i) {
             mp[trips[i][1]] += trips[i][0]; // picking up the passengers resulting in occupany in seats
             mp[trips[i][2]] -= trips[i][0]; //droping off the passengers resulting in reduction of filling seats
        }
        for (auto X : mp) { 
            capacity -= X.second;
            
            if (capacity < 0) return false;
        }
        return true;
    }
};

//2nd approach
class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int i=0;i<trips.size();++i)
        {
            heap.push({trips[i][1],trips[i][0]});
            heap.push({trips[i][2],-trips[i][0]});
        }
        int onboard =0;
        while(!heap.empty())
        {
            onboard += heap.top().second;
            heap.pop();
            if(onboard>capacity) return false;
        }
        return true;
        
    }
    
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//       int stops[1001] = {};
//       for (auto t : trips) {
//           stops[t[1]] += t[0];
//           stops[t[2]] -= t[0];
//       }
        
//       for (auto i = 0; capacity >= 0 && i < 1001; ++i) {
//           capacity -= stops[i];
//       }
//       return capacity >= 0;q
// }
    
    
};