class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt =0 ;
        int candidate = 0 ;

        for(auto num : nums){
            if(cnt == 0){
                candidate = num;
            }

            if(num == candidate){
                cnt++;
            }else{
                cnt--;
            }
        }
        return candidate;
    }
};