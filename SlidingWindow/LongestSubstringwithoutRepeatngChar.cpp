class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        queue<char>q;
        int maxi = INT_MIN;
        map<char,int>mp;

        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            q.push(s[i]);

            while(mp[s[i]]>1){
                mp[q.front()]--;
                q.pop();
            }
            int x = q.size();
            maxi = max(x,maxi);
        }
        return maxi;
    }
};

//using sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxlen = INT_MIN;
        unordered_map<char,int>mp;

        while(j<n){
            mp[s[j]]++;

            if(mp.size() == j-i+1){
                maxlen = max(maxlen,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1){
                //means duplicate
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(maxlen == INT_MIN){
            return 0;
        }
        return maxlen;
    }
};

//most Optimised solution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxlen = INT_MIN;
        vector<char>v(256);
        while(j<n){
            char r = s[j];
            v[r]++;

            while(v[r]>1){
                char l = s[i];
                v[l]--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        if(maxlen == INT_MIN){
            return 0;
        }
        return maxlen;
    }
};