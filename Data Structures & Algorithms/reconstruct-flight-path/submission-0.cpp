class Solution {
    vector<string> result;
private:
     bool DFS(string from_city , vector<string>& path , int numTickets ,unordered_map<string , vector<string>>& adj){
            path.push_back(from_city);

            if(path.size() == numTickets + 1){
                result = path;
                return true;
            }

            vector<string>& neighbors = adj[from_city];
            
            for(int i = 0 ; i < neighbors.size() ; i++){
                string to_city = neighbors[i];

                neighbors.erase(neighbors.begin() + i);

                if(DFS(to_city , path , numTickets , adj) == true){
                    return true;
                }

                neighbors.insert(neighbors.begin() + i , to_city);

            }
            path.pop_back();
            return false;

        }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string , vector<string>> adj;

        vector<string> path ;
        int numTickets = tickets.size();

        for(auto& it : tickets){
            adj[it[0]].push_back(it[1]);
        }

        for(auto& it : adj){
            sort(it.second.begin() , it.second.end());
        }

        DFS("JFK" ,path , numTickets , adj);

        return result;
    }
};
