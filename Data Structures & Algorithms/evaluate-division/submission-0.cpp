class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair<string , double>>>adj;

        for(int i = 0 ; i < values.size(); i++){
            auto start = equations[i][0];
            auto end = equations[i][1];

            adj[start].push_back({end , values[i]});
            adj[end].push_back({start , 1.0 / values[i]});
        }

        vector<double> res;
       
        for(auto& it : queries){
            auto start = it[0];
            auto end = it[1];

            queue<pair<string , double>> q;
            unordered_set<string> visited;

            q.push({start , 1});
            visited.insert(start);

            if(adj.find(start) == adj.end() || adj.find(end) == adj.end()){
                res.push_back(-1.0);
                continue;
            }

            bool found = false;

            while(!q.empty()){
                auto [node , edw] = q.front();
                q.pop();

                if(node == end){
                    found = true;
                    res.push_back(edw);
                    break;
                }

                for(auto& [adjNode , val] : adj[node]){
                    if(visited.count(adjNode)) continue;

                    visited.insert(adjNode);
                    q.push({adjNode , edw * val});
                }
            }

            if(!found) res.push_back(-1.0);
        }

        return res;
    }
};