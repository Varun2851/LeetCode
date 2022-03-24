class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,s=0;
        int startindex = -1;
        int res=INT_MAX;
        while(j<n){
        
            s=s+nums[j];
            if(s<target){
                j++;     
            }
           else{
            
                while(s>=target){
                
                    res=min(res,j-i+1);
                    startindex = i;
                    s=s-nums[i];
                    i++;
                }
                j++;
            }
        }
        if(res==INT_MAX){
              return 0;
        }
          for(int k = startindex; k<startindex+res; k++){
            cout<<nums[k]<<" ";
        }
        return res;
         
    }
};