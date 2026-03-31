class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        stack<int> st;

        for(int i =0 ; i < asteroids.size(); i++){
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                if(st.top() < abs(asteroids[i])){
                    st.pop();
                }
                else if(st.top() == abs(asteroids[i])){
                    destroyed = true;
                    st.pop();
                    break;
                }else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push(asteroids[i]);
            }
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin() , res.end());
        return res;
    }
};