class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > freqMap;

        vector<int> ans;

        for(int i = 0 ; i<nums.size(); i++){
            freqMap[nums[i]]++;
        }

        vector<pair<int,int>> v(freqMap.begin(), freqMap.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        for(int i = 0; i <k ; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
