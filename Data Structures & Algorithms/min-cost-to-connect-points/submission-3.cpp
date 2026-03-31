class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<pair<int , int>>> adj(n);

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1; j < n ; j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j , dis});
                adj[j].push_back({i , dis});
            }
        }

        priority_queue<pair<int , int > , vector<pair<int , int>> , greater<pair<int , int>>>pq;

        pq.push({0 , 0});// {cost , node};

        int edgesUsed = 0;
        int cost = 0 ;

        vector<bool> vis(n  , false);

        while(!pq.empty() && edgesUsed < n){
            auto [nodeCost , node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node] = true;

            cost+= nodeCost;
            edgesUsed ++;

            for(auto [nei , neiCost] : adj[node]){
                if(!vis[nei]){
                    pq.push({neiCost , nei});
                }
            }
        }
        return cost;
    }
};
