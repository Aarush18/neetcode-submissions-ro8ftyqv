class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;

        int curr  = 0 ;

        for(int i = 1 ; i < prices.size() ; i++){
            curr+= prices[i] - prices[i - 1];

            if(curr < 0){
                curr = 0 ;
            }

            maxP = max(maxP , curr);
        }

        return maxP;
    }
};
