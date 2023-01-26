class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        int new_weight;
        if(n == 1){
            return stones[0];
        }
        for(int i = 0; i<n; i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            new_weight =  a-b;
            cout<<new_weight<<" ";
            pq.push(new_weight);
        }
        return new_weight;
    }
};