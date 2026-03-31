class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            int temp1 = max({nums[i] , currMax* nums[i] , currMin*nums[i]});
            int temp2 = min({nums[i] , currMax* nums[i] , currMin*nums[i]});

            currMax = temp1;
            currMin = temp2;

            maxProd = max(maxProd , currMax);
        }
        return maxProd;
    }
};
