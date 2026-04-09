class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int ,int>> capProf;

        for(int i = 0 ; i < n ; i++){
            capProf.push_back({capital[i] , profits[i]});
        }

        sort(capProf.begin() , capProf.end());

        priority_queue<int> pq;
        int idx = 0;

        while(k--){
            
            while(idx < n && capProf[idx].first <= w){
                pq.push(capProf[idx].second);
                idx++;
            }

            if(pq.empty()) break;

            w+= pq.top();
            pq.pop();

        }

        return w;
    }
};