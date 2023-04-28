class Solution {
public:
    bool outofOrder(vector<int>& nums,int i){
        //corner cases
        int x = nums[i];
        if(i == 0){
            return x > nums[i+1];
        }

        if(i == nums.size()-1){
            return x < nums[i-1];
        }

        return x > nums[i+1] or x < nums[i-1]; 
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int smallest = INT_MAX;
        int largest = INT_MIN;

        for(int i = 0; i<n; i++){
            int x = nums[i];
            
            if(outofOrder(nums,i)){

                smallest = min(smallest,x);
                largest = max(largest,x);
            }
        }

        if(smallest == INT_MAX){
            return 0;
        }

        int left = 0;
        int right = n-1;

        while(smallest>=arr[left]){
            left++;
        }

        while(largest<=arr[right]){
            right--;
        }
        return right-left+1;
    }
};