class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

                priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        pq.push({grid[0][0] , {0 , 0}});

        vector<vector<bool>>vis(n , vector<bool>(m , false));

        vector<pair<int , int>> dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int t = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if(vis[x][y]) continue;
            vis[x][y] = true;
           

            if(x == n-1 && y == n-1){
                return t;
            }

            for(auto [dx , dy] : dirs){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]){\
                    int newTime = max(t , grid[nx][ny]);
                    pq.push({newTime , {nx , ny}});
                }
            }
        }
        return -1 ;
    }
};
