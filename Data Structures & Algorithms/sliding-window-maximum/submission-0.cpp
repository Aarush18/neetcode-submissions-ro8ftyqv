class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 ;
        int r = 0 ;

        deque<int> dq;
        vector<int> output;

        while(r < n){

            // aage agar bada element hai then clear the dq
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);

            // for deleting the elements which are out of the window 
            if(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }

            if(r - l + 1 == k){
                output.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return output;
    }
};
