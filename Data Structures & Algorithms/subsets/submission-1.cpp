class Solution {
private:    
    void solve(int ind , vector<int>& nums , vector<int>& output , vector<vector<int>>& res){
        if(ind == nums.size()){
            res.push_back(output);
            return;
        }

        //include 
        output.push_back(nums[ind]);
        solve(ind + 1 , nums , output , res);
        output.pop_back();

        solve(ind + 1 , nums , output , res);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;

        solve(0 , nums , output , res);
        return res;
    }
};
