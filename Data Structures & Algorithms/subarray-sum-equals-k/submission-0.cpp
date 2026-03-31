class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> preMap;

        preMap[0] = 1;
        
        int sum = 0;
        int count = 0;

        for(auto num : nums){
            sum+= num;

            if(preMap.count(sum - k)){
                count+= preMap[sum - k];
            }

            preMap[sum]++;
        }

        return count;
    }
};