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

                int gasNeededCurrently = cost[j];

                j = (j + 1) % n;

                int gasNeededOnNextStation = gas[j];

                currGas = currGas - gasNeededCurrently + gasNeededOnNextStation;

            }

            if(i == j) return i;
        }

        return -1;
    }
};
