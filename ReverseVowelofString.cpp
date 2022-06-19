class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E'
            or ch == 'I' or ch == 'O' or ch == 'U';
    }
    string reverseVowels(string s) {
        
        int n = s.size();
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            while(left < right and !isVowel(s[left])){
                left++;
            }
            while(right > left and !isVowel(s[right])){
                right--;
            }
            
            swap(s[left] , s[right]);
            left++;
            right--;
        }
        return s;
    }
};