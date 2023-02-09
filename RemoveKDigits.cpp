class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        stack<char>s;

        for(int i = 0; i<n; i++){
            if(s.empty()){
                s.push(nums[i]); //agar stack khali h to push kro simple
            }
            else{
                //stack khali nh h , koi ele pada h , agar ele pada h to compare kro
                while(!s.empty() and s.top()>nums[i] and k>0){
                    s.pop();
                    k--;
                }
                s.push(nums[i]); //compare kro current element se , and phir crrent element push kr do stack m
            }
        }
        //agar abhi bhi k 0 nh hua ho to pop kro
        while(k>0){
            s.pop();
            k--;
        }

        if(s.empty()){
            return "0";
        }

        //ab sara compare wala kaam kr lia ab hamara number stack m pada h 
        //now fatch the number from stack
        string ans = "";

        while(!s.empty()){
            ans = s.top()+ans;
            s.pop();
        }

        //ab last m check kr lo koi leadig 0 to nh pada h 

        int i = 0;
        while(ans[i] == '0'){
            i++;
        }
        //now ab final string return kr do
        return (ans.substr(i) == "")?"0":(ans.substr(i));
    }
};