class Solution {
public:
    int PeakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        
        if(n >= 3){
            
            for(int i = 1; i<=n-2;){
                
                // if the ith element is peak or not
                if(arr[i] > arr[i+1] and arr[i] > arr[i-1]){
                    index = i;
                    i++;
                }
                else{
                    i++;
                }
            }
        }
        return index ;
    }
};