class Solution {
public:
    int solve(vector<int>& prices,int n, int buy, int indx,vector<vector<int>>&memo){
        int profit = 0;
        //base case
        if(indx == n){
            return 0;
        }
        if(memo[indx][buy] != -1){
            return memo[indx][buy];
        }
        //recursive case
        //there will be two options with us , we can buy on ith day or sell on ith day 
        if(buy){
            profit = max(-prices[indx]+solve(prices,n,0,indx+1,memo),0+solve(prices,n,1,indx+1,memo));
        }
        else{

            profit = max(prices[indx]+solve(prices,n,1,indx+1,memo),0+solve(prices,n,0,indx+1,memo));

        }
        return memo[indx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>memo(n+1,vector<int>(2,-1));
        int buy =  1;
        int indx = 0;
        int ans = solve(prices,n,buy,indx,memo);
        return ans;
    }
};