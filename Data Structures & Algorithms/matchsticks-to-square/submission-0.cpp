class Solution {
private:
    bool solve(int ind , vector<int>& matchsticks , vector<int>& sides , int target){
        if(ind == matchsticks.size()){
            for(int i = 0 ; i < 4 ; i++){
                if(sides[i] != target){
                    return false;
                }
            }
            return true;
        }


        for(int i = 0 ; i < 4 ; i++){
            if(sides[i] + matchsticks[ind] > target) continue;

            sides[i]+= matchsticks[ind];
            if(solve(ind + 1 , matchsticks , sides , target) == true){
                return true;
            }
            sides[i]-= matchsticks[ind];

            if(sides[i] == 0){
                break;
            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin() , matchsticks.end() , 0);
        if(sum % 4 != 0){
            return false;
        }

        int target = sum / 4;

        sort(matchsticks.rbegin() , matchsticks.rend());
        vector<int> sides(4 , 0);

        return solve(0 , matchsticks , sides , target);
    }
};