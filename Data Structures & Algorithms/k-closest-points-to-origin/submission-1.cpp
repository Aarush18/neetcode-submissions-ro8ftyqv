class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        int n = points.size();

        priority_queue<pair<int, pair<int,int>>> pq;

        for(int i = 0 ; i < n ; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int dis = x1*x1 + y1*y1;
            pq.push({dis , {x1 , y1}});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            res.push_back({it.second.first , it.second.second});
        }
        return res;
    }
};
