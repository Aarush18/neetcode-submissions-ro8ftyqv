class Solution {
private:
    int capShip(int capacity , vector<int>& weights){

        auto temp = capacity;
        int days = 1;

        for(int i = 0 ; i < weights.size(); i++){
            if(capacity >= weights[i]){
                capacity -= weights[i];
            }else{
                days++;
                capacity = temp - weights[i];
            }
        }

        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long maxi = *max_element(weights.begin() , weights.end());

        long long l = maxi ;
        long long sum = accumulate(weights.begin() , weights.end() , 0);

        long long r = sum;
        
        long long ans = r;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(capShip(mid , weights) <= days){
                ans = mid ;
                r = mid - 1;
            }else{
                l = mid + 1 ;
            }
        }

        return ans;
    }
};