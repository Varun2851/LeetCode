class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        
        int i = 0;
        int j = 0;

        string ans;

        while(i<s1.size() and j < s2.size()){
            ans.push_back(s1[i]);
            ans.push_back(s2[i]);

            i++;
            j++;
        }

        if(i == s1.size()){
            for(int j = i; j<s2.size(); j++){
                ans.push_back(s2[j]);
            }
        }

        if(j == s2.size()){
            for(int i = j; i<s1.size(); i++){
                ans.push_back(s1[i]);
            }
        }
        return ans;
    }
};