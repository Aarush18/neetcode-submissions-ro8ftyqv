class Solution {
private:
    bool dfs(int node , int parent , vector<bool>& visited , vector<vector<int>>& adj){
        visited[node] = true;

        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it , node , visited , adj) == false){
                    return false;
                }
            }
            else if(it != parent){
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) { 
         // valid tree ke liye , we have to check for connectivity and cyclicity as well . No cycles should be there + all the nodes should be connected

        vector<bool> visited(n , false);

        vector<vector<int>> adj(n);

        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //check cyle
        if(dfs(0 , -1 , visited , adj) == false){
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
