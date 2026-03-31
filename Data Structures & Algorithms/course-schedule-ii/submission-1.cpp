class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int> indegree(numCourses , 0);

        for(auto& it : prerequisites){
            auto course = it[0];
            auto preq = it[1];

            adj[preq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            ans.push_back(p);

            for(auto it : adj[p]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == numCourses)return ans;
        return {};
    }
};
