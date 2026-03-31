class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> mpp;

        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]++;
        }
        // map [element -> frequency]
        int longest = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mpp.find(nums[i] - 1) == mpp.end()){
                int currEL = nums[i];
                int cnt = 1;
                while(mpp.find(currEL + 1) != mpp.end()){
                    cnt++;
                    currEL++;
                }
                
                longest = max(longest , cnt);
                   
            }
        }

        return longest ;
    }
};
