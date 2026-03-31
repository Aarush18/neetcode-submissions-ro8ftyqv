class Solution {
private:
    void solve(int ind , vector<int>& candidates , vector<int>& output , vector<vector<int>>& res , int target){
        if(ind > candidates.size() || target < 0){
            return;
        }
        
        if(target == 0){
            res.push_back(output);
            return;
        }

        for(int i = ind ; i < candidates.size(); i++){
            
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }

            output.push_back(candidates[i]);
            solve(i + 1 , candidates , output , res , target - candidates[i]);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());

        vector<vector<int>> res;
        vector<int> output;

        solve(0 , candidates , output , res , target);

        return res;
    }
};
