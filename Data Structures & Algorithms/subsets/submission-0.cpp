class Solution {
private: 
    void helper(int ind ,vector<int> output ,vector<vector<int>>& res , vector<int>& nums){
        if(ind == nums.size()){
            res.push_back(output);
            return ;
        }

        //exclude
        helper(ind + 1 , output , res , nums);

        //include
        output.push_back(nums[ind]);
        helper(ind + 1 , output , res ,nums);
    
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> output;
        helper(0 , output , res, nums);

        return res;
    }
};
