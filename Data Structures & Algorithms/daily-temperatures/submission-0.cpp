class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st; // index tracking
        vector<int> output(n, 0);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int x = st.top();
                st.pop();
                output[x] = i - x;
            }
            st.push(i);
        }
        return output;
    }
};
