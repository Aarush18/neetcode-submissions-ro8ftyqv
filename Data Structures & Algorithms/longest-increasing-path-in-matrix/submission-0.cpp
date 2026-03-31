class Solution {
private:
    int solve(int x , int y , int n , int m , vector<vector<int>>& dp , vector<vector<int>>& matrix){
        
        int ans = 1;

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        vector<pair<int , int>> dirs = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

        for(auto [dx , dy] : dirs){
            int nx = x + dx;
            int ny = y + dy;

            if( nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] > matrix[x][y]){
                ans = max(ans , 1 + solve(nx , ny , n , m , dp , matrix));
            }
        }

        return dp[x][y] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp (n , vector<int>(m + 1 , -1 ));

        int maxi = 0;

        for(int i = 0; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                maxi = max(maxi , solve(i , j , n , m , dp , matrix));
            }
        }

        return maxi;
    }
};
