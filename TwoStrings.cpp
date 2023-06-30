#include <bits/stdc++.h>
using namespace std;
int main() {
    string str = "orange";
    string str1 = "apple";

    string res = str+str1;

    map<char,int>mp;

    for(auto X : res){
        mp[X]++;
    }

    string ans;

    for(auto X : mp){
        auto y = X;

        if(y.second <= 1){
            ans += y.first;
        }
        else{
            while(1){
                ans += y.first;
                break;
            }
        }
    }


    sort(ans.begin(),ans.end(),greater<char>());

    for(auto X : ans){
        cout<<X;
    }

    return 0;

}
