class Solution {
private:
    bool dfs(int node , int parent , vector<vector<int>>& adj , vector<bool>& vis){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it , node , adj , vis) == true){
                    return true;
                }
            }else if(it != parent){
                return true;
            }
        }

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);

        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            vector<bool> vis(edges.size() + 1 , false);

            if(dfs(it[0] , -1 , adj , vis)){
                return it;
            } 
        }

        return {};
    }
};
