class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        bool a = false ;
        bool b = false;
        bool c = false;

        for(auto triplet : triplets){
            
            bool trash = false;

            for(int i = 0 ; i < 3; i++){
                if(triplet[i] > target[i]){
                    trash = true;
                    break;
                }
            }
            if(trash == true){
                continue;
            }

            if(triplet[0] == target[0]) a = true;

            if(triplet[1] == target[1]) b = true;

            if(triplet[2] == target[2]) c = true;

        }

        return a && b && c;
    }
};
