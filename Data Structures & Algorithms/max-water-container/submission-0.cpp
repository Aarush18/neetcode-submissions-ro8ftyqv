class Solution {
public:
    int maxArea(vector<int>& heights) {
       int n = heights.size();
       int l = 0;
       int r = n-1; 

       int maxCap = 0;

       while( l < r){
         int cap = min(heights[l] , heights[r]) * (r - l);
         maxCap = max( maxCap , cap);

         if(heights[l] < heights[r]){
            l++;
         }else{
            r--;
         }

       }
       return maxCap;
    }
};
