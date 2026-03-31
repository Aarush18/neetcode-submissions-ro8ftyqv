class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0 ;

        int r = people.size() - 1;

        sort(people.begin() , people.end());

        int boat = 0;

        while(l <= r){
            if(l == r){
                boat++;
                break;
            }

            if(people[l] + people[r] <= limit){
                boat++;
                l++;
                r--;
            }else{
                r--;
                boat++;
            }
        }
        return boat;
    }
};