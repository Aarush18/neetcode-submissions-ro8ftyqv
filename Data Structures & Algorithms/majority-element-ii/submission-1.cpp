class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cd1  = 0 ;
        int cd2 = 0 ;

        int cnt1 = 0 ;
        int cnt2 = 0 ;

        int n = nums.size();

        for(auto num : nums){
            if(num == cd1){
                cnt1++;
            }else if(num == cd2){
                cnt2++;
            }else if(cnt1 == 0){
                cd1 = num;
                cnt1 = 1;
            }else if(cnt2 == 0){
                cd2 = num;
                cnt2 = 1;
            }else {
                cnt1 --;
                cnt2 --;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(auto num : nums){
            if(num == cd1) cnt1++;
            else if(num == cd2) cnt2++;
        }
        vector<int> temp;
        if(cnt1 > n/3) temp.push_back(cd1);
        if(cnt2 > n/3) temp.push_back(cd2); 

        return temp;
    }
};