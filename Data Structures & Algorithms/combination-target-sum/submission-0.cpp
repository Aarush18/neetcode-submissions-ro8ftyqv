class Solution {
private:
    void helper(vector<int> & nums , int ind ,vector<vector<int>>& res , vector<int> output , int sum , int target){
        if(sum == target){
            res.push_back(output);
            return;
        }
        if(ind == nums.size() || sum > target){
            return ;
        }

        //take the current idx
        output.push_back(nums[ind]);
        helper(nums , ind , res , output , sum + nums[ind] , target);
        output.pop_back();

        //or skip the current idx 
        helper(nums , ind + 1 , res , output , sum , target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> output;
        helper(nums , 0 , res , output , 0 ,  target);
        return res;
    }
};
