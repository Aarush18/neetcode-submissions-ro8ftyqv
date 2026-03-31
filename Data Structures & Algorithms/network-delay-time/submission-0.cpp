class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);

        for(auto& it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int, int>>> pq;

        vector<int> dist(n + 1 , INT_MAX);
        
        dist[k] = 0;
        pq.push({ 0 , k});


        while(!pq.empty()){
            auto [dis , node] = pq.top();
            pq.pop();

            for(auto it : adj[node]){
                auto nei = it.first;
                auto edw = it.second;

                if(edw + dis < dist[nei]){
                    dist[nei] = edw + dis;
                    pq.push({dist[nei] , nei});
                }
            }
        }

        int ans = 0;
    
        for(int i = 1; i <= n ; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
