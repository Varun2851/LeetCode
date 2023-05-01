#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        if(s1.size()>s2.size()){
            return false;
        }

        
        if(v1 == v2){
            return true;
        }

        for(int i = s1.size(); i<s2.size(); i++){
            v2[s2[i-s1.size()]-'a']--;
            v2[s2[i]-'a']++;

            if(v1 == v2){
                return true;
            }
        }
        return false;
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    int ans = checkInclusion(s1,s2);
    cout<<ans;
    return 0;
}