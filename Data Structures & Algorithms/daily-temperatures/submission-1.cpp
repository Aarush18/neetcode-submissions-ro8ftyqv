class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // index only
        int n = temperatures.size();
        vector<int> output( n , 0);

        for(int i= 0 ; i < n ; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                auto x = st.top();
                st.pop();
                output[x] = i - x;
            }
            st.push(i);
        }
        return output;
    }
};
