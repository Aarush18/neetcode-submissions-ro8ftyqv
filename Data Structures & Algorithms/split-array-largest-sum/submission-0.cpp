class Solution {
private:
    bool canSplit(int val , vector<int>& nums , int k){
        int currSum = 0;
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++){
            if(currSum + nums[i] <= val){
                currSum = currSum + nums[i];
            }else{
                cnt++;
                currSum = nums[i];
            }
        }

        return cnt <= k ; 
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin() , nums.end());
        long long r = accumulate(nums.begin() , nums.end() , 0);

        long long ans = r;

        while(l <= r){
            auto mid = l + (r - l)/2;

            if(canSplit(mid , nums , k)){
                ans = mid ;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};