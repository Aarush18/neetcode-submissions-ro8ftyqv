class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> atlantic(n, vector<bool>(m,false));
        vector<vector<bool>> pacific(n, vector<bool>(m,false));

        vector<vector<int>> ans;

        queue<pair<int , int>> q;

        vector<pair<int , int>> dirs = {{1 , 0} , { 0 , 1 } , { -1 , 0 } , {0 , -1}};

        for(int i = 0 ; i < m ; i++){
            q.push({n - 1 , i});
            atlantic[n-1][i] = true;
        }

        for(int i = 0 ; i < n ; i++){
            q.push({i , m - 1});
            atlantic[i][m-1] = true;
        }

        while(!q.empty()){
            auto[x , y] = q.front();
            q.pop();

            for(auto [dx , dy] : dirs){
                int nx = x + dx ;
                int ny = y + dy ;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && heights[nx][ny] >= heights[x][y] && !atlantic[nx][ny]){
                    atlantic[nx][ny] = true;
                    q.push({nx , ny});
                }
            }
        }

        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
        }

        for(int i = 0 ; i < m ; i++){
            q.push({0 , i});
            pacific[0][i] = true;
        }

        for(int i = 0 ; i < n ; i++){
            q.push({i , 0});
            pacific[i][0] = true;
        }

        while(!q.empty()){
            auto[x , y] = q.front();
            q.pop();

            for(auto [dx , dy] : dirs){
                int nx = x + dx ;
                int ny = y + dy ;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && heights[nx][ny] >= heights[x][y] && !pacific[nx][ny]){
                    pacific[nx][ny] = true;
                    q.push({nx , ny});
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if (atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i , j});
                }
            }
        }
        return ans;
        
    }
};
