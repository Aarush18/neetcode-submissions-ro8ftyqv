class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMap(n);
        vector<int> suffMap(n);

        vector<int> output;
        int product = 1;

        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                prefMap[i] = 1;
            }else{
            product = product * nums[i-1];
            prefMap[i] = product;
            }
        }
         product = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(i == n-1){
                suffMap[i] = 1;
            }else{
            product = product* nums[i+1];
            suffMap[i] = product;
            }
        }

        for(int i = 0 ; i < n ; i++){
            int value = prefMap[i] * suffMap[i];
            output.push_back(value);
        }
        return output;
    }
};
