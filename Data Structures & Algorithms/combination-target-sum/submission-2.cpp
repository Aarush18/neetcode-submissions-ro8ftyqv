class Solution {
private:
    void solve(int ind , vector<int>& nums , int target , vector<int>& output , vector<vector<int>>& res){
        if(ind >= nums.size() || target < 0){
            return;
        }

        if(target == 0){
            res.push_back(output);
            return;
        }

        //include 
        output.push_back(nums[ind]);
        solve(ind , nums , target - nums[ind] , output , res);
        output.pop_back();

        solve(ind + 1 , nums , target , output , res);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> output;

        solve(0 , nums , target , output , res);

        return res;
    }
};
