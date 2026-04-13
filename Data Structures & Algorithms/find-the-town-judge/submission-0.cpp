class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n + 1 , 0);
        vector<int> indegree(n + 1 , 0);

        for(auto &it : trust){
            outdegree[it[0]]++;
        }

        for(auto & it : trust){
            indegree[it[1]]++;
        }

        for(int i = 1 ; i <= n ; i++){
            if(outdegree[i] == 0 && indegree[i] == n - 1){
                return i ;
            }
        }

        return -1;
    }
};