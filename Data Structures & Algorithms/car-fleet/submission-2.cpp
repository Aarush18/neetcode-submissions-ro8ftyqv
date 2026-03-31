class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int , int >> result;

        for(int i = 0 ; i < position.size() ; i++){
            result.push_back({position[i] , speed[i]});
        }

        sort(result.begin() , result.end());

        int n = result.size();

        for(int i = n-1 ; i >= 0 ; i --){
            double time = (double) (target - result[i].first )/ result[i].second ;

            if(!st.empty() && time <= st.top()){
                continue;
            }
            st.push(time);
        }

        return st.size();
    }
};
