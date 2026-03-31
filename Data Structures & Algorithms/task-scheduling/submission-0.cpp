class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};

        for(int i = 0; i < tasks.size() ; i++){
            hash[tasks[i] - 'A']++;
        }

        priority_queue<int>pq;

        for(int i = 0 ; i < 26 ; i++){
            if(hash[i] > 0){
                pq.push(hash[i]);
            }
        }

        int time = 0 ;

        while(!pq.empty()){
            vector<int> res;
            for(int i = 0 ; i <= n ; i++){
                if(!pq.empty()){
                    auto freq = pq.top();
                    pq.pop();
                    freq--;
                    res.push_back(freq);
                }
            }

            for(auto f : res){
                if(f>0){
                    pq.push(f);
                }
            }
            if(pq.empty()){
                time+=res.size();
            }else{
                time+=n+1;
            }
        }
        return time;
    }
};
