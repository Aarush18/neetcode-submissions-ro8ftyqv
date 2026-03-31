class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> mpp;
        vector<vector<int>> bucket(n+1);
        vector<int> result ;

        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]]++;
        }

        //i -> freq;
        //arr[i] -> vector of elements hai 
        // bucket[i] -> is freq pe konsa element hai 
        
        for(auto &it : mpp){
            int freq = it.second;
            int element = it.first;

            bucket[freq].push_back(element);
        }

        for(int i = n ; i >= 0 ; i--){
            if(bucket[i].size() == 0){
                continue;
            }
            while(bucket[i].size() > 0 && k > 0 ){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};
