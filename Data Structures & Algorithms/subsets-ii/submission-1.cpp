class Solution {
private:
    void solve(int ind , vector<int>& nums , vector<vector<int>>& res , vector<int>& output){

        res.push_back(output);

        for(int i = ind ; i < nums.size() ; i++){
            
            if(i > ind && nums[i] == nums[i - 1]){
                continue;
            }
            output.push_back(nums[i]);
            solve(i + 1 , nums , res ,output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>output;

        sort(nums.begin() , nums.end());

        solve(0 , nums , res , output);

        return res;
    }
};
