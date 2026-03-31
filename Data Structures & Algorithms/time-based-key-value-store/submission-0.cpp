class TimeMap {
    unordered_map<string , vector<pair<string , int>>> timeMap;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {

        if (timeMap.find(key) == timeMap.end()) return "";

        int l = 0; 
        int r = timeMap[key].size() - 1;

        string ans;

        while ( l <= r){
            int mid = l + (r - l)/2;

            if(timeMap[key][mid].second == timestamp){
                return timeMap[key][mid].first;
            }
            else if(timeMap[key][mid].second <= timestamp){
                ans = timeMap[key][mid].first;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
