class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;

        vector<int> nse(n);

        for(int i = n-1 ; i >= 0 ; i--){
            while( !st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) {
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> pse(n);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }

        int maxi = -1e9;
        
        for(int i = 0 ; i < n ; i++){
            maxi = max (maxi , heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};
