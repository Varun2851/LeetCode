class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum = 0;
        int res=INT_MAX;
        while(j<n){
        
            sum=sum+nums[j];
            if(sum<target){
                j++;     
            }
           else{
            
                while(sum>=target){
                
                    res=min(res,j-i+1);
                    sum=sum-nums[i];
                    i++;
                }
                j++;
            }
        }
        if(res==INT_MAX){
              return 0;
        }
          
        return res;
    }
};

////////////////////////////2Pointer Approach////////////////////////

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int minlen=INT_MAX;
        int sum=0;
        while(right<nums.size())
        {
            sum+=nums[right++];
            while(sum>=target)
            {
                minlen=min(minlen,right - left);
                sum-=nums[left++];
            }
        }
        return(minlen==INT_MAX)?0:minlen;  
    }
};