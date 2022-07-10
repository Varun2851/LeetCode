class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(int i = 0; i<3; i++){
            if(amount[i] != 0){
                pq.push(amount[i]);
            }
        }
        int ans = 0;
        while(pq.size() >= 2 and pq.top() >= 1){
            int top1 = pq.top()-1;
            pq.pop();
            int top2 = pq.top()-1;
            pq.pop();
            
            ans++;
            
            if(top1 > 0){
                pq.push(top1);
            }
            if(top2 > 0){
                pq.push(top2);
            }
        }
        if(pq.size() == 1){
            ans += pq.top();
        }
        return ans;
    }
};