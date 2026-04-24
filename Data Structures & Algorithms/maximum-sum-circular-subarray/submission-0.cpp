class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int maxSum = nums[0];

        for(int i = 1 ; i < n ; i++){
            currMax = max(nums[i] , currMax + nums[i]);
            maxSum = max(maxSum , currMax);
        }

        int currMin = nums[0];
        int minSum = nums[0];

        for(int i = 1 ; i < n ; i++){
            currMin = min(nums[i] , currMin + nums[i]);
            minSum = min(minSum , currMin);
        }

        int ts = 0 ;
        for(auto x : nums){
            ts += x;
        }

        if(maxSum < 0){
            return maxSum;
        }

        return max(maxSum , ts - minSum);
    }
};