class Solution {
private:
    int calcTime(int rate , vector<int>& piles){
        int sum = 0 ;
        for(int i = 0 ; i < piles.size(); i++){
            sum += ceil((double)piles[i] / rate);
        }

        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = 0;
        
        for(int i = 0 ; i < piles.size() ; i++){
            maxi = max(maxi , piles[i]);
        }


        int l = 1 ;
        int r = maxi ;
        int ans = r ;

        while( l <= r) {
            int mid = l + (r-l)/2;

            if(calcTime(mid , piles) <= h){
                ans = mid ;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
