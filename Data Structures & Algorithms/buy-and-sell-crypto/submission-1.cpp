class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int maxProf = 0;


        while(r < prices.size()){
            int profit = prices[r] - prices[l];

            maxProf = max(maxProf , profit);

            if(prices[l] > prices[r]){
                l++;
            }else{
                r++;
            }

        }
        return maxProf;
    }
};
