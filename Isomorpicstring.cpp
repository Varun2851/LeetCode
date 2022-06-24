//https://leetcode.com/problems/isomorphic-strings/submissions/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, char>mp1, mp2;
        
        for(int i=0; i<s.size(); i++){
            if(mp1.find(s[i]) == mp1.end() and mp2.find(t[i]) == mp2.end()){
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }else{
                // check if the key of firstmap present as value in the second map
                if(t[i] != mp1[s[i]] or s[i] != mp2[t[i]]){
                    return false;
                }
            }
        }
        return true;
    }
};
