class Solution {
private:
    bool dfs(int node , int parent , vector<bool>& visited , vector<vector<int>>& adj){

        visited[node] = true;

        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it , node , visited , adj) == true){
                    return true;
                }
            }else if(it != parent){
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        vector<bool> visited(n , false);

        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // cycle check 

        if(dfs(0 , -1 , visited , adj) == true){
            return false;
        }

        // connectivity check
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }
};
