class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>> dist(n , vector<int>(k + 2 , INT_MAX));

        vector<vector<pair<int , int>>> adj(n + 1);

        for(auto& it : flights){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int , pair<int ,int> > , vector<pair<int , pair<int ,int>>> , greater<pair<int , pair<int ,int>>>>pq;

        pq.push({0 , {src , 0}}); // {dis , {node , stops}};

        dist[src][0] = 0 ;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int dis = p.first;
            int node = p.second.first;
            int stops = p.second.second;

            if(node == dst){
                return dis;
            }

            if(stops > k) continue;

            for(auto [nei , cost] : adj[node]){
                if(dis + cost < dist[nei][stops]){
                    dist[nei][stops + 1] = dis + cost;
                    pq.push({dist[nei][stops + 1] , { nei  , stops + 1}});
                }
            }   
        }
        return -1;
    }
};
