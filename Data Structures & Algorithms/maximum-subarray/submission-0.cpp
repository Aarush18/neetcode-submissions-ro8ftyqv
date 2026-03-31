class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currSum = 0 ;
        int maxi = -1e9;
        for(int i = 0 ; i < nums.size(); i++){
            currSum = currSum + nums[i];
            maxi = max(maxi , currSum);

            if(currSum < 0){
                currSum = 0 ;
            }

        }

        return maxi;
    }
};