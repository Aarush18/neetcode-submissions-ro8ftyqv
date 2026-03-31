class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> hash;

        int maxi = 0 ;

        for(int i= 0 ; i < n; i++){
            hash[nums[i]]++;
        }

        for(int i = 0 ; i < n; i++){
            if(hash[nums[i]] > n/2){
                maxi = nums[i];
            }
        }
        return maxi;
    }
};