class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // Line sweep the goat . THE OG (GREEDY)
        vector<int> diff(1001 , 0);

        for(auto& it : trips){
            diff[it[1]] += it[0];
            diff[it[2]] -= it[0];
        }

        int sum = 0 ;

        for(int i = 0 ; i < 1001 ; i++){
            sum+= diff[i];
            if(sum > capacity){
                return false;
            }
        }

        return true;
    }
};