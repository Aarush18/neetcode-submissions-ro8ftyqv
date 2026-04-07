class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        int n = tasks.size();

        vector<vector<int>> sortedArray;

        for(int i = 0 ; i < n ; i++){
            sortedArray.push_back({tasks[i][0] , tasks[i][1] , i});
        }

        sort(sortedArray.begin(), sortedArray.end());

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>>pq;

        int idx = 0 ;
        int curr_time = 0 ;

        while(idx < n || !pq.empty()){
            if(pq.empty() && curr_time < sortedArray[idx][0]){
                curr_time = sortedArray[idx][0];
            }

            while(idx < n && sortedArray[idx][0] <= curr_time){
                pq.push({sortedArray[idx][1] , sortedArray[idx][2]});
                idx++;
            }

            auto [procTime , idx] = pq.top();
            pq.pop();

            curr_time += procTime;
            res.push_back(idx);
        }

        return res;
    }
};