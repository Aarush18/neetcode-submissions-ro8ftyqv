class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> output;

        int n = nums.size();

        int l = 0 ;
        int r = 0 ;

        while(r < n){   

            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);

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
