class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i = 0  ; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            if(x == y){
                pq.push(0);
                continue;
            }else if(x < y){
                pq.push(y - x);
            }else{
                pq.push(x - y); 
            }
        }
        return pq.top();
    }
};
