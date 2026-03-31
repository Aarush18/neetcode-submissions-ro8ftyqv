class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0 ; int leftMax = 0;

        for(char ch : s){
            if(ch == '('){
                leftMin++;
                leftMax++;
            }else if(ch == ')'){
                leftMin --;
                leftMax --;
            }else{
                leftMin --;
                leftMax ++;
            }
            if(leftMin < 0){
                leftMin = 0 ;
            }
            if(leftMax < 0){
                return false;
            }
        }
        return leftMin == 0;
    }
};
