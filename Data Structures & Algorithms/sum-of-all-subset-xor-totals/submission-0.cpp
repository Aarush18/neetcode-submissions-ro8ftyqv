class Solution {
public:
    int ans = 0;

    void solve(int i, vector<int>& nums, int currXor){
        // base case
        if(i == nums.size()){
            ans += currXor;
            return;
        }

        // take element
        solve(i + 1, nums, currXor ^ nums[i]);

        // don't take element
        solve(i + 1, nums, currXor);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(0, nums, 0);
        return ans;
    }
};