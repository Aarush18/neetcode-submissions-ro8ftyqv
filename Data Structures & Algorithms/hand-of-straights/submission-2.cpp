class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int , int> mpp;

        if(hand.size() % groupSize != 0){
            return false;
        }

        for(int i = 0 ; i < hand.size(); i++){
            mpp[hand[i]]++;
        }

        sort(hand.begin() , hand.end());

        for(int i = 0 ; i < hand.size(); i++){
            int start = hand[i];

            if(mpp[start] == 0){
                continue;
            }

            for(int j = 0 ; j < groupSize; j++){
                int card = start + j;

                if(mpp[card] == 0 ){
                    return false;
                }
                
                mpp[card]--;
            }
        }

        return true;
    }
};
