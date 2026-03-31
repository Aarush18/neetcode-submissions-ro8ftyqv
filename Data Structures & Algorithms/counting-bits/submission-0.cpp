class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;

        int cnt = 0;
        for(int i = 0; i <= n ; i++){
            int cnt = 0;
            for(int j = 0 ; j < 32 ; j++){
                if((1 << j) & i ){
                    cnt ++;
                }
            }
            output.push_back(cnt);
        }

        return output;
    }
};
