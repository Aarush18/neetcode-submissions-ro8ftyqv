class CountSquares {
public:

    map<pair<int , int> , int>mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0] , point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];

        int ans = 0 ;

        for(auto& it : mp){
            int x2 = it.first.first;
            int y2 = it.first.second;

            if(abs(x2 - x1) == abs(y2 - y1) && x2 != x1 && y2 != y1){
                ans += it.second * mp[{x1 , y2}] * mp[{x2 , y1}];
            }
        }
        return ans;
    }
};
