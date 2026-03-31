class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

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

        int completed = 0;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            completed++;

            for(auto it : adj[p]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(completed == numCourses){
            return true;
        }else{
            return false;
        }
    }
};
