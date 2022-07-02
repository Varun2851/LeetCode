//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/submissions/
class Solution {
public:
    int maxdiff(vector<int>&horizontalCuts ,int length){
        sort(horizontalCuts.begin(),horizontalCuts.end());
        int maxcut = horizontalCuts[0];
        
        for(int i = 1; i<horizontalCuts.size(); i++){
            maxcut = max(maxcut , horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        maxcut = max(maxcut,length-horizontalCuts.back());
        return maxcut;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int x =  maxdiff(horizontalCuts,h);
        long long int y =  maxdiff(verticalCuts,w);
        
        return (x*y)%1000000007;
    }
};