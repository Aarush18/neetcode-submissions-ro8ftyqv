class Solution {
private:
    void helper(vector<int>& candidates , int target , vector<int>&output , vector<vector<int>>&res , int idx){
        if(target < 0) return;
        if(target == 0){
            res.push_back(output);
            return;
        }

        for(int i = idx ; i < candidates.size() ; i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            output.push_back(candidates[i]); // LELO
            helper(candidates , target - candidates[i] , output , res , i + 1);
            output.pop_back(); // VAPASI (nahi liya)
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;

        sort(candidates.begin() , candidates.end());

        helper(candidates , target , output , res , 0);

        return res;
    }
};
