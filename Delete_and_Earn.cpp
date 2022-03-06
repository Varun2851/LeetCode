class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int>arr(10001,0);
        
        for(int i = 0; i<nums.size(); i++){
            arr[nums[i]]++;
        }
        
        int include=0;
        int exclude=0;
        
        for(int i=0;i<arr.size();i++)
        {
            int newInc=exclude+arr[i]*i;
            int newExc=max(include,exclude);
            
            include=newInc;
            exclude=newExc;
        }
         
        return  max(include,exclude);
    }
};