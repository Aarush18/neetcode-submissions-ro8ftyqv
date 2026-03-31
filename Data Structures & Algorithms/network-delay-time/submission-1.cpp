class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);

        for(auto& it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int ,int> , vector<pair<int ,int>> , greater<pair<int , int>>> pq;

        pq.push({k , 0});

        vector<int> dist(n + 1 , INT_MAX);

        dist[k] = 0;

        while(!pq.empty()){
            auto [node , dis] = pq.top();
            pq.pop();

            for(auto it : adj[node]){
                auto edw = it.second;
                auto nei = it.first;

                if(dis + edw < dist[nei]){
                    dist[nei] = dis + edw;
                    pq.push({nei , dist[nei]});
                }
            }
        }

        int maxi = 0;

        for(int i = 1 ; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1 ;
            }
            maxi = max(maxi , dist[i]);
        }

        return maxi;

    }
};
