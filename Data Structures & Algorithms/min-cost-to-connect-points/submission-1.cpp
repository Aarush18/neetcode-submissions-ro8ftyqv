class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // adjacency list: adj[u] = {v, cost}
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
        > pq;

        vector<bool> visited(n, false);

        pq.push({0, 0}); // {cost, node}
        int cost = 0;
        int edgesUsed = 0;

        while(!pq.empty() && edgesUsed < n) {
            auto [nodeCost, node] = pq.top();
            pq.pop();

            if(visited[node]) continue;

            visited[node] = true;
            cost += nodeCost;
            edgesUsed++;

            for(auto [nei, neiCost] : adj[node]) {
                if(!visited[nei]) {
                    pq.push({neiCost, nei});
                }
            }
        }

        return cost;
    }
};
