class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int l = 0 ;
        int r = 0 ;

        while(r < nums.size()){

            if(nums[l] == nums[r] && l != r){
                return true;
            }
            if(r - l + 1 > k){
                l++;
            }
            if(r - l + 1 == k){
                if(nums[l] == nums[r] && l != r){
                    return true;
                }
            }

            r++;
        }

        return false;
    }
};