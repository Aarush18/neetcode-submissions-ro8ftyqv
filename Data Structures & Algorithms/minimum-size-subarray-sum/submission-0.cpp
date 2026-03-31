class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;

        int l = 0;  
        int r = 0;

        int minLen = 1e9;

        while(r < nums.size()){
            sum+= nums[r];

            while(sum >= target){
                sum-= nums[l];
                minLen = min(minLen , r - l + 1);
                l++;
            }

            r++;
        }

        return minLen == 1e9 ? 0 : minLen;
    }
};