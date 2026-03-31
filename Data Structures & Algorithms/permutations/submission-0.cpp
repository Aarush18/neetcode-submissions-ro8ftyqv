class Solution {
    unordered_set<int> st;
    vector<vector<int>>res;
private:
    void solve(vector<int>& output , vector<int>& nums){
        if(output.size() == nums.size()){
            res.push_back(output);
            return;
        }
     
        for(int i = 0 ; i < nums.size() ; i++){
            if(st.find(nums[i]) == st.end()){
                output.push_back(nums[i]);
                st.insert(nums[i]);
                solve(output , nums );
                output.pop_back();
                st.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> output;
        solve(output , nums);
        return res;
    }
};
