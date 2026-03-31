class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses);
        
        for(auto& it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;

        for(int i = 0 ; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0 ;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            cnt++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return cnt == numCourses;

    }
};
