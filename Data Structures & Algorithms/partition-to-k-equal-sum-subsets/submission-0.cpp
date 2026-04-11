class Solution {
private:
    bool solve(int ind , vector<int>& nums , vector<int>& subsets , int target , int k){
        if(ind == nums.size()){
            for(int i = 0 ;i < k ; i++){
                if(subsets[i] != target){
                    return false;
                }
            }
            return true;
        }


        for(int i = 0 ;i < k ; i++){
            if(subsets[i] + nums[ind] > target){
                continue;
            }

            subsets[i]+= nums[ind];
            if(solve(ind + 1 , nums , subsets , target , k ) == true){
                return true;
            }
            subsets[i]-= nums[ind];

            if(subsets[i] == 0) break;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(sum % k != 0){
            return false;
        }

        int target = sum / k;

        vector<int> subsets(k , 0);

        sort(nums.rbegin() , nums.rend());

        return solve(0 , nums , subsets , target , k);
 
    }
};