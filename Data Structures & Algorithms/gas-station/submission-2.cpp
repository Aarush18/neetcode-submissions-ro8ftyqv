class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        for(int i = 0 ; i < n ; i++){

            if(gas[i] < cost[i]){
                continue;
            }
            int j = (i + 1) % n;

            int currGas = gas[i] - cost[i] + gas[j];

            while(j != i){
                if(currGas < cost[j]){
                    break;
                }

                int costFromThisStation = cost[j];

                j = (j + 1) % n;

                int gasAddedOnTheNextStation = gas[j];

                currGas = currGas - costFromThisStation + gasAddedOnTheNextStation;

            }

            if(i == j) return i;
        }

        return -1;
    }
};
