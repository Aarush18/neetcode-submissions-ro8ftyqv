class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        int l = 0 ;
        int r = 0 ;

        while(r < nums.size()){
            if(st.count(nums[r])) return true;
            
            st.insert(nums[r]);
            

            if(st.size() > k){
                st.erase(nums[l]);
                l++;
            }

            r++;
        }

        return false;
    }
};