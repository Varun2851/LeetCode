//https://leetcode.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_fuel = 0;
        int total_fuel = 0;
        int total_cost = 0;
        int start = 0;
        int diff = 0;
        int n = gas.size();
        int m = cost.size();

        for(int i = 0; i<n; i++){
            total_fuel += gas[i];
        }

        for(int i = 0; i<m; i++){
            total_cost += cost[i];
        }

        if(total_fuel < total_cost){
            return -1;
        }

        for(int i = 0; i<n; i++){
            current_fuel += gas[i]-cost[i];

            if(current_fuel < 0){
                start = i+1;
                current_fuel = 0;
            }
        }
        return start;
    }
};