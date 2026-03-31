class Solution {
public:
    int jump(vector<int>& nums) {
        int currInd = 0;
        int farthest = 0;
        int jumps = 0;

        for(int i = 0; i < nums.size() - 1 ; i++){
            farthest = max(farthest , i + nums[i]);

            if(currInd == i){
                jumps++ ;
                currInd = farthest ;
            }
        }
        return jumps;
    }
};
