//https://leetcode.com/problems/count-binary-substrings/submissions/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int count = 0 , i = 1 , current = 1, prev = 0;
        
        while(i < s.size()){
            if(s[i] != s[i-1]){
                count += min(prev,current);
                prev = current;
                current = 1;
            }
            else{
                current++;
            }
            i++;
        }
        count += min(prev , current);
        return count;
    }
};