class Solution {
    vector<string> result;
private:
    void dfs(string city , unordered_map<string , priority_queue<string , vector<string> , greater<string>>>& adj ){
        
        while(!adj[city].empty()){

            auto nextCity = adj[city].top();
            adj[city].pop();

            dfs(nextCity , adj);
        }

        result.push_back(city);
        return;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // hierholzer algo . 

        unordered_map<string , priority_queue<string , vector<string> , greater<string>>> adj;

        for(auto& it : tickets){
            adj[it[0]].push(it[1]);
        }

        dfs("JFK" , adj);
        reverse(result.begin() , result.end());

        return result;
    }
};
