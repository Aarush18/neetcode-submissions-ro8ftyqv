class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
         > pq;

        vector<vector<int>> dist(n , vector<int>(k+2 , INT_MAX));

        dist[src][0] = 0 ;
        pq.push({0 , {src , 0}});

        vector<vector<pair<int , int>>> adj(n);

        for(auto &it : flights){
            int s = it[0];
            int e = it[1];
            int cost = it[2];

            adj[s].push_back({e , cost});
        }

        while(!pq.empty()){
            auto [currCost , p] = pq.top();
            auto [ node , stops ] = p;
            pq.pop();

            if(node == dst) return currCost;
            if(stops > k){
                continue;
            }

            for(auto [adjNode , price] : adj[node]){
                int newStops = stops + 1;
                int newCost = currCost + price;
                if(newCost < dist[adjNode][newStops]){
                    dist[adjNode][newStops] = newCost ;
                    pq.push({newCost , { adjNode , stops + 1}});
                }
            }
        }
        return -1 ;
    }
};
