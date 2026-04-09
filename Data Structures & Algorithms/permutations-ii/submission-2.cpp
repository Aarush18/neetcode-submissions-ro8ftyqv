class Solution {
private:
    void solve(int ind , vector<int>& nums , vector<vector<int>>& res , vector<int>& output , vector<bool>&used){
        
        if(nums.size() == output.size()){
            res.push_back(output);
            return;
        }

        for(int i = 0 ; i < nums.size(); i++){
            
            if(i > 0 && nums[i-1] == nums[i] && used[i-1] == false){
                continue;
            }

            if(used[i]) continue;

            used[i] = true;

            output.push_back(nums[i]);
            solve(i + 1 , nums , res , output , used);
            output.pop_back();

            used[i] = false;

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;

        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<bool>used(n , false);

        solve(0 , nums , res , output , used);

        return res;
    }
};