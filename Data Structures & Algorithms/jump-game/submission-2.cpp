class Solution {
private:
    bool solve(int ind , vector<int>& nums){
        if(ind >= nums.size() - 1){
            return true;
        }

        for(int jump = 1 ; jump <= nums[ind]; jump++){
            if(solve(ind + jump , nums) == true){
                return true;
            }
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1){
            return true;
        }

        return solve(0 , nums);
    }
};
