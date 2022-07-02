class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        //we will use two pointer technique 
        int low = 0;
        int high = 0;
        int ans = 0;
        //we need a largest substring without repeating char
        int freq[256] = {0};

        while(high < n){
            freq[s[high]]++;
            //Check that frequency of every char should be 1
            if(freq[s[high]] > 1){
                freq[s[low]]--
                low++;
            }
            ans = max(ans , high-low+1);
            high++;
        }
        return ans;
    }
};