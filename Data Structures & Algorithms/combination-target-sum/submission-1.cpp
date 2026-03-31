class Solution {
private:
    void solve(int ind , vector<vector<int>>& res , vector<int>& nums , int target , vector<int>& output){
        if(target == 0 ){
            res.push_back(output);
            return ;
        }
        if(target < 0){
            return;
        }

        for(int i = ind ; i < nums.size(); i++){
            output.push_back(nums[i]);
            solve(i, res , nums , target - nums[i] , output );
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int> output;
        solve(0 , res , nums , target , output);

        return res;
    }
};
