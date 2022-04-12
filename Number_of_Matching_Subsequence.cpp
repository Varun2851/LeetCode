// Problem link = https://leetcode.com/problems/number-of-matching-subsequences/submissions/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>mp;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]].push_back(i);
        }
        
        int curr_index=-1,c=0;
        
        for(auto x:words)
        {
            bool flag=1;
            curr_index=-1;
            for(int i=0;i<x.length();i++)
            {
                int temp=curr_index;
                for(auto y:mp[x[i]])
                {
                    if(y>curr_index)
                    {
                        curr_index=y;
                        break;
                    }
                }
                
                if(temp==curr_index)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                c++;
        }
        return c;
    }
};