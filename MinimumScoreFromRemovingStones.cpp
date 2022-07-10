class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
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
        return ans;
    }
};