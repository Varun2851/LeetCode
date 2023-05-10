// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n = s.size();

        for(int i = 0; i<n; i++){
            if(st.empty() or st.top().first != s[i]){
                st.push({s[i],1});
            }
            else{
                //means duplicate
                auto prev = st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }

            if(st.top().second == k){
                st.pop();
            }
        }

        string ans =  "";
        while(!st.empty()){
            auto top = st.top();
            st.pop();

            while(top.second--){
                ans += top.first;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
        return ans;
    }
};